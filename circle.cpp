#include "circle.h"
#include <QDebug>

Circle::Circle() : x(0), y(0)
{

}

Circle::~Circle()
{
    if (running()) {
        emit finished();
    }
}


void Circle::setX(int x)
{
    this->x = x;
}

void Circle::setY(int y)
{
    this->y = y;
}

//void Circle::setDir(bool dir)
//{
//    this->dir = dir;
//}

int Circle::getX()
{
    return x;
}

int Circle::getY()
{
    return y;
}

//bool Circle::getDir()
//{
//    return dir;
//}



void Circle::run()
{
    if (running()) {
        //qDebug() << running();
        emit finished();
    }
}

void Circle::setMessage(int x, int y)
{
    this->x = x;
    //qDebug() << this->x << this->y;
}
