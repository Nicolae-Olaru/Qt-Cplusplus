#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->entrateBox->setEnabled(false);
    ui->usciteBox->setEnabled(false);

    // Loading Panel First Time
    QPixmap off("/home/nicolae/QtProjects/PLC/Icons/amber-off-16.png");
    QPixmap on("/home/nicolae/QtProjects/PLC/Icons/green-on-16.png");
    ui->labelEN0->setPixmap(off);
    ui->labelEN1->setPixmap(off);
    ui->labelEN2->setPixmap(off);
    ui->labelEN3->setPixmap(off);
    ui->labelEN4->setPixmap(off);
    ui->labelEN5->setPixmap(off);
    ui->labelEN6->setPixmap(off);
    ui->labelEN7->setPixmap(off);

}

MainWindow::~MainWindow()
{
    this->maintain->terminate();
    delete ui;
}

void MainWindow::updateGUI(QPixmap on, QPixmap off)
{
    //START Fase di Update interfaccia!

    if( this->m_io.inputs[0] == 0 )
        ui->labelEN0->setPixmap(off);
    else
        ui->labelEN0->setPixmap(on);


    // Bottone 1 IN
    if( this->m_io.inputs[1] == 0 )
        ui->labelEN1->setPixmap(off);
    else
        ui->labelEN1->setPixmap(on);


    // Bottone 2 IN
    if( this->m_io.inputs[2] == 0 )
        ui->labelEN2->setPixmap(off);
    else
        ui->labelEN2->setPixmap(on);

    // Bottone 3   IN
    if( this->m_io.inputs[3] == 0 )
        ui->labelEN3->setPixmap(off);
    else
        ui->labelEN3->setPixmap(on);

    // Bottone 4   IN
    if( this->m_io.inputs[4] == 0 )
        ui->labelEN4->setPixmap(off);
    else
        ui->labelEN4->setPixmap(on);

    // Bottone 5     IN
    if( this->m_io.inputs[5] == 0 )
        ui->labelEN5->setPixmap(off);
    else
        ui->labelEN5->setPixmap(on);

    // Bottone 6     IN
    if( this->m_io.inputs[6] == 0 )
        ui->labelEN6->setPixmap(off);
    else
        ui->labelEN6->setPixmap(on);;

    // Bottone 7
    if( this->m_io.inputs[7] == 0 )
        ui->labelEN7->setPixmap(off);
    else
        ui->labelEN7->setPixmap(on);
    //----------------------------------OUT------------------------------------------

    // Bottone 0 OUT
    if( this->m_io.outputs[0] == 0 )
    {
        //ui->pb_U0->blockSignals(true);
        ui->pb_U0->setChecked(false);
        //ui->pb_U0->blockSignals(false);
    }
    else
    {
        //ui->pb_U0->blockSignals(true);
        ui->pb_U0->setChecked(true);
        //ui->pb_U0->blockSignals(false);
    }

    // Bottone 1 OUT
    if( this->m_io.outputs[1] == 0 )
    {
        //ui->pb_U1->blockSignals(true);
        ui->pb_U1->setChecked(false);
        //ui->pb_U1->blockSignals(false);
    }
    else
    {
        //ui->pb_U1->blockSignals(true);
        ui->pb_U1->setChecked(true);
        //ui->pb_U1->blockSignals(false);
    }

    // Bottone 2 OUT
    if( this->m_io.outputs[2] == 0 )
        ui->pb_U2->setChecked(false);
    else
        ui->pb_U2->setChecked(true);


    // Bottone 3 OUT
    if( this->m_io.outputs[3] == 0 )
        ui->pb_U3->setChecked(false);
    else
        ui->pb_U3->setChecked(true);


    // Bottone 4 OUT
    if( this->m_io.outputs[4] == 0 )
        ui->pb_U4->setChecked(false);
    else
        ui->pb_U4->setChecked(true);

    // Bottone 5 OUT
    if( this->m_io.outputs[5] == 0 )
        ui->pb_U5->setChecked(false);
    else
        ui->pb_U5->setChecked(true);
}

void MainWindow::maintain_status_alive(){

    while( true )
    {
        QPixmap off("/home/nicolae/QtProjects/PLC/Icons/amber-off-16.png");
        QPixmap on("/home/nicolae/QtProjects/PLC/Icons/green-on-16.png");

        //START Fase di caricamnento bottoni!
        int i = 0;
        while(i < N_INPUTS)
        {
            plc.read_register_in(i + 0, &m_io.inputs[i]);
            i++;
        }
        i=0;
        while(i < N_OUTPUTS)
        {
            plc.read_register_in((i + N_INPUTS), &m_io.outputs[i]);
            i++;
        }
        updateGUI(on, off);
        QThread::msleep(200);
    }
};




// Button Connect
void MainWindow::on_connectButton_clicked()
{
    QString ip = ui->lineEdit->text();
    plc.setIP(ip);
    plc.setPORT(502);
    if(plc.connect() == 1)
    {
        // Disable buttons because connected!!!!!!!!!!!!!
        ui->statusConnectionLabel->setText("Connection Successfull!");
        ui->entrateBox->setEnabled(true);
        ui->usciteBox->setEnabled(true);
        ui->connectButton->setEnabled(false);
        qDebug() << "Tutto apposto con la connessione";

       //Start Thread
        this->maintain = QThread::create([this]{MainWindow::maintain_status_alive();});
        this->maintain->start();
    }
    else
    ui->statusConnectionLabel->setText("Unable to connect!");

}


void MainWindow::on_disconnectButton_clicked()
{
    ui->entrateBox->setEnabled(false);
    ui->usciteBox->setEnabled(false);
    plc.disconnect();
    ui->connectButton->setEnabled(true);
    ui->statusConnectionLabel->setText("Disconnected");
}

// OUTTTTTTTTT BUTTONSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS

void MainWindow::on_pb_U0_clicked()
{
    plc.write_register(8, ui->pb_U0->isChecked()?1:0);
}


void MainWindow::on_pb_U1_clicked()
{
    plc.write_register(9, ui->pb_U1->isChecked()?1:0);
}


void MainWindow::on_pb_U2_clicked()
{
    plc.write_register(10, ui->pb_U2->isChecked()?1:0);
}


void MainWindow::on_pb_U3_clicked()
{
    plc.write_register(11, ui->pb_U3->isChecked()?1:0);
}


void MainWindow::on_pb_U4_clicked()
{
    plc.write_register(12, ui->pb_U4->isChecked()?1:0);
}


void MainWindow::on_pb_U5_clicked()
{
    plc.write_register(13, ui->pb_U5->isChecked()?1:0);
}

