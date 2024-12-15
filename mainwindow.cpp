#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <random>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //styling the ui
    style();
    //filling my comboBox below
    ui->comboBox->addItem("Mersenne Twister Engine");
    ui->comboBox->addItem("Srand Engine");
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


    }
    else if(!ui->checkBox_5->isChecked()){
    ui->checkBox_3->setEnabled(true);
        ui->checkBox_3->setChecked(true);
    }


}
void MainWindow::checkbox2(){
    if(ui->checkBox_6->isChecked()){
        ui->checkBox_3->setChecked(false);
        ui->checkBox->setChecked(false);
        ui->checkBox_3->setEnabled(false);
        ui->checkBox->setEnabled(false);


    }
    if(!ui->checkBox_6->isChecked()){
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_3->setChecked(true);
        ui->checkBox->setEnabled(true);
        ui->checkBox->setChecked(true);

    }
}
void MainWindow::logic1(){
    int slval = ui->horizontalSlider->value();
    ui->label_3->clear();
    random_device device;
    mt19937 generate(device());
    uniform_int_distribution<> numericals(0,9);
    uniform_int_distribution<> smallAlpha('a','z');
    vector<char> symbols = {'!', '@', '#', '$', '%', '^', '&', '*',')','(','~','`',';',':'};
    uniform_int_distribution<> symbolpick(0, symbols.size() - 1);
    uniform_int_distribution<> randomgen(0,2);




    // the generating logic
    for(int n=0;n<slval;n++){
        int randomprint = randomgen(generate);
        if(randomprint==0){
            int numbers = numericals(generate) ;
            ui->label_3->setText(ui->label_3->text() + QString::number(numbers));
        }
        if(randomprint==1){
            char small_alpha = smallAlpha(generate) ;
            ui->label_3->setText(ui->label_3->text() + small_alpha);
        }
        if(randomprint==2){
            char specialchars = symbols[symbolpick(generate)] ;
            ui->label_3->setText(ui->label_3->text() + specialchars);
        }
        }
}

void MainWindow::style(){
    //coloring

    ui->horizontalSlider->setStyleSheet(
        "QSlider {"
        "    background: rgb(27, 27, 27);"  // Set the overall background color for the entire slider
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
