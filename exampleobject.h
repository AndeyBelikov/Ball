#ifndef EXAMPLEOBJECT_H
#define EXAMPLEOBJECT_H

#include <QObject>

class ExampleObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)


public:
    explicit ExampleObject(QObject *parent = 0);
    virtual ~ExampleObject();
    bool running() const;

private:
    bool m_running;

signals:
    void finished();
    void runningChanged(bool running);


public slots:
    virtual void run() = 0;
    void setRunning(bool running);
};

#endif // EXAMPLEOBJECT_H
