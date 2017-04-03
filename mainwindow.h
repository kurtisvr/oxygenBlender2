#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
//#include "alarmWindow.h"
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //alarmWindow *myAlarm;

    //All methods are declared here
private slots:
    void spO2SetPoint();
    void fiO2SetPoint();
    void timeInterval();
    void beginWeaning();
    void one();
    void two();
    void three();
    void four();
    void five();
    void six();
    void seven();
    void eight();
    void nine();
    void zero();
    void decimal();
    void spO2Enter();
    void fiO2Enter();
    void timeEnter();
    //void showPopUp();

    //Every label/button/etc declared here
private:
    QLabel *spO2Label;
    QLabel *fiO2Label;
    QLabel *timeLabel;
    QLabel *editLabel;
    QLabel *timerLabel;
    QLabel *currentFiO2Label;
    QLabel *currentSpO2Label;
    QLabel *changingSpO2Label;
    QLabel *changingFiO2Label;
    QLabel *changingTimeLabel;
    QLabel *alarmLabel;             //Comment out later
    QLabel *fiO2CheckLabel;         //Comment out later

    QPushButton *spO2SetPoint_Button;
    QPushButton *fiO2SetPoint_Button;
    QPushButton *timeInterval_Button;
    QPushButton *beginWeaning_Button;
    QPushButton *one_Button;
    QPushButton *two_Button;
    QPushButton *three_Button;
    QPushButton *four_Button;
    QPushButton *five_Button;
    QPushButton *six_Button;
    QPushButton *seven_Button;
    QPushButton *eight_Button;
    QPushButton *nine_Button;
    QPushButton *zero_Button;
    QPushButton *decimal_Button;
    QPushButton *spO2Enter_Button;
    QPushButton *fiO2Enter_Button;
    QPushButton *timeEnter_Button;

    QMessageBox alarmBox;

};

#endif // MAINWINDOW_H
