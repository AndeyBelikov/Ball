#include "exampleobject.h"

ExampleObject::ExampleObject(QObject *parent) : QObject(parent)
{

}


ExampleObject::~ExampleObject()
{

}


bool ExampleObject::running() const
{
    return m_running;
}



void ExampleObject::setRunning(bool running)
{
    if (m_running == running)
        return;

    m_running = running;
    emit runningChanged(running);
}

