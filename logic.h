#ifndef LOGIC_H
#define LOGIC_H

//#include <QObject>
#include <exampleobject.h>
#include <QTimer>

class Logic : public ExampleObject
{
    Q_OBJECT

public:
    virtual ~Logic();
    Logic();
    void checkCollision();
    bool getDir();
    void setDir(bool);
    //QTimer *timer;

signals:
    void updateDb(int, int);
    void sendMessage(int, int);

public slots:
    void run() override;
    void doLogic();
    //void timerAlarm();

private:
    //QTimer *timer;
    bool dir;
    int x;
    int y;
};

#endif // LOGIC_H
