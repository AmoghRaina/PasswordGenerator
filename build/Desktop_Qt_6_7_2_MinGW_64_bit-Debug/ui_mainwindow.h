/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QComboBox *comboBox;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QPushButton *pushButton_3;
    QLabel *label_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 250);
        QFont font;
        font.setFamilies({QString::fromUtf8("Tahoma")});
        font.setPointSize(9);
        font.setBold(false);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 20, 20);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 10, 480, 230));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);"));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(340, 30, 141, 26));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Tahoma")});
        checkBox->setFont(font1);
        checkBox->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 200, 161, 29));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Tahoma")});
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        pushButton->setFont(font2);
        pushButton->setCheckable(false);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 131, 20));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Tahoma")});
        font3.setBold(false);
        font3.setUnderline(true);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(450, 210, 41, 29));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Tahoma")});
        font4.setBold(false);
        pushButton_2->setFont(font4);
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(340, 60, 151, 26));
        checkBox_2->setFont(font1);
        checkBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);"));
        checkBox_3 = new QCheckBox(centralwidget);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(340, 90, 151, 26));
        checkBox_3->setFont(font1);
        checkBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);"));
        checkBox_4 = new QCheckBox(centralwidget);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setGeometry(QRect(340, 120, 151, 26));
        checkBox_4->setFont(font1);
        checkBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);\n"
""));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 60, 311, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Tahoma")});
        font5.setBold(false);
        font5.setUnderline(false);
        label_3->setFont(font5);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 20, 20);"));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(170, 100, 151, 20));
        horizontalSlider->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);\n"
""));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 100, 111, 20));
        label_4->setFont(font5);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);"));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(170, 17, 161, 28));
        checkBox_5 = new QCheckBox(centralwidget);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setGeometry(QRect(20, 130, 121, 26));
        checkBox_5->setFont(font1);
        checkBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);"));
        checkBox_6 = new QCheckBox(centralwidget);
        checkBox_6->setObjectName("checkBox_6");
        checkBox_6->setGeometry(QRect(150, 130, 111, 26));
        checkBox_6->setFont(font1);
        checkBox_6->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 160, 121, 29));
        pushButton_3->setFont(font4);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(130, 100, 21, 20));
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        checkBox->raise();
        pushButton->raise();
        label->raise();
        pushButton_2->raise();
        checkBox_2->raise();
        checkBox_3->raise();
        checkBox_4->raise();
        label_3->raise();
        label_4->raise();
        horizontalSlider->raise();
        comboBox->raise();
        checkBox_5->raise();
        checkBox_6->raise();
        pushButton_3->raise();
        label_5->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QString());
        checkBox->setText(QCoreApplication::translate("MainWindow", "Include Numbers", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Generate Password", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Password Generator", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Include Small Letters", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Include Special Chars", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "Include Big Letters", nullptr));
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Password Length", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "Easy To Read", nullptr));
        checkBox_6->setText(QCoreApplication::translate("MainWindow", "Easy To Say", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Copy Password", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
