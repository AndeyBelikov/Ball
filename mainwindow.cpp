#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

#include <QSignalSpy>
#include <QTest>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    windowHeight = 500;
    windowWidth = 1000;
    this->setFixedSize(windowWidth, windowHeight);

    m_db.setName("./circleCoordinates.db");
    m_db.connectToDataBase();
    m_db.createTable();

    connect(this, &MainWindow::updateDb, &m_db, &DataBase::setCoord);

    connect(&thread_1, &QThread::started, &logic, &Logic::run);
    connect(&thread_2, &QThread::started, &circle, &Circle::run);

    connect(&logic, &Logic::finished, &thread_1, &QThread::quit, Qt::DirectConnection);
    connect(&circle, &Circle::finished, &thread_2, &QThread::quit, Qt::DirectConnection);

    connect(&logic, &Logic::sendMessage, &circle, &Circle::setMessage, Qt::DirectConnection);


    logic.moveToThread(&thread_1);
    circle.moveToThread(&thread_2);

}



MainWindow::~MainWindow()
{
    //QSignalSpy spy(&thread_1, SIGNAL( finished() ));
    //QCOMPARE(spy.count(), 2);
    //qDebug() << spy.count();
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(circle.getX(), circle.getY(), 100, 100);
    update();

}

void MainWindow::closeEvent(QCloseEvent *event)
{

    QMessageBox::StandardButton askUser;
    askUser = QMessageBox::question( this,  QApplication::applicationName(), tr(" Do you want to close programm ? "),
                                     QMessageBox::Yes | QMessageBox::No , QMessageBox::No );
    if (askUser == QMessageBox::No) {
        event->ignore();
    } else {
        circle.setRunning(false);
        logic.setRunning(false);
        thread_1.wait();
        thread_2.wait();
        event->accept();
    }
}


void MainWindow::on_start_clicked()
{
    circle.setRunning(true);
    logic.setRunning(true);

    thread_1.start();
    thread_2.start();
}



void MainWindow::on_stop_clicked()
{
    emit updateDb(circle.getX(), circle.getY());
    qDebug() << QWidget::size();
    circle.setRunning(false);
    logic.setRunning(false);
}
