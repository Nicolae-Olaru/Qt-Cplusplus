#ifndef DB_MANIPULATION_H
#define DB_MANIPULATION_H

#include "strutture.h"

#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
//#include <QSqlDatabase>
//#include <QSql>
#include <QDebug>
#include <QString>


#include <QList>

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>



class DB_manipulation{
private:
    QString host_ip;
    int host_port;
    QString database_type;
    QString user;
    QString password;
    QString database_name;
public:

    DB_manipulation(QString host_ip,int host_port,QString type_db,QString database_name,QString username,QString password);

    void set_host_ip(QString host_ip);
    void set_host_port(int host_port);
    void set_database_type(QString type_db);
    void set_database_name(QString database_name);
    void set_username(QString username);
    void set_password(QString password);

    bool check_db_connection();
    void extract_data_all(data_t &data);
    int max_rows();
    bool insert_data_line(QString nome,QString cognome,QString tipo,int cilindrata);

};




#endif // DB_MANIPULATION_H
