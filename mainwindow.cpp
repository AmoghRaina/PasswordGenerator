#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <random>
#include <QClipboard>
#include <QTimer>

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
    if(ui->comboBox->currentIndex()==0){
    int slval = ui->horizontalSlider->value();
    ui->label_3->clear();
    generatedPassword.clear();

     // random distribution logic
    random_device device;
    mt19937 generate(device());
    uniform_int_distribution<> numericals(0,9);
    uniform_int_distribution<> smallAlpha('a','z');
    uniform_int_distribution<> bigAlpha('A', 'Z');
    vector<char> symbols = {'!', '@', '#', '$', '%', '^', '&', '*',')','(','~','`',';',':'};
    uniform_int_distribution<> symbolpick(0, symbols.size() - 1);

    uniform_int_distribution<> randomgen(0,3);

   // the generating logic

    for(int n=0;n<slval;n++){
        int randomprint = randomgen(generate);

        if(symbolst==true&&numt==false&&smallAlp==false&&bigAlp==false){
            randomprint=2;
        }
        if(symbolst==false&&numt==true&&smallAlp==false&&bigAlp==false){
            randomprint=0;
        }
        if(symbolst==false&&numt==false&&smallAlp==true&&bigAlp==false){
            randomprint=1;
        }
        if(symbolst==false&&numt==false&&smallAlp==false&&bigAlp==true){
            randomprint=3;
        }

        if(symbolst==false){
            if(randomprint==2)
                randomprint+=1;
        }
        if(numt==false){
            if(randomprint==0){
                randomprint+=1;
            }
        }
        if(smallAlp==false){
            if(randomprint==1){
                randomprint+=1;
            }
        }
        if(bigAlp==false){
            if(randomprint==3){
                randomprint-=3;
            }
        }


        if(randomprint==0&&numt==true){
            int numbers = numericals(generate) ;
           generatedPassword += QString::number(numbers);
        }
        if(randomprint==1&&smallAlp==true){
            char small_alpha = smallAlpha(generate) ;
                generatedPassword += QString(small_alpha);
        }
        if(randomprint==2&&symbolst==true){
            char specialchars = symbols[symbolpick(generate)] ;
            generatedPassword += QString(specialchars);
        }

        if(randomprint==3&&bigAlp==true){
            char bigA = bigAlpha(generate);
           generatedPassword += QString(bigA);
        }

        }
    ui->label_3->setText(generatedPassword);
        int sliderValue = ui->horizontalSlider->value();
    if (sliderValue < 4) {
        QMessageBox::warning(this, "Warning", "The slider value is too low! Please increase it.");
    } else if (sliderValue < 7) {
        ui->label_7->setStyleSheet("background-color: red;");
    } else if (sliderValue < 9) {
        ui->label_7->setStyleSheet("background-color: yellow;");
    }
    else if (sliderValue>=11){
        ui->label_7->setStyleSheet("background-color: green;");

    }
    }
    else{
        int slval = ui->horizontalSlider->value();
        ui->label_3->clear();
        generatedPassword.clear();

        // random distribution logic

        mt19937 generate(time(0));
        uniform_int_distribution<> numericals(0,9);
        uniform_int_distribution<> smallAlpha('a','z');
        uniform_int_distribution<> bigAlpha('A', 'Z');
        vector<char> symbols = {'!', '@', '#', '$', '%', '^', '&', '*',')','(','~','`',';',':'};
        uniform_int_distribution<> symbolpick(0, symbols.size() - 1);

        uniform_int_distribution<> randomgen(0,3);

        // the generating logic

        for(int n=0;n<slval;n++){
            int randomprint = randomgen(generate);

            if(symbolst==true&&numt==false&&smallAlp==false&&bigAlp==false){
                randomprint=2;
            }
            if(symbolst==false&&numt==true&&smallAlp==false&&bigAlp==false){
                randomprint=0;
            }
            if(symbolst==false&&numt==false&&smallAlp==true&&bigAlp==false){
                randomprint=1;
            }
            if(symbolst==false&&numt==false&&smallAlp==false&&bigAlp==true){
                randomprint=3;
            }

            if(symbolst==false){
                if(randomprint==2)
                    randomprint+=1;
            }
            if(numt==false){
                if(randomprint==0){
                    randomprint+=1;
                }
            }
            if(smallAlp==false){
                if(randomprint==1){
                    randomprint+=1;
                }
            }
            if(bigAlp==false){
                if(randomprint==3){
                    randomprint-=3;
                }
            }


            if(randomprint==0&&numt==true){
                int numbers = numericals(generate) ;
                generatedPassword += QString::number(numbers);
            }
            if(randomprint==1&&smallAlp==true){
                char small_alpha = smallAlpha(generate) ;
                generatedPassword += QString(small_alpha);
            }
            if(randomprint==2&&symbolst==true){
                char specialchars = symbols[symbolpick(generate)] ;
                generatedPassword += QString(specialchars);
            }

            if(randomprint==3&&bigAlp==true){
                char bigA = bigAlpha(generate);
                generatedPassword += QString(bigA);
            }

        }
        ui->label_3->setText(generatedPassword);
        int sliderValue = ui->horizontalSlider->value();
        if (sliderValue < 4) {
            QMessageBox::warning(this, "Warning", "The slider value is too low! Please increase it.");
        } else if (sliderValue < 7) {
            ui->label_7->setStyleSheet("background-color: red;");
        } else if (sliderValue < 9) {
            ui->label_7->setStyleSheet("background-color: yellow;");
        }
        else if (sliderValue>=11){
            ui->label_7->setStyleSheet("background-color: green;");

        }
    }
    }

void MainWindow::easy(){


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
