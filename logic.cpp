#include "logic.h"
#include <QDebug>
//#include <QThread>
#include <QSql>
#include <QTest>


Logic::Logic() : x(0), y(0)
{
    //timer = new QTime(this);
}

Logic::~Logic()
{
    if (running()) {
        emit finished();
    }
}



void Logic::doLogic()
{
    x++;
    y++;
}

void Logic::checkCollision()
{

}

bool Logic::getDir()
{
    return dir;
}

void Logic::setDir(bool dir)
{
    this->dir = dir;
}


void Logic::run()
{
    //connect(&timer, &QTimer::timeout, this, &Logic::doLogic);
    while (running()) {
        checkCollision();
        doLogic();
        QTest::qSleep(5);
        //timer->start(15);
        emit sendMessage(x, y);
    }
    emit finished();
}
