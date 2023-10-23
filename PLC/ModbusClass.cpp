
#include <QString>
#include <QThread>
#include <modbus/modbus.h>
#include <QDebug>
#include "ModbusClass.h"




// Connection Try4
int ModbusClass::connect(){

    this->my_modbus = modbus_new_tcp(this->ip.toStdString().c_str(),this->port);

    int rc = modbus_connect(my_modbus);
    qDebug() << rc ;
    if ( rc == 0 )
    {
        setup_connect = true;
        return 1;

    }
    else
    {
        setup_connect = false;
        return -1;
    }
};
// SET IP
void ModbusClass::setIP(QString ip){
    this->ip = ip;
};
// SET Port
void ModbusClass::setPORT(int port){
    this->port = port;
};

void ModbusClass::disconnect(){
    modbus_close(this->my_modbus);
};

int ModbusClass::read_register_in(int addr, uint16_t *valore){
    if( this->my_modbus != nullptr)
    {
        int res = 0;
        res = modbus_read_registers(this->my_modbus, addr, 1, valore);
        return 0;

    }
    else
        return -1;

    return 0;
};
int ModbusClass::read_register_out(int addr, uint16_t *valore){
    if( this->my_modbus != nullptr)
    {
        int res = modbus_read_registers(this->my_modbus, addr, 1, valore);
        return 1;
    }
    else
        return -1;

    return 0;
};

void ModbusClass::write_register(int address,int value){
    modbus_write_register(this->my_modbus, address, value);
};








































