#ifndef MODBUSCLASS_H
#define MODBUSCLASS_H



#include <QString>
#include <modbus/modbus.h>

class ModbusClass{

public:
    void setIP(QString ip);
    void setPORT(int port);
    int connect();
    bool isConnected();
    void disconnect();
    void insert_data(QString input);
    int read_register_in(int addr, uint16_t *valore);
    int read_register_out(int addr, uint16_t *valore);
    void write_register(int address,int value);


private:
    QString ip;
    int port;
    bool setup_connect;
    modbus_t *my_modbus = nullptr;
};
#endif // MODBUSCLASS_H


