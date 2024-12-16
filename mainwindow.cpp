#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <random>
#include <QClipboard>
#include <QTimer>
#include <cmath>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //styling the ui
    style();
    //filling my comboBox below
    ui->comboBox->addItem("Hardware Randomness");
    ui->comboBox->addItem("Time Randomness");
    //setting range of the slider
    ui->horizontalSlider->setRange(0, 35);
    ui->horizontalSlider->setValue(13);

    //setting the slider value to the label
    ui->label_5->setText(QString::number(ui->horizontalSlider->value()));
    // setting the check box state to true by default
    ui->checkBox->setChecked(true);
    ui->checkBox_2->setChecked(true);
    ui->checkBox_3->setChecked(true);
    ui->checkBox_4->setChecked(true);
    connect(ui->checkBox,&QCheckBox::stateChanged,this,&MainWindow::generatePassword);
    connect(ui->horizontalSlider,&QSlider::valueChanged,this,&MainWindow::sliderValue);
    connect(ui->checkBox_5,&QCheckBox::stateChanged,this,&MainWindow::checkbox);
    connect(ui->checkBox_6,&QCheckBox::stateChanged,this,&MainWindow::checkbox2);
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::logic1);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&MainWindow::copy);
    connect(ui->checkBox,&QCheckBox::stateChanged,this,&MainWindow::check);
    connect(ui->checkBox_2,&QCheckBox::stateChanged,this,&MainWindow::check);
    connect(ui->checkBox_3,&QCheckBox::stateChanged,this,&MainWindow::check);
    connect(ui->checkBox_4,&QCheckBox::stateChanged,this,&MainWindow::check);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::generatePassword(int state){
    if (state == Qt::Checked) {

    } else {

    }
}
void MainWindow::sliderValue(int val){
    ui->label_5->setText(QString::number(val));
}
void MainWindow::checkbox(){
    if(ui->checkBox_5->isChecked()){
        ui->checkBox_3->setChecked(false);
        ui->checkBox_3->setEnabled(false);  // disabling the checkbox
        symbolst = false;

    }
    else if(!ui->checkBox_5->isChecked()){
    ui->checkBox_3->setEnabled(true);
        ui->checkBox_3->setChecked(true);
        symbolst = true;
    }


}
void MainWindow::checkbox2(){
    if(ui->checkBox_6->isChecked()){
        ui->checkBox_3->setChecked(false);
        ui->checkBox->setChecked(false);
        ui->checkBox_3->setEnabled(false);
        ui->checkBox->setEnabled(false);
        numt = false;


    }
    if(!ui->checkBox_6->isChecked()){
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_3->setChecked(true);
        ui->checkBox->setEnabled(true);
        ui->checkBox->setChecked(true);
        numt = true;

    }
}
void MainWindow::logic1(){

    slval = ui->horizontalSlider->value();
    ui->label_3->clear();
    generatedPassword.clear();

     // random distribution logic
    random_device device;
    mt19937 generate;
    if(ui->comboBox->currentIndex()==0){

        generate.seed(device());
    }
    else if (ui->comboBox->currentIndex()==1){
        generate.seed(time(0));
    }
    uniform_int_distribution<> numericals(0,9);
    uniform_int_distribution<> smallAlpha('a','z');
    uniform_int_distribution<> bigAlpha('A', 'Z');
    vector<char> symbols = {'!', '@', '#', '$', '%', '^', '&', '*',')','(','~','`',';',':'};
    uniform_int_distribution<> symbolpick(0, symbols.size() - 1);

    // Dynamic valid types list
    vector<int> validTypes;
    if (numt) validTypes.push_back(0);      // Type 0: Numbers
    if (smallAlp) validTypes.push_back(1);  // Type 1: Small Alphabets
    if (symbolst) validTypes.push_back(2);  // Type 2: Symbols
    if (bigAlp) validTypes.push_back(3);    // Type 3: Big Alphabets

    if (validTypes.empty()) {
        QMessageBox::warning(this, "Warning", "No character types selected. Please enable at least one option.");
        return;
    }

    uniform_int_distribution<> randomgen(0, validTypes.size() - 1);

    // Password generation logic
    for (int n = 0; n < slval; n++) {
        int randomType = validTypes[randomgen(generate)];

        if (randomType == 0) {  // Numbers
            int number = numericals(generate);
            generatedPassword += QString::number(number);
        } else if (randomType == 1) {  // Small Alphabets
            char small_alpha = smallAlpha(generate);
            generatedPassword += QString(small_alpha);
        } else if (randomType == 2) {  // Symbols
            char specialchar = symbols[symbolpick(generate)];
            generatedPassword += QString(specialchar);
        } else if (randomType == 3) {  // Big Alphabets
            char big_alpha = bigAlpha(generate);
            generatedPassword += QString(big_alpha);
        }
    }

    ui->label_3->setText(generatedPassword);


    if (slval < 4) {
        QMessageBox::warning(this, "Warning", "The slider value is too low! Please increase it.");
    } else if (slval > 20) {
        ui->label_7->setStyleSheet("background-color: rgb(27, 255, 0);");
    } else if (slval >= 11) {
        ui->label_7->setStyleSheet("background-color: green;");
    } else if (slval < 9) {
        ui->label_7->setStyleSheet("background-color: yellow;");
    } else if (slval < 7) {
        ui->label_7->setStyleSheet("background-color: red;");
    }

    timee();
}




void MainWindow::check(){
    //checkboxes bool value
    if(!ui->checkBox->isChecked()){
        numt =false;
    }
    else {
        numt =true;
    }
    if(!ui->checkBox_2->isChecked()){
        smallAlp =false;
    }
    else {
        smallAlp =true;
    }
    if(!ui->checkBox_3->isChecked()){
        symbolst =false;
    }
    else {
        symbolst =true;
    }
    if(!ui->checkBox_4->isChecked()){
        bigAlp =false;
    }
    else {
        bigAlp =true;
    }

}

void MainWindow::copy(){
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(generatedPassword);
    ui->label_8->setText("Copied");
    QTimer::singleShot(2000, this, [this]() {
        ui->label_8->clear(); // Clear the label text
    });
}
void MainWindow::timee() {
    int totalChars = 0;

    // Counting available character types
    if (numt) totalChars += 10;
    if (smallAlp) totalChars += 26;
    if (bigAlp) totalChars += 26;
    if (symbolst) totalChars += 14;

    if (totalChars == 0) {
        ui->label_10->setText("No character types selected.");
        return;
    }

    // Calculate combinations
    double combinations = pow(totalChars, slval);
    double crackingSpeed = 1e9;
    double crackingTimeSeconds = combinations / crackingSpeed;

    QString timeString;

    // Format very large numbers using scientific notation
    auto formatLargeNumber = [](double number) {
        int exponent = log10(number);
        double base = number / pow(10, exponent);
        return QString::number(base, 'f', 2) + " × 10^" + QString::number(exponent);
    };

    if (crackingTimeSeconds < 60) {
        if (crackingTimeSeconds > 1e6) {
            timeString = formatLargeNumber(crackingTimeSeconds) + " seconds";
        } else {
            timeString = QString::number(crackingTimeSeconds, 'f', 2) + " seconds";
        }
    } else if (crackingTimeSeconds < 3600) {
        double minutes = crackingTimeSeconds / 60;
        if (minutes > 1e6) {
            timeString = formatLargeNumber(minutes) + " minutes";
        } else {
            timeString = QString::number(minutes, 'f', 2) + " minutes";
        }
    } else if (crackingTimeSeconds < 86400) {
        double hours = crackingTimeSeconds / 3600;
        if (hours > 1e6) {
            timeString = formatLargeNumber(hours) + " hours";
        } else {
            timeString = QString::number(hours, 'f', 2) + " hours";
        }
    } else {
        double days = crackingTimeSeconds / 86400;
        if (days > 1e6) {
            timeString = formatLargeNumber(days) + " days";
        } else {
            timeString = QString::number(days, 'f', 2) + " days";
        }
    }

    ui->label_10->setText(timeString);
}

void MainWindow::style(){
    //coloring

    ui->horizontalSlider->setStyleSheet(
        "QSlider {"
        "    background: rgb(27, 27, 27);"  // bg for the entire slider
        "}"
        "QSlider::groove:horizontal {"
        "    background: rgb(100, 100, 100);"  // Background color for the groove (track)
        "    height: 4px;"
        "}"

        "QSlider::handle:horizontal {"
        "    background: white;"  // White color for the handle
        "    border: 2px solid #d3d3d3;"
        "    width: 10px;"
        "    height: 10px;"
        "    margin-top: -3px;"
        "    margin-bottom: -3px"
        "}"
        "QSlider::sub-page:horizontal {"
        "    background-color: rgb(230, 230, 230);"  // Blue to white gradient for the filled portion
        "}"

        );

    // uncomment the below code for the checkboxes style change (i personally didnt like it so i commented it)



//     QList<QCheckBox*> checkBoxes = { ui->checkBox, ui->checkBox_2, ui->checkBox_3, ui->checkBox_4 };
// for (QCheckBox* checkBox : checkBoxes) {
// checkBox->setStyleSheet(
//         "QCheckBox {"
//         "    background-color: rgb(27, 27, 27);"  // Background color for the entire checkbox
//         "}"
//         "QCheckBox::indicator:checked {"
//         "    background-color: #1E90FF;"  // Color when checked
//         "    border: 1px solid rgb(100, 100, 100);"  // Border when checked

//         "}"


//         "QCheckBox::indicator:unchecked {"
//         "    background-color: rgb(27, 27, 27);"  // Background color when unchecked
//         "    border: 1px solid rgb(100, 100, 100);"  // Border for the unchecked state
//         "}"


//         );
// }

}
