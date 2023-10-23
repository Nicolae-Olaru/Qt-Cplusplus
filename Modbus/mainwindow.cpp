#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QModbusClient>
#include <QModbusDevice>

#include <QElapsedTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbConn_clicked()
{
    if (_connector == nullptr)
        _connector = modbus_new_tcp(ui->leIPAddress->text().toStdString().c_str(),502);

    int rc = 0;
    if (_connector != nullptr)
    {
        rc = modbus_connect(_connector);

        //TODO: read Outputs and set push buttons
        bool bValue = false;
        //TODO: READ HERE
        ui->pbOut1->blockSignals(true);
        ui->pbOut1->setChecked(bValue);//UPDATE OUT 1
        ui->pbOut1->blockSignals(false);

        //TODO: READ HERE
        ui->pbOut2->blockSignals(true);
        ui->pbOut2->setChecked(bValue);//UPDATE OUT 2
        ui->pbOut2->blockSignals(false);

        //TODO: READ HERE
        ui->pbOut3->blockSignals(true);
        ui->pbOut3->setChecked(bValue);//UPDATE OUT 3
        ui->pbOut3->blockSignals(false);

        QElapsedTimer timer;


        if (rc != -1)
        {
            ui->groupBox->setEnabled(true);


            timer.start();
            modbus_write_register(_connector, 0, 55);
            qDebug() << "Time passed to connect : "<<timer.elapsed();
        }
        else
        {
            //TODO: error branch here!
            return;
        }


    }
}

void MainWindow::on_pbDisconn_clicked()
{
    if (_connector != nullptr)
    {
        modbus_close(_connector);
        ui->groupBox->setEnabled(false);
    }
}


void MainWindow::on_pbOut1_clicked()
{
    modbus_write_register(_connector, 8, ui->pbOut1->isChecked()?1:0);
}


void MainWindow::on_pbOut2_clicked()
{
    modbus_write_register(_connector, 9, ui->pbOut2->isChecked()?1:0);
}


void MainWindow::on_pbOut3_clicked()
{
    modbus_write_register(_connector, 10, ui->pbOut3->isChecked()?1:0);
}

