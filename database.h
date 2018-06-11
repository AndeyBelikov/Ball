#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

#include <QString>
#include <QSqlDatabase>


class DataBase : public QObject
{
    Q_OBJECT

public:
    explicit DataBase(QObject *parent = 0);
    virtual ~DataBase();
    void connectToDataBase();
    void setDbName(const QString& path);
    void createTable();
    void setName(const QString& path);

public slots:
    void setCoord(int, int);

signals:

private:
    QSqlDatabase m_db;

//    bool openDataBase();
//    bool restoreDataBase();
    void closeDataBase();
};

#endif // DATABASE_H
