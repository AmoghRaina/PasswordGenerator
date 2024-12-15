#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <random>
#include <vector>
#include <QString>
using namespace std;
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
    bool numt =true;
    bool symbolst =true;
    bool smallAlp=true;
    bool bigAlp=true;
    QString generatedPassword;


private:
    Ui::MainWindow *ui;
    void style();
    void generatePassword(int state);
    void sliderValue(int val);
    void checkbox();
    void checkbox2();
    void logic1();
    void copy();
    void easy();
    void check();
};
#endif // MAINWINDOW_H
