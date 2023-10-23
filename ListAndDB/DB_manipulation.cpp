
#include "DB_manipulation.h"

#include <QList>
//#include <QSqlError>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>


DB_manipulation::DB_manipulation(QString host_ip,int host_port,QString type_db,QString database_name,QString username,QString password)
{
    this->host_ip = host_ip ;
    this->host_port = host_port ;
    this->database_type = type_db ;
    this->user = username;
    this->password = password;
    this->database_name = database_name;

}
void DB_manipulation::set_database_name(QString database_name){
    this->database_name = database_name;
};
void DB_manipulation::set_host_ip(QString host_ip){
    this->host_ip = host_ip;
};
void DB_manipulation::set_host_port(int host_port){
    this->host_port = host_port ;
};
void DB_manipulation::set_database_type(QString type_db){
    this->database_type = type_db ;
};
void DB_manipulation::set_username(QString username){
    this->user = username;
};
void DB_manipulation::set_password(QString password){
    this->password = password;
};

bool DB_manipulation::check_db_connection(){
    QSqlDatabase db = QSqlDatabase::addDatabase(this->database_type);
    db.setHostName(this->host_ip);
    db.setDatabaseName(this->database_name);
    db.setUserName(this->user);
    db.setPassword(this->password);
    db.setPort(this->host_port);
    bool ok = db.open();
    db.close();
    return ok;
};

void DB_manipulation::extract_data_all(data_t &data[])
{
    qDebug() <<sizeof(int32_t);

    QSqlDatabase db = QSqlDatabase::addDatabase(this->database_type);
    db.setHostName(this->host_ip);
    db.setDatabaseName(this->database_name);
    db.setUserName(this->user);
    db.setPassword(this->password);
    db.setPort(this->host_port);
    db.open();
    QSqlQuery countQuery;
    countQuery.exec("SELECT COUNT(*) FROM info");
    countQuery.next();
    int rowCount = countQuery.value(0).toInt();
    QSqlQuery query("select * from info");
    if( query.exec("select * from info") )
    {
        int i = 0 ;
        while(i < rowCount ){
            data[i].id = query.value("id").toInt();
            data[i].nome = query.value("nome").toString();
            data[i].cognome = query.value("cognome").toString();
            data[i].tipo_macchina = query.value("tipo_macchina").toString();
            data[i].cilindrata = query.value("cilindrata").toInt();
            query.next();
            i++;
        }
    }
    db.close();

//    table.setRowCount(rowCount);
//    table.setColumnCount(5);

};
int DB_manipulation::max_rows(){
    QSqlDatabase db = QSqlDatabase::addDatabase(this->database_type);
    db.setHostName(this->host_ip);
    db.setDatabaseName(this->database_name);
    db.setUserName(this->user);
    db.setPassword(this->password);
    db.setPort(this->host_port);
    db.open();
    QSqlQuery countQuery;
    countQuery.exec("SELECT COUNT(*) FROM info");
    countQuery.next();
    int rowCount = countQuery.value(0).toInt();
    db.close();
    return rowCount;
};
/*
bool DB_manipulation::insert_data_line(QString nome,QString cognome,QString tipo,int cilindrata)
{
};
*/
