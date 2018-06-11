#include "database.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>

#include <QSqlQuery>
#include <QSql>


DataBase::DataBase(QObject *parent) : QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");

    QSqlQuery qry;
    qry.prepare( "INSERT INTO coord (id, xCoord, yCoord) VALUES (1, 0, 0)" );
      if( !qry.exec() ) {
        qDebug() << qry.lastError();
      }
      else {
        qDebug( "Initialized!" );
      }
}

void DataBase::connectToDataBase()
{
    if (!m_db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
                              QObject::tr("Unable to establish a database connection.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        qDebug() << m_db.lastError();
    }
    else {
        qDebug() << "DataBase: connection ok";
    }
}

DataBase::~DataBase()
{
    closeDataBase();
}

void DataBase::setCoord(int x, int y)
{
    QSqlQuery qry;
    qry.prepare( "UPDATE coord SET xCoord = :x, yCoord = :y WHERE id = 1" );
    qry.addBindValue(x);
    qry.addBindValue(y);
    qry.exec();
      if( !qry.exec() ) {
        qDebug() << qry.lastError();
      }
      else {
        qDebug( "Updated!" );
      }

}


//bool DataBase::restoreDataBase()
//{
//    if(this->openDataBase()){
//        if(!this->createTable()){
//            return false;
//        } else {
//            return true;
//        }
//    } else {
//        qDebug() << "Не удалось восстановить базу данных";
//        return false;
//    }
//    return false;
//}


//bool DataBase::openDataBase()
//{
//    /* База данных открывается по заданному пути
//     * и имени базы данных, если она существует
//     * */
//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setHostName(DATABASE_HOSTNAME);
//    db.setDatabaseName("C:/example/" DATABASE_NAME);
//    if(db.open()){
//        return true;
//    } else {
//        return false;
//    }
//}


void DataBase::closeDataBase()
{
    m_db.close();
}

void DataBase::createTable()
{
    QSqlQuery qry;
    qry.prepare( "CREATE TABLE IF NOT EXISTS coord (id INTEGER UNIQUE PRIMARY KEY, xCoord INTEGER, yCoord INTEGER)" );
    if( !qry.exec() ) {
        qDebug() << qry.lastError();
    } else {
        qDebug() << "Table created!";
    }
}

void DataBase::setName(const QString &path)
{
    m_db.setDatabaseName(path);
}
