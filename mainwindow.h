// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H
#include <QMainWindow>
#include <QString>

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
    int slval;

private:
    Ui::MainWindow *ui;
    void style();
    void generatePassword(int state);
    void sliderValue(int val);
    void checkbox();
    void checkbox2();
    void logic1();
    void copy();
    void check();
    void timee();
};
// #endif // MAINWINDOW_H
