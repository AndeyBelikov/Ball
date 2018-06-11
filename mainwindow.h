#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QPainter>
#include <QCloseEvent>
#include <QString>

#include "circle.h"
#include "logic.h"
#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Circle circle;
    Logic logic;
    DataBase m_db;

protected:
    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *event);

public slots:


signals:
    void finished();
    void updateDb(int, int);


private slots:
    void on_start_clicked();
    void on_stop_clicked();


private:
    Ui::MainWindow *ui;
    QThread thread_1;
    QThread thread_2;

    int windowHeight;
    int windowWidth;
};

#endif // MAINWINDOW_H
