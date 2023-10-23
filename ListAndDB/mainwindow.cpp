#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DB_manipulation.h"
#include <QListView>
#include <QGridLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Connect Button pushButton
void MainWindow::on_pushButton_clicked()
{
    DB_manipulation my_connect("127.0.0.1",3306,"QMYSQL","data","root","password");
    if ( my_connect.check_db_connection() )
    {
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->label->setText("Connected!");
    }
    else
    {
        ui->label->setText("Unable to connect to the DB");
    }
}

//Disconnect Button pushButton_2
void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->label->setText("Disconnected");
}


void MainWindow::on_pushButton_3_clicked()
{
    DB_manipulation my_connect("127.0.0.1",3306,"QMYSQL","data","root","password");
    if ( ! my_connect.check_db_connection() )
    {
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->label->setText("Fatal Error on DB connect!!!!!");
    }
    QTableWidget *table = ui->tableWidget;
    int dim = my_connect.max_rows();
    data_t data[dim];
    my_connect.extract_data_all(&data[dim]);

    int rows = my_connect.max_rows();
    int xv = 1;





    table->setRowCount(rows);
    table->setColumnCount(5);

    QTableWidgetItem *id = new QTableWidgetItem("");
    table->setItem(xv,0,id);
    QTableWidgetItem *name = new QTableWidgetItem("Name");
    table->setItem(xv,1,name);
    QTableWidgetItem *surname = new QTableWidgetItem("Surname");
    table->setItem(xv,2,surname);
    QTableWidgetItem *type = new QTableWidgetItem("Car type");
    table->setItem(xv,3,type);
    QTableWidgetItem *cilindrata = new QTableWidgetItem("Cilindrata");
    table->setItem(xv,4,cilindrata);

    foreach (data_t x, data) {
        QTableWidgetItem *id = new QTableWidgetItem(x.id);
        table->setItem(xv,0,id);
        QTableWidgetItem *name = new QTableWidgetItem(x.nome);
        table->setItem(xv,1,name);
        QTableWidgetItem *surname = new QTableWidgetItem(x.nome);
        table->setItem(xv,2,surname);
        QTableWidgetItem *type = new QTableWidgetItem(x.nome);
        table->setItem(xv,3,type);
        QTableWidgetItem *cilindrata = new QTableWidgetItem(x.nome);
        table->setItem(xv,4,cilindrata);
        xv++;
    }

}

