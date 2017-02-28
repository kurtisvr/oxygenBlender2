#ifndef ALARM_H
#define ALARM_H

#include <QDialog>

namespace Ui {
class Alarm;
}

class Alarm : public QDialog
{
    Q_OBJECT

public:
    explicit Alarm(QWidget *parent = 0);
    ~Alarm();

private slots:
    void continueMethod();
    void stopMethod();


private:
    Ui::Alarm *ui;
    //alarmWindow *myDialog();

    QPushButton *continueButton;
    QPushButton *stopButton;
};

#endif // ALARM_H
