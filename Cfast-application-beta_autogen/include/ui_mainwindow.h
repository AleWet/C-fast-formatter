/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QFrame *fr1;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_3;
    QPlainTextEdit *plainTextEdit_2;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_4;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_4;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QTableWidget *tableWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(891, 596);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(891, 596));
        centralwidget->setAutoFillBackground(false);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::NoFrame);
        frame->setFrameShadow(QFrame::Shadow::Plain);
        frame->setLineWidth(0);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName("gridLayout_3");
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(200, 30));
        frame_2->setMaximumSize(QSize(16777215, 35));
        frame_2->setFrameShape(QFrame::Shape::NoFrame);
        frame_2->setFrameShadow(QFrame::Shadow::Plain);
        frame_2->setLineWidth(0);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(200, 35));
        pushButton->setMaximumSize(QSize(300, 16777215));

        horizontalLayout->addWidget(pushButton);

        plainTextEdit = new QPlainTextEdit(frame_2);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setMinimumSize(QSize(100, 30));
        plainTextEdit->setMaximumSize(QSize(16777215, 40));
        plainTextEdit->setFrameShape(QFrame::Shape::NoFrame);
        plainTextEdit->setFrameShadow(QFrame::Shadow::Plain);
        plainTextEdit->setLineWidth(0);
        plainTextEdit->setBackgroundVisible(false);
        plainTextEdit->setCenterOnScroll(false);

        horizontalLayout->addWidget(plainTextEdit);


        gridLayout_3->addWidget(frame_2, 1, 0, 1, 1);

        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea->setFrameShadow(QFrame::Shadow::Plain);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 865, 495));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        fr1 = new QFrame(scrollAreaWidgetContents);
        fr1->setObjectName("fr1");
        fr1->setMinimumSize(QSize(600, 400));
        fr1->setMaximumSize(QSize(600, 600));
        fr1->setFrameShape(QFrame::Shape::NoFrame);
        fr1->setFrameShadow(QFrame::Shadow::Plain);
        fr1->setLineWidth(0);
        verticalLayout_2 = new QVBoxLayout(fr1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        frame_4 = new QFrame(fr1);
        frame_4->setObjectName("frame_4");
        frame_4->setMinimumSize(QSize(0, 35));
        frame_4->setMaximumSize(QSize(16777215, 50));
        frame_4->setFrameShape(QFrame::Shape::NoFrame);
        frame_4->setFrameShadow(QFrame::Shadow::Plain);
        frame_4->setLineWidth(0);
        horizontalLayout_2 = new QHBoxLayout(frame_4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(200, 35));
        pushButton_3->setMaximumSize(QSize(300, 35));

        horizontalLayout_2->addWidget(pushButton_3);

        plainTextEdit_2 = new QPlainTextEdit(frame_4);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setMaximumSize(QSize(16777215, 35));
        plainTextEdit_2->setFrameShape(QFrame::Shape::NoFrame);
        plainTextEdit_2->setFrameShadow(QFrame::Shadow::Plain);
        plainTextEdit_2->setLineWidth(0);

        horizontalLayout_2->addWidget(plainTextEdit_2);


        verticalLayout_2->addWidget(frame_4);

        frame_5 = new QFrame(fr1);
        frame_5->setObjectName("frame_5");
        frame_5->setMinimumSize(QSize(0, 40));
        frame_5->setMaximumSize(QSize(16777215, 50));
        frame_5->setFrameShape(QFrame::Shape::NoFrame);
        frame_5->setFrameShadow(QFrame::Shadow::Plain);
        frame_5->setLineWidth(0);
        horizontalLayout_3 = new QHBoxLayout(frame_5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(5, 5, 5, 5);
        pushButton_4 = new QPushButton(frame_5);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(200, 35));
        pushButton_4->setMaximumSize(QSize(300, 35));

        horizontalLayout_3->addWidget(pushButton_4);

        plainTextEdit_3 = new QPlainTextEdit(frame_5);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setMinimumSize(QSize(0, 35));
        plainTextEdit_3->setMaximumSize(QSize(16777215, 35));
        plainTextEdit_3->setFrameShape(QFrame::Shape::NoFrame);
        plainTextEdit_3->setFrameShadow(QFrame::Shadow::Plain);
        plainTextEdit_3->setLineWidth(0);

        horizontalLayout_3->addWidget(plainTextEdit_3);


        verticalLayout_2->addWidget(frame_5);

        plainTextEdit_4 = new QPlainTextEdit(fr1);
        plainTextEdit_4->setObjectName("plainTextEdit_4");
        plainTextEdit_4->setMinimumSize(QSize(600, 0));
        plainTextEdit_4->setMaximumSize(QSize(600, 50));
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(true);
        font.setKerning(true);
        plainTextEdit_4->setFont(font);
        plainTextEdit_4->setFrameShape(QFrame::Shape::NoFrame);
        plainTextEdit_4->setFrameShadow(QFrame::Shadow::Plain);
        plainTextEdit_4->setLineWidth(0);

        verticalLayout_2->addWidget(plainTextEdit_4);

        frame_6 = new QFrame(fr1);
        frame_6->setObjectName("frame_6");
        frame_6->setMinimumSize(QSize(0, 40));
        frame_6->setMaximumSize(QSize(16777215, 50));
        frame_6->setFrameShape(QFrame::Shape::NoFrame);
        frame_6->setFrameShadow(QFrame::Shadow::Plain);
        frame_6->setLineWidth(0);
        horizontalLayout_4 = new QHBoxLayout(frame_6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(5, 5, 5, 5);
        pushButton_5 = new QPushButton(frame_6);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(0, 35));
        pushButton_5->setMaximumSize(QSize(300, 35));

        horizontalLayout_4->addWidget(pushButton_5);

        pushButton_2 = new QPushButton(frame_6);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 35));
        pushButton_2->setMaximumSize(QSize(300, 35));

        horizontalLayout_4->addWidget(pushButton_2);


        verticalLayout_2->addWidget(frame_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(fr1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(tab_2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setFrameShape(QFrame::Shape::NoFrame);
        tableWidget->setFrameShadow(QFrame::Shadow::Plain);
        tableWidget->setLineWidth(0);

        gridLayout_4->addWidget(tableWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "add file", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "read file name will be displayed here", nullptr));
        plainTextEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "read file name will be displayed here", nullptr));
        pushButton_3->setText(QString());
        plainTextEdit_2->setPlainText(QCoreApplication::translate("MainWindow", "select variable that will be displayed as the X-axis", nullptr));
        pushButton_4->setText(QString());
        plainTextEdit_3->setPlainText(QCoreApplication::translate("MainWindow", "select variable that will be displayed as the Y-axis", nullptr));
        plainTextEdit_4->setPlainText(QCoreApplication::translate("MainWindow", "you can always add more variables to be displayed on the Y-axis after the graph is created", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "use time as default (x-axis)", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "create new graph", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
