#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "alarmWindow.h"

#include <QTCore/QCoreApplication>
#include <QElapsedTimer>
#include <QMessageBox>


#include <iostream>
#include <fstream>
#include <string>

//Global Variables:
QString spO2SetPoint = "", fiO2SetPoint = "", timerSetPoint = "";
//QString spO2Level = "", fiO2Level = "", time = "";
double spO2Level, fiO2Level, timeLevel, timeLevelConstant;
QString value = "";

//Defining the mainWindow, setting up all labels + buttons
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    spO2Label = new QLabel("SpO2: 100", this);                                  //Set label equal to text
    spO2Label -> setGeometry(QRect(QPoint(75,25), QSize(50,200)));              //Where the label will be located/size

    fiO2Label = new QLabel("FiO2: 100", this);
    fiO2Label -> setGeometry(QRect(QPoint(75,75), QSize(50,200)));

    timeLabel = new QLabel("Time: 100", this);
    timeLabel -> setGeometry(QRect(QPoint(75,125), QSize(50,200)));

    spO2SetPoint_Button = new QPushButton("Change SpO2", this);                     //Set button equal to text
    spO2SetPoint_Button -> setGeometry(QRect(QPoint(150, 100), QSize(125,50)));     //Where the button will be located/size
    connect(spO2SetPoint_Button, SIGNAL(released()), this, SLOT(spO2SetPoint()));   //Connects the button to a method below that happens when button is pressed

    fiO2SetPoint_Button = new QPushButton("Change FiO2", this);
    fiO2SetPoint_Button -> setGeometry(QRect(QPoint(150, 150), QSize(125,50)));
    connect(fiO2SetPoint_Button, SIGNAL(released()), this, SLOT(fiO2SetPoint()));

    timeInterval_Button = new QPushButton("Change Time Inteval", this);
    timeInterval_Button -> setGeometry(QRect(QPoint(150,200), QSize(125,50)));
    connect(timeInterval_Button, SIGNAL(released()), this, SLOT(timeInterval()));

    beginWeaning_Button = new QPushButton("Start", this);
    beginWeaning_Button -> setGeometry(QRect(QPoint(300,150), QSize(50, 50)));
    connect(beginWeaning_Button, SIGNAL(released()), this, SLOT(beginWeaning()));

    one_Button = new QPushButton("1", this);
    one_Button  -> setGeometry(QRect(QPoint(150,100), QSize(50,50)));
    connect(one_Button, SIGNAL(released()), this, SLOT(one()));
    one_Button -> hide();//Not displayed on initial screen

    two_Button = new QPushButton("2", this);
    two_Button  -> setGeometry(QRect(QPoint(200,100), QSize(50,50)));
    connect(two_Button, SIGNAL(released()), this, SLOT(two()));
    two_Button -> hide();//Not displayed on initial screen

    three_Button = new QPushButton("3", this);
    three_Button  -> setGeometry(QRect(QPoint(250,100), QSize(50,50)));
    connect(three_Button, SIGNAL(released()), this, SLOT(three()));
    three_Button -> hide();//Not displayed on initial screen

    four_Button = new QPushButton("4", this);
    four_Button  -> setGeometry(QRect(QPoint(150,150), QSize(50,50)));
    connect(four_Button, SIGNAL(released()), this, SLOT(four()));
    four_Button -> hide();//Not displayed on initial screen

    five_Button = new QPushButton("5", this);
    five_Button  -> setGeometry(QRect(QPoint(200,150), QSize(50,50)));
    connect(five_Button, SIGNAL(released()), this, SLOT(five()));
    five_Button -> hide();//Not displayed on initial screen

    six_Button = new QPushButton("6", this);
    six_Button  -> setGeometry(QRect(QPoint(250,150), QSize(50,50)));
    connect(six_Button, SIGNAL(released()), this, SLOT(six()));
    six_Button -> hide();//Not displayed on initial screen

    seven_Button = new QPushButton("7", this);
    seven_Button  -> setGeometry(QRect(QPoint(150,200), QSize(50,50)));
    connect(seven_Button, SIGNAL(released()), this, SLOT(seven()));
    seven_Button -> hide();//Not displayed on initial screen

    eight_Button = new QPushButton("8", this);
    eight_Button  -> setGeometry(QRect(QPoint(200,200), QSize(50,50)));
    connect(eight_Button, SIGNAL(released()), this, SLOT(eight()));
    eight_Button -> hide();//Not displayed on initial screen

    nine_Button = new QPushButton("9", this);
    nine_Button  -> setGeometry(QRect(QPoint(250,200), QSize(50,50)));
    connect(nine_Button, SIGNAL(released()), this, SLOT(nine()));
    nine_Button -> hide();//Not displayed on initial screen

    zero_Button = new QPushButton("0", this);
    zero_Button  -> setGeometry(QRect(QPoint(150,250), QSize(50,50)));
    connect(zero_Button, SIGNAL(released()), this, SLOT(zero()));
    zero_Button -> hide();//Not displayed on initial screen

    decimal_Button = new QPushButton(".", this);
    decimal_Button  -> setGeometry(QRect(QPoint(200,250), QSize(50,50)));
    connect(decimal_Button, SIGNAL(released()), this, SLOT(decimal()));
    decimal_Button -> hide();//Not displayed on initial screen

    spO2Enter_Button = new QPushButton("Enter", this);
    spO2Enter_Button  -> setGeometry(QRect(QPoint(250,250), QSize(100,50)));
    connect(spO2Enter_Button, SIGNAL(released()), this, SLOT(spO2Enter()));
    spO2Enter_Button -> hide();//Not displayed on initial screen

    fiO2Enter_Button = new QPushButton("Enter", this);
    fiO2Enter_Button  -> setGeometry(QRect(QPoint(250,250), QSize(100,50)));
    connect(fiO2Enter_Button, SIGNAL(released()), this, SLOT(fiO2Enter()));
    fiO2Enter_Button -> hide();//Not displayed on initial screen

    timeEnter_Button = new QPushButton("Enter", this);
    timeEnter_Button  -> setGeometry(QRect(QPoint(250,250), QSize(100,50)));
    connect(timeEnter_Button, SIGNAL(released()), this, SLOT(timeEnter()));
    timeEnter_Button -> hide();//Not displayed on initial screen

    editLabel = new QLabel("", this);
    editLabel -> setGeometry(QRect(QPoint(400,75), QSize(200,200)));
    editLabel -> hide();//Not displayed on initial screen

    timerLabel = new QLabel("", this);
    timerLabel -> setGeometry(QRect(QPoint(75,125), QSize(50, 200)));
    timerLabel -> hide();//Not displayed on initial screen

    currentSpO2Label = new QLabel("", this);
    currentSpO2Label -> setGeometry(QRect(QPoint(75,25), QSize(200, 200)));
    currentSpO2Label -> hide();//Not displayed on initial screen

    currentFiO2Label = new QLabel("", this);
    currentFiO2Label -> setGeometry(QRect(QPoint(75,75), QSize(200, 200)));
    currentFiO2Label -> hide();//Not displayed on initial screen

    changingSpO2Label = new QLabel("Enter SpO2 Value", this);
    changingSpO2Label -> setGeometry(QRect(QPoint(400,0), QSize(200,200)));
    changingSpO2Label -> hide();

    changingFiO2Label = new QLabel("Enter FiO2 Value", this);
    changingFiO2Label -> setGeometry(QRect(QPoint(400,0), QSize(200,200)));
    changingFiO2Label -> hide();

    changingTimeLabel = new QLabel("Enter Time Value (seconds)", this);
    changingTimeLabel -> setGeometry(QRect(QPoint(400,0), QSize(200,200)));
    changingTimeLabel -> hide();

    alarmLabel = new QLabel("Alarm", this);
    alarmLabel -> setGeometry(QRect(QPoint(150, 150), QSize(200,200)));
    alarmLabel -> hide();

    fiO2CheckLabel = new QLabel("FiO2 Check:", this);
    fiO2CheckLabel -> setGeometry(QRect(QPoint(150, 100), QSize(200,200)));
    fiO2CheckLabel -> hide();

    //myAlarm = new alarm1;
    //QMessageBox alarmBox;
    alarmBox.setText("Continue?");
    alarmBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

}


//Change SpO2 Set Point to w/e user wants
void MainWindow::spO2SetPoint(){
    //Hide all setup variables
    spO2Label -> hide();
    spO2SetPoint_Button -> hide();
    fiO2Label -> hide();
    fiO2SetPoint_Button -> hide();
    timeLabel -> hide();
    timeInterval_Button -> hide();
    beginWeaning_Button -> hide();

    //Show input buttons so user can input a new number
    one_Button -> show();
    two_Button -> show();
    three_Button -> show();
    four_Button -> show();
    five_Button -> show();
    six_Button -> show();
    seven_Button -> show();
    eight_Button -> show();
    nine_Button -> show();
    zero_Button -> show();
    spO2Enter_Button -> show();
    editLabel -> show();
    decimal_Button -> show();
    changingSpO2Label -> show();
}

//Change FiO2 Set Point to w/e user wants
void MainWindow::fiO2SetPoint(){
    //Hide all setup variables
    spO2Label -> hide();
    spO2SetPoint_Button -> hide();
    fiO2Label -> hide();
    fiO2SetPoint_Button -> hide();
    timeLabel -> hide();
    timeInterval_Button -> hide();
    beginWeaning_Button -> hide();

    //Show input buttons so user can input a new number
    one_Button -> show();
    two_Button -> show();
    three_Button -> show();
    four_Button -> show();
    five_Button -> show();
    six_Button -> show();
    seven_Button -> show();
    eight_Button -> show();
    nine_Button -> show();
    zero_Button -> show();
    fiO2Enter_Button -> show();
    editLabel -> show();
    decimal_Button -> show();
    changingFiO2Label -> show();
}

//Change time interval to whatever user wants
void MainWindow::timeInterval(){
    //Hide all setup variables
    spO2Label -> hide();
    spO2SetPoint_Button -> hide();
    fiO2Label -> hide();
    fiO2SetPoint_Button -> hide();
    timeLabel -> hide();
    timeInterval_Button -> hide();
    beginWeaning_Button -> hide();

    //Show input buttons so user can input a new number
    one_Button -> show();
    two_Button -> show();
    three_Button -> show();
    four_Button -> show();
    five_Button -> show();
    six_Button -> show();
    seven_Button -> show();
    eight_Button -> show();
    nine_Button -> show();
    zero_Button -> show();
    timeEnter_Button -> show();
    editLabel -> show();
    decimal_Button -> show();
    changingTimeLabel -> show();
}


//Methods that are called whenever a button is pressed
void MainWindow::one(){
    value = value + "1";
    editLabel -> setText(value);
}

void MainWindow::two(){
    value = value + "2";
    editLabel -> setText(value);
}

void MainWindow::three(){
    value = value + "3";
    editLabel -> setText(value);
}

void MainWindow::four(){
    value = value + "4";
    editLabel -> setText(value);
}

void MainWindow::five(){
    value = value + "5";
    editLabel -> setText(value);
}

void MainWindow::six(){
    value = value + "6";
    editLabel -> setText(value);
}

void MainWindow::seven(){
    value = value + "7";
    editLabel -> setText(value);
}

void MainWindow::eight(){
    value = value + "8";
    editLabel -> setText(value);
}

void MainWindow::nine(){
    value = value + "9";
    editLabel -> setText(value);
}

void MainWindow::zero(){
    value = value + "0";
    editLabel -> setText(value);
}

void MainWindow::decimal(){
    value = value + ".";
    editLabel -> setText(value);
}

void MainWindow::spO2Enter(){//Enter button for spO2 input screen
    spO2Level = value.toDouble();
    //spO2SetPoint = QString::number(spO2Level);
    spO2Label -> setText(value);
    value = "";
    editLabel -> setText(value);

    one_Button -> hide();
    two_Button -> hide();
    three_Button -> hide();
    four_Button -> hide();
    five_Button -> hide();
    six_Button -> hide();
    seven_Button -> hide();
    eight_Button -> hide();
    nine_Button -> hide();
    zero_Button -> hide();
    spO2Enter_Button -> hide();
    editLabel -> hide();
    decimal_Button -> hide();
    changingSpO2Label -> hide();

    spO2Label -> show();
    spO2SetPoint_Button -> show();
    fiO2Label -> show();
    fiO2SetPoint_Button -> show();
    timeLabel -> show();
    timeInterval_Button -> show();
    beginWeaning_Button -> show();
}

void MainWindow::fiO2Enter(){//Enter button for fiO2 input screen
    fiO2Level = value.toDouble();
    //spO2SetPoint = QString::number(spO2Level);
    fiO2Label -> setText(value);
    value = "";
    editLabel -> setText(value);

    one_Button -> hide();
    two_Button -> hide();
    three_Button -> hide();
    four_Button -> hide();
    five_Button -> hide();
    six_Button -> hide();
    seven_Button -> hide();
    eight_Button -> hide();
    nine_Button -> hide();
    zero_Button -> hide();
    fiO2Enter_Button -> hide();
    editLabel -> hide();
    decimal_Button -> hide();
    changingFiO2Label -> hide();

    spO2Label -> show();
    spO2SetPoint_Button -> show();
    fiO2Label -> show();
    fiO2SetPoint_Button -> show();
    timeLabel -> show();
    timeInterval_Button -> show();
    beginWeaning_Button -> show();
}

void MainWindow::timeEnter(){//Enter button for time interval screen
    timeLevel = value.toDouble();
    //spO2SetPoint = QString::number(spO2Level);
    timeLabel -> setText(value);
    value = "";
    editLabel -> setText(value);

    one_Button -> hide();
    two_Button -> hide();
    three_Button -> hide();
    four_Button -> hide();
    five_Button -> hide();
    six_Button -> hide();
    seven_Button -> hide();
    eight_Button -> hide();
    nine_Button -> hide();
    zero_Button -> hide();
    timeEnter_Button -> hide();
    editLabel -> hide();
    decimal_Button -> hide();
    changingTimeLabel -> hide();

    spO2Label -> show();
    spO2SetPoint_Button -> show();
    fiO2Label -> show();
    fiO2SetPoint_Button -> show();
    timeLabel -> show();
    timeInterval_Button -> show();
    beginWeaning_Button -> show();
}



std::string getLastLine(std::ifstream& in){
    std::string line;
    while(in >> std::ws && std::getline(in, line));
    return line;
}

//Begin main process here:
void MainWindow::beginWeaning(){

    //Hide all setup variables
    spO2Label -> hide();
    spO2SetPoint_Button -> hide();
    fiO2Label -> hide();
    fiO2SetPoint_Button -> hide();
    timeLabel -> hide();
    timeInterval_Button -> hide();
    beginWeaning_Button -> hide();

    //Show new variables
    timerLabel -> show();
    currentFiO2Label -> show();
    currentSpO2Label -> show();
    alarmLabel -> show();
    fiO2CheckLabel -> show();
    //Display SpO2 SetPoint, FiO2 SetPoint, Time Interval

    /*
     * spO2 Setpoint stored in "spO2Level"
     * fiO2 Setpoint stored in "fiO2Level"
     * time interval (in seconds) stored in "timeLevel"
     *
     */

    std::ifstream file("example.txt");
    std::string line;
    if(file){
        line = getLastLine(file);

    }
    else
        std::cout << "Unable to open file.\n";

   // std::string line = ".98";
    //std::string::size_type sz;
    //*******************************************************************************************************
    //These inputs will be from the pulse ox
    double input1 = .98;//Patient fiO2 level
    double input2 = .98;//Patinet spO2 level
    //*******************************************************************************************************

    int counter = 0;
    double fiO2 = input1;
    double spO2 = input2;
    double fiO2Check = .6;
    int alarm = 0;
    int problem = 0;
    int timerPlaceholder = 0;

    timeLevelConstant = timeLevel;
    currentFiO2Label -> setText("FiO2:   " + QString::number(fiO2));
    currentSpO2Label -> setText("SpO2:   " + QString::number(spO2));
    alarmLabel -> setText("Alarm: " + QString::number(alarm));
    fiO2CheckLabel -> setText("FiO2 Check: " + QString::number(fiO2Check));

    qApp -> processEvents();

//    QElapsedTimer timer;
//    timer.start();
//    while(1){
//        if(timer.elapsed()==5000){
//            break;
//        }
//    }



    QElapsedTimer timer;
    timer.start();
    for(int i = 0; i < 10; i++){
        timerLabel -> setText(QString::number(timer.elapsed()));
    }
    while(1){
        currentFiO2Label -> setText("FiO2:   " + QString::number(fiO2));
        currentSpO2Label -> setText("SpO2:   " + QString::number(spO2));

        while(counter < timeLevel){
            counter = timer.elapsed() + timerPlaceholder;  //in milliseconds
            counter = counter/1000;     //counter in seconds
            timerLabel -> setText("Time: " + QString::number(counter));
            qApp -> processEvents();
            //insert code to receive spO2 level here
//            if(spO2 < spO2Level){
//                fiO2 = fiO2 + fiO2Level;
//                problem = 1;
//                break;
//            }
        }

        if(problem == 1){
            timerPlaceholder = timerPlaceholder + timer.elapsed();
            int ret = alarmBox.exec();
            switch (ret){
                case QMessageBox::Yes:
                timer.restart();
                problem = 0;
                    break;
                case QMessageBox::No:
                    problem = 1;
            }
        }

        if(problem == 1){
            QApplication::quit();
        }
//        while(counter < timeLevel){
//            if(spO2 < spO2Level){
//                fiO2 = fiO2 + .1;
//                problem = 1;
//                QApplication::quit();
//                break;
//            }
//        }
//        if(problem ==1){
//            alarm = 1;
//        }

        if(fiO2 - fiO2Level <= fiO2Check){
            alarm = 1;
            alarmLabel -> setText("Alarm: " + QString::number(alarm));

//            QApplication a(argc, argv);
//            alarmWindow w;
//            w.showMaximized();
            qApp -> processEvents();

            fiO2 = fiO2 - fiO2Level;

            //wait for nurse input

            //Change fiO2 check for next iteration
            if(fiO2 <= .6 && fiO2 > .4){
                fiO2Check = .4;
                timerPlaceholder = timerPlaceholder + timer.elapsed();
                int ret = alarmBox.exec();
                switch (ret){
                    case QMessageBox::Yes:
                    timer.restart();
                        break;
                    case QMessageBox::No:
                        QApplication::quit();
                }
            }
            else if(fiO2 <= .4 && fiO2 > .25){
                fiO2Check = .25;
                timerPlaceholder = timerPlaceholder + timer.elapsed();
                int ret = alarmBox.exec();
                switch (ret){
                    case QMessageBox::Yes:
                    timer.restart();
                        break;
                    case QMessageBox::No:
                        QApplication::quit();
                }
            }
            else if(fiO2 <= .25){
                //Patient successfully weaned
                //QApplication::quit();
                this-> close();//Closes program when we get to this point
            }
        }
        else{
            if(problem == 1){
                //this -> close();
                QApplication::quit();
            }
            fiO2 = fiO2 - fiO2Level;
        }
        alarm = 0;
        alarmLabel -> setText("Alarm: " + QString::number(alarm));
        fiO2CheckLabel -> setText("FiO2 Check: " + QString::number(fiO2Check));
        qApp -> processEvents();
        timeLevel = timeLevel + timeLevelConstant;

    }

}



MainWindow::~MainWindow()
{

}
