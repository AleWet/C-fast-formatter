#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QtCharts>
#include <QComboBox>
#include <map>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void on_pushButton_clicked();
    void initializeGridFromFile();
    void copySelectedCells();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void updateDropdowns();
    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();
    void setTimeDefault();

private:
    Ui::MainWindow *ui;
    QComboBox *dropdown1;
    QComboBox *dropdown2;
    std::map<QString, int> mapNameToIndex;
    void setupDropdowns();
    void createGraph(const QString& firstVariable, const std::vector<QString>& secondVariables);
    void openConfigDialog(QChart* chart, std::vector<QLineSeries*>* series, int graphNumberToBePassedCuzStrangeError);
    QStringList getAvailableVariables();
    QList<QMainWindow*> graphWindows;
    void cleanupGraphWindows();
    void closeEvent(QCloseEvent *event) override;
    QMap<QString, QValueAxis*> yAxes;
    int axisCount = 0;
    QStringList axisColors = {
        "#FF0000", "#00FF00", "#0000FF", "#FFA500",
        "#800080", "#008080", "#FF00FF", "#000080"
    };
};
#endif
