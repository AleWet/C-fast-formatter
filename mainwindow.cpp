#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <QStandardPaths>
#include <QFile>
#include <QTextStream>
#include <QClipboard>
#include <QApplication>
#include <QVBoxLayout>
#include <QRegularExpression>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QColorDialog>
#include <QInputDialog>
#include <memory>
#include <QMessageBox>

bool isFileOpened = false;
bool isTimeDefault = false;
QString fileName = "";
QString prevFileDirectory = "C://";
int graphNumber = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit_2->setReadOnly(true);
    ui->plainTextEdit_3->setReadOnly(true);
    ui->plainTextEdit_4->setReadOnly(true);
    QTextCursor cursor = ui->plainTextEdit_4->textCursor();
    QTextBlockFormat textBlockFormat = cursor.blockFormat();
    //textBlockFormat.setAlignment(Qt::AlignRight);

    setupDropdowns();
}

MainWindow::~MainWindow()
{
    // Disconnect all signals/slots
    disconnect();
    mapNameToIndex.clear();

    cleanupGraphWindows();
    delete ui;
}

void MainWindow::setupDropdowns()
{
    dropdown1 = new QComboBox(this);
    dropdown2 = new QComboBox(this);

    dropdown1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    dropdown2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    dropdown1->setMinimumHeight(ui->pushButton_3->height());
    dropdown2->setMinimumHeight(ui->pushButton_4->height());

    QVBoxLayout* layout3 = new QVBoxLayout(ui->pushButton_3);
    layout3->setContentsMargins(0, 0, 0, 0);
    layout3->addWidget(dropdown1);
    ui->pushButton_3->setLayout(layout3);

    QVBoxLayout* layout4 = new QVBoxLayout(ui->pushButton_4);
    layout4->setContentsMargins(0, 0, 0, 0);
    layout4->addWidget(dropdown2);
    ui->pushButton_4->setLayout(layout4);

    ui->pushButton_3->setFlat(true);
    ui->pushButton_4->setFlat(true);

    connect(dropdown1, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_pushButton_3_clicked);
    connect(dropdown2, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_pushButton_4_clicked);

    QString styleSheet = "QComboBox { padding: 5px; }";
    dropdown1->setStyleSheet(styleSheet);
    dropdown2->setStyleSheet(styleSheet);
}

void MainWindow::setTimeDefault() {
    if (isFileOpened) {
        auto timeIterator = mapNameToIndex.find("Time Simulation Time  (s)");

        if (timeIterator == mapNameToIndex.end()) {
            QMessageBox::critical(this, "Error", "No time variable found inside the input file");
            return;
        }

        qInfo() << timeIterator->first;

        int index = std::distance(mapNameToIndex.begin(), timeIterator);
        if (index >= 0 && index < dropdown1->count()) {
            dropdown1->setCurrentIndex(index);
        } else {
            QMessageBox::critical(this, "Error", "Invalid index for time variable");
        }
    }
    else {
        QMessageBox::critical(this, "Error", "Open a file first");
        return;
    }
}

void MainWindow::updateDropdowns()
{
    dropdown1->clear();
    dropdown2->clear();

    for (const auto& pair : mapNameToIndex) {
        dropdown1->addItem(pair.first);
        dropdown2->addItem(pair.first);
    }
    if (isTimeDefault) setTimeDefault();
}

void MainWindow::initializeGridFromFile()
{
    qDebug() << "Entering initializeGridFromFile()";
    QFile file(fileName);
    QFile* ptFile = &file;

    if (!ptFile->exists()) {
        qCritical() << "File does not exist:" << fileName;
        QMessageBox::critical(this, "Error", "File does not exist.");
        return;
    }

    if (!ptFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Unable to open file:" << fileName << "Error:" << ptFile->errorString();
        QMessageBox::critical(this, "Error", "Unable to open file: " + ptFile->errorString());
        return;
    }

    QTableWidget* table = ui->tableWidget;

    table->setRowCount(0);
    table->setColumnCount(0);
    table->setEditTriggers(QAbstractItemView::DoubleClicked);

    QTextStream in(ptFile);
    int maxColumns = 0;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',', Qt::SkipEmptyParts);
        maxColumns = qMax(maxColumns, fields.size());
    }

    qDebug() << "Maximum columns found:" << maxColumns;

    table->setColumnCount(maxColumns);
    ptFile->seek(0);

    try {
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(',', Qt::SkipEmptyParts);

            int row = table->rowCount();
            table->insertRow(row);

            for (int column = 0; column < fields.size(); ++column) {
                QTableWidgetItem *item = new QTableWidgetItem(fields[column].trimmed());
                table->setItem(row, column, item);
            }
        }

        qDebug() << "Table populated with" << table->rowCount() << "rows";

        if (table->rowCount() >= 4) {
            for (int i = 0; i < table->columnCount(); i++) {
                QTableWidgetItem* header = table->item(0, i);
                QTableWidgetItem* varName = table->item(1, i);
                QTableWidgetItem* measureUnit = table->item(3, i);

                if (header && varName && measureUnit) {
                    QString headerString = header->data(Qt::DisplayRole).toString();
                    QString varNameString = varName->data(Qt::DisplayRole).toString();
                    QString measureUnitString = measureUnit->data(Qt::DisplayRole).toString();

                    QString finalString = headerString + " " + varNameString + "  (" + measureUnitString + ")";
                    mapNameToIndex[finalString] = i;
                } else {
                    qWarning() << "Null item found at column" << i;
                }
            }
        } else {
            qWarning() << "Not enough rows to read headers";
        }

        qDebug() << "mapNameToIndex populated with" << mapNameToIndex.size() << "entries";

        table->resizeColumnsToContents();

        ptFile->close();

        updateDropdowns();

        qDebug() << "initializeGridFromFile() completed successfully";
    } catch (const std::exception& e) {
        qCritical() << "Exception caught in initializeGridFromFile():" << e.what();
        QMessageBox::critical(this, "Error", "An error occurred while processing the file: " + QString(e.what()));
    } catch (...) {
        qCritical() << "Unknown exception caught in initializeGridFromFile()";
        QMessageBox::critical(this, "Error", "An unknown error occurred while processing the file.");
    }
}

void MainWindow::on_pushButton_clicked()
{
    isFileOpened = true;
    fileName = QFileDialog::getOpenFileName(this, "Open a File", prevFileDirectory);
    prevFileDirectory = fileName;
    ui->plainTextEdit->setPlainText(fileName);
    initializeGridFromFile();
    updateDropdowns();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->matches(QKeySequence::Copy))
    {
        copySelectedCells();
    }
    else
    {
        QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::copySelectedCells()
{
    QTableWidget* table = ui->tableWidget;
    QModelIndexList selectedIndexes = table->selectionModel()->selectedIndexes();

    if (selectedIndexes.isEmpty())
        return;

    std::sort(selectedIndexes.begin(), selectedIndexes.end(),
              [](const QModelIndex &a, const QModelIndex &b) {
                  if (a.row() != b.row())
                      return a.row() < b.row();
                  return a.column() < b.column();
              });

    QString selectedText;
    int currentRow = -1;

    for (const QModelIndex &index : selectedIndexes)
    {
        if (currentRow != -1 && currentRow != index.row())
        {
            selectedText += "\n";
        }
        currentRow = index.row();

        if (index.column() != 0 && index.column() != selectedIndexes.first().column())
        {
            selectedText += "\t";
        }

        QTableWidgetItem *item = table->item(index.row(), index.column());
        if (item)
        {
            selectedText += item->text();
        }
        else
        {
            selectedText += "";
        }
    }

    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(selectedText);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString selectedVariable = dropdown1->currentText();
    qDebug() << "Selected variable for dropdown1:" << selectedVariable;
}

void MainWindow::on_pushButton_4_clicked()
{
    QString selectedVariable = dropdown2->currentText();
    qDebug() << "Selected variable for dropdown2:" << selectedVariable;
}

void MainWindow::createGraph(const QString& firstVariable, const std::vector<QString>& secondVariables) {
    if (!isFileOpened) {
        QMessageBox::critical(this, "Error", "Open a file first");
        return;
    }
    else if (firstVariable.isEmpty() || secondVariables.empty()) {
        QMessageBox errorBox;
        errorBox.setText("select both variables first");
        errorBox.exec();
        return;
    }



    auto chart = std::make_shared<QChart>();
    auto allSeries = std::make_shared<std::vector<QLineSeries*>>();

    QTableWidget* table = ui->tableWidget;

    // Create and set up X axis
    QValueAxis* axisX = new QValueAxis();
    axisX->setTitleText(firstVariable);
    chart->addAxis(axisX, Qt::AlignBottom);

    for (size_t i = 0; i < secondVariables.size(); ++i) {
        const auto& varName = secondVariables[i];
        auto series = new QLineSeries;
        series->setName(varName);

        // Set the color for this series
        QString color = axisColors[i % axisColors.size()];
        series->setColor(QColor(color));

        for (int row = 4; row < table->rowCount(); ++row) {
            QTableWidgetItem* xItem = table->item(row, mapNameToIndex[firstVariable]);
            QTableWidgetItem* yItem = table->item(row, mapNameToIndex[varName]);

            if (xItem && yItem) {
                bool xOk, yOk;
                double x = xItem->text().toDouble(&xOk);
                double y = yItem->text().toDouble(&yOk);

                if (xOk && yOk) {
                    series->append(x, y);
                }
            }
        }

        chart->addSeries(series);
        series->attachAxis(axisX);

        // Create a new Y axis for this series
        QValueAxis* axisY = new QValueAxis();
        axisY->setTitleText(varName);
        axisY->setLinePenColor(series->color());
        axisY->setLabelsColor(series->color());
        axisY->setTitleBrush(QBrush(series->color()));

        // Align Y axes alternately on left and right
        Qt::Alignment alignment = (i % 2 == 0) ? Qt::AlignLeft : Qt::AlignRight;
        chart->addAxis(axisY, alignment);
        series->attachAxis(axisY);

        allSeries->push_back(series);
        yAxes[varName] = axisY;
    }

    chart->setTitle(QString("%1 vs Multiple Variables").arg(firstVariable));

    QChartView *chartView = new QChartView(chart.get());
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow *graphWindow = new QMainWindow(this);
    graphWindows.append(graphWindow);

    QWidget *centralWidget = new QWidget(graphWindow);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QString graphNumberString = QString::number(graphNumber);
    int graphNumberToBePassedCuzStrangeError = graphNumber;
    graphWindow->setWindowTitle("Graph Window (Number: " + graphNumberString + ")");

    QPushButton *configButton = new QPushButton("Configure", centralWidget);
    configButton->setFixedSize(170, 30);
    connect(configButton, &QPushButton::clicked, [this, chart, allSeries, graphNumberToBePassedCuzStrangeError]() {
        openConfigDialog(chart.get(), allSeries.get(), graphNumberToBePassedCuzStrangeError);
    });

    layout->addWidget(configButton);
    layout->addWidget(chartView);

    graphWindow->setCentralWidget(centralWidget);
    graphWindow->resize(800, 600);
    graphWindow->show();

    // Use weak_ptr to avoid circular references
    std::weak_ptr<QChart> weakChart = chart;
    std::weak_ptr<std::vector<QLineSeries*>> weakAllSeries = allSeries;

    connect(graphWindow, &QObject::destroyed, [weakChart, weakAllSeries, this]() {
        if (auto chart = weakChart.lock()) {
            // Clean up axes
            for (auto axis : yAxes) {
                delete axis;
            }
            yAxes.clear();
        }
        if (auto allSeries = weakAllSeries.lock()) {
            for (auto series : *allSeries) {
                delete series;
            }
        }
    });
}

void MainWindow::openConfigDialog(QChart* chart, std::vector<QLineSeries*>* series,int graphNumberToBePassedCuzStrangeError) {
    if (!chart || !series) {
        qWarning() << "Invalid chart or series in openConfigDialog";
        return;
    }

    QString graphNumberString = QString::number(graphNumberToBePassedCuzStrangeError);
    QDialog configDialog(this);
    configDialog.setWindowTitle("Graph Configuration (Graph Number: " + graphNumberString + ")");
    configDialog.resize(600, 400);

    QVBoxLayout *mainLayout = new QVBoxLayout(&configDialog);

    QFormLayout *formLayout = new QFormLayout();
    mainLayout->addLayout(formLayout);

    QLineEdit *titleEdit = new QLineEdit(chart->title(), &configDialog);
    formLayout->addRow("Chart Title:", titleEdit);

    QLineEdit *xAxisEdit = new QLineEdit(chart->axes(Qt::Horizontal).first()->titleText(), &configDialog);
    formLayout->addRow("X-Axis Label:", xAxisEdit);

    QListWidget *variableList = new QListWidget(&configDialog);
    for (const auto& s : *series) {
        variableList->addItem(s->name());
    }
    mainLayout->addWidget(new QLabel("Current Y-Axis Variables:"));
    mainLayout->addWidget(variableList);

    QPushButton *addButton = new QPushButton("Add Variable", &configDialog);
    QPushButton *removeButton = new QPushButton("Remove Variable", &configDialog);
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(removeButton);
    mainLayout->addLayout(buttonLayout);

    QPushButton *okButton = new QPushButton("OK", &configDialog);
    mainLayout->addWidget(okButton);

    connect(addButton, &QPushButton::clicked, [this, series, variableList, chart]() {

        //avoid more than 4 y-axis at the same time
        if (variableList->count() > 5) {
            QMessageBox errorBox;
            QMessageBox::critical(this, "Error", "there can only be at most 6 axis at the same time");
            return;
        }

        QStringList availableVars = getAvailableVariables();
        QString selectedVar = QInputDialog::getItem(this, "Add Variable", "Select a variable to add:", availableVars, 0, false);
        if (!selectedVar.isEmpty() && !series->empty()) {
            auto newSeries = new QLineSeries();
            newSeries->setName(selectedVar);

            // Set color for new series
            QString color = axisColors[series->size() % axisColors.size()];
            newSeries->setColor(QColor(color));

            const auto& firstSeries = series->at(0);
            for (int i = 0; i < firstSeries->count(); ++i) {
                QPointF point = firstSeries->at(i);
                QTableWidgetItem* yItem = ui->tableWidget->item(i + 4, mapNameToIndex[selectedVar]);
                if (yItem) {
                    bool ok;
                    double y = yItem->text().toDouble(&ok);
                    if (ok) {
                        newSeries->append(point.x(), y);
                    }
                }
            }

            chart->addSeries(newSeries);

            // Attach to X axis
            newSeries->attachAxis(chart->axes(Qt::Horizontal).first());

            // Create new Y axis
            QValueAxis* newAxisY = new QValueAxis();
            newAxisY->setTitleText(selectedVar);
            newAxisY->setLinePenColor(newSeries->color());
            newAxisY->setLabelsColor(newSeries->color());
            newAxisY->setTitleBrush(QBrush(newSeries->color()));

            // Align new Y axis
            Qt::Alignment alignment = (series->size() % 2 == 0) ? Qt::AlignLeft : Qt::AlignRight;
            chart->addAxis(newAxisY, alignment);
            newSeries->attachAxis(newAxisY);

            series->push_back(newSeries);
            yAxes[selectedVar] = newAxisY;
            variableList->addItem(selectedVar);
        }
    });

    connect(removeButton, &QPushButton::clicked, [this, series, variableList, chart]() {
        QListWidgetItem *item = variableList->currentItem();
        if (item) {
            QString varName = item->text();
            auto it = std::find_if(series->begin(), series->end(),
                                   [&varName](const QLineSeries* s) { return s->name() == varName; });

            if (it != series->end()) {
                // Remove Y axis
                if (yAxes.contains(varName)) {
                    QValueAxis* axis = yAxes[varName];
                    chart->removeAxis(axis);
                    delete axis;
                    yAxes.remove(varName);
                }

                // Remove series
                chart->removeSeries(*it);
                delete *it;
                series->erase(it);
                delete variableList->takeItem(variableList->row(item));
            }
        }
    });

    connect(okButton, &QPushButton::clicked, [&]() {
        chart->setTitle(titleEdit->text());
        chart->axes(Qt::Horizontal).first()->setTitleText(xAxisEdit->text());
        configDialog.accept();
    });

    configDialog.exec();
}

QStringList MainWindow::getAvailableVariables() {
    QStringList variables;
    for (const auto& pair : mapNameToIndex) {
        variables << pair.first;
    }
    return variables;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString firstVariable = dropdown1->currentText();
    QString secondVariable = dropdown2->currentText();
    std::vector<QString> secondVariables = {secondVariable};
    createGraph(firstVariable, secondVariables);
    graphNumber++;
}

void MainWindow::cleanupGraphWindows()
{
    for(auto window : graphWindows)
    {
        if (window) {
            window->close();
            delete window;
        }
    }
    graphWindows.clear();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    cleanupGraphWindows();
    QMainWindow::closeEvent(event);
}

void MainWindow::on_pushButton_5_clicked()
{
    if (!isTimeDefault) isTimeDefault = true;
    if (isFileOpened) setTimeDefault();
}
