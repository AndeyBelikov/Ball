#ifndef CIRCLE_H
#define CIRCLE_H

//#include <QObject>
#include <exampleobject.h>
//#include <QWidget>


class Circle : public ExampleObject
{
    Q_OBJECT

public:
    virtual ~Circle();
    Circle();
    void setX(int);
    void setY(int);
    //void setDir(bool);
    int getX();
    int getY();
    //bool getDir();

signals:


public slots:
    void run() override;
    void setMessage(int, int);

private:
    //bool dir;
    int x;
    int y;
};

#endif // CIRCLE_H
