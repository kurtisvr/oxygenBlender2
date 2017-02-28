#include "alarmWindow.h"
#include "ui_alarmWindow.h"

Alarm::Alarm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alarm)
{
    ui->setupUi(this);
    continueButton = new QPushButton("Continue", this);
    connect(continueButton, SIGNAL(released()), this, SLOT(continueMethod()));
    stopButton = new QPushButton("Stop", this);
    connect(stopButton, SIGNAL(released()), this, SLOT(stopMethod()));

    //connect(spO2SetPoint_Button, SIGNAL(released()), this, SLOT(spO2SetPoint()));
}

void alarmWindow::continueMethod(){

}

void alarmWindow::stopMethod(){

}


Alarm::~Alarm()
{
    delete ui;
}
