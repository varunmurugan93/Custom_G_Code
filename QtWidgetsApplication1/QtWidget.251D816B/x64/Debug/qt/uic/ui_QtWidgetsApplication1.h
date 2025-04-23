/********************************************************************************
** Form generated from reading UI file 'QtWidgetsApplication1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPLICATION1_H
#define UI_QTWIDGETSAPPLICATION1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsApplication1Class
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_Gcode;
    QLineEdit *lineEdit_H;
    QLabel *label_H;
    QLabel *label_Title;
    QLabel *label_W;
    QLineEdit *lineEdit_W;
    QLabel *label_F;
    QLineEdit *lineEdit_F;
    QLabel *label_N;
    QLineEdit *lineEdit_N;
    QRadioButton *radioButton_normal;
    QRadioButton *radioButton_helix;
    QPushButton *pushButton_Import;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWidgetsApplication1Class)
    {
        if (QtWidgetsApplication1Class->objectName().isEmpty())
            QtWidgetsApplication1Class->setObjectName(QString::fromUtf8("QtWidgetsApplication1Class"));
        QtWidgetsApplication1Class->resize(1119, 689);
        centralWidget = new QWidget(QtWidgetsApplication1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_Gcode = new QPushButton(centralWidget);
        pushButton_Gcode->setObjectName(QString::fromUtf8("pushButton_Gcode"));
        pushButton_Gcode->setGeometry(QRect(700, 400, 301, 61));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_Gcode->sizePolicy().hasHeightForWidth());
        pushButton_Gcode->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(19);
        pushButton_Gcode->setFont(font);
        lineEdit_H = new QLineEdit(centralWidget);
        lineEdit_H->setObjectName(QString::fromUtf8("lineEdit_H"));
        lineEdit_H->setGeometry(QRect(130, 160, 181, 41));
        sizePolicy.setHeightForWidth(lineEdit_H->sizePolicy().hasHeightForWidth());
        lineEdit_H->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(20);
        lineEdit_H->setFont(font1);
        label_H = new QLabel(centralWidget);
        label_H->setObjectName(QString::fromUtf8("label_H"));
        label_H->setGeometry(QRect(130, 110, 201, 41));
        label_H->setFont(font1);
        label_Title = new QLabel(centralWidget);
        label_Title->setObjectName(QString::fromUtf8("label_Title"));
        label_Title->setGeometry(QRect(450, 20, 331, 51));
        label_Title->setFont(font1);
        label_W = new QLabel(centralWidget);
        label_W->setObjectName(QString::fromUtf8("label_W"));
        label_W->setGeometry(QRect(130, 240, 191, 41));
        label_W->setFont(font1);
        lineEdit_W = new QLineEdit(centralWidget);
        lineEdit_W->setObjectName(QString::fromUtf8("lineEdit_W"));
        lineEdit_W->setGeometry(QRect(130, 290, 181, 41));
        sizePolicy.setHeightForWidth(lineEdit_W->sizePolicy().hasHeightForWidth());
        lineEdit_W->setSizePolicy(sizePolicy);
        lineEdit_W->setFont(font1);
        label_F = new QLabel(centralWidget);
        label_F->setObjectName(QString::fromUtf8("label_F"));
        label_F->setGeometry(QRect(130, 380, 191, 41));
        label_F->setFont(font1);
        lineEdit_F = new QLineEdit(centralWidget);
        lineEdit_F->setObjectName(QString::fromUtf8("lineEdit_F"));
        lineEdit_F->setGeometry(QRect(130, 420, 181, 41));
        sizePolicy.setHeightForWidth(lineEdit_F->sizePolicy().hasHeightForWidth());
        lineEdit_F->setSizePolicy(sizePolicy);
        lineEdit_F->setFont(font1);
        label_N = new QLabel(centralWidget);
        label_N->setObjectName(QString::fromUtf8("label_N"));
        label_N->setGeometry(QRect(130, 510, 191, 41));
        label_N->setFont(font1);
        lineEdit_N = new QLineEdit(centralWidget);
        lineEdit_N->setObjectName(QString::fromUtf8("lineEdit_N"));
        lineEdit_N->setGeometry(QRect(130, 560, 181, 41));
        sizePolicy.setHeightForWidth(lineEdit_N->sizePolicy().hasHeightForWidth());
        lineEdit_N->setSizePolicy(sizePolicy);
        lineEdit_N->setFont(font1);
        radioButton_normal = new QRadioButton(centralWidget);
        radioButton_normal->setObjectName(QString::fromUtf8("radioButton_normal"));
        radioButton_normal->setGeometry(QRect(640, 160, 151, 28));
        QFont font2;
        font2.setPointSize(18);
        radioButton_normal->setFont(font2);
        radioButton_helix = new QRadioButton(centralWidget);
        radioButton_helix->setObjectName(QString::fromUtf8("radioButton_helix"));
        radioButton_helix->setGeometry(QRect(850, 160, 161, 28));
        radioButton_helix->setFont(font2);
        pushButton_Import = new QPushButton(centralWidget);
        pushButton_Import->setObjectName(QString::fromUtf8("pushButton_Import"));
        pushButton_Import->setGeometry(QRect(700, 270, 301, 61));
        sizePolicy.setHeightForWidth(pushButton_Import->sizePolicy().hasHeightForWidth());
        pushButton_Import->setSizePolicy(sizePolicy);
        pushButton_Import->setFont(font);
        QtWidgetsApplication1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtWidgetsApplication1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1119, 21));
        QtWidgetsApplication1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtWidgetsApplication1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtWidgetsApplication1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtWidgetsApplication1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtWidgetsApplication1Class->setStatusBar(statusBar);

        retranslateUi(QtWidgetsApplication1Class);

        QMetaObject::connectSlotsByName(QtWidgetsApplication1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsApplication1Class)
    {
        QtWidgetsApplication1Class->setWindowTitle(QApplication::translate("QtWidgetsApplication1Class", "QtWidgetsApplication1", nullptr));
        pushButton_Gcode->setText(QApplication::translate("QtWidgetsApplication1Class", "Write G-code", nullptr));
        label_H->setText(QApplication::translate("QtWidgetsApplication1Class", "Height (H)", nullptr));
        label_Title->setText(QApplication::translate("QtWidgetsApplication1Class", "G-Code Generator", nullptr));
        label_W->setText(QApplication::translate("QtWidgetsApplication1Class", "Width (W)", nullptr));
        label_F->setText(QApplication::translate("QtWidgetsApplication1Class", "Speed (F)", nullptr));
        label_N->setText(QApplication::translate("QtWidgetsApplication1Class", "Layers (N)", nullptr));
        radioButton_normal->setText(QApplication::translate("QtWidgetsApplication1Class", "Normal", nullptr));
        radioButton_helix->setText(QApplication::translate("QtWidgetsApplication1Class", "Helix", nullptr));
        pushButton_Import->setText(QApplication::translate("QtWidgetsApplication1Class", "Import Path", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplication1Class: public Ui_QtWidgetsApplication1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION1_H
