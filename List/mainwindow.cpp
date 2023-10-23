#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QModelIndexList>
#include <QString>
#include <QListWidgetItem>
#include <QFont>
#include "data.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
#if 0
    //ui->pushButton->setIcon(QIcon("673483.png"));
    try {
        ui->pushButton->setIcon(QIcon("/home/nicolae/One/673483.png"));
    } catch (const std::exception& e) {
        qDebug() << "Error setting icon: " << e.what();
    }
#else
    ui->pushButton->setIcon(QIcon(QPixmap(":ingranaggio")));
#endif


    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(load_and_show_data_on_list()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//#define GET_VALUE(VALUE) ListManager->instance()->getValue(VALUE)

void MainWindow::fillData()
{
//    inform lista_nomi[NUM_ELEMENTI] = {
//        {"Olaru", "Nicolae", 1500},
//        {"Marco", "Rossi", 2000},
//        {"Federico", "Bianchi", 1200},
//        {"Haid", "Mohamed", 1550},
//        {"Anna", "Gianluca", 1000},
//        {"Rocco", "Frank", 3000},
//        {"Bianchi", "Luca", 2800}
//    };

    _list.clear();

    _list << inform("Olaru", "Nicolae", 1500);
    _list << inform("Marco", "Rossi", 2000);
    _list << inform("Haid", "Mohamed", 1550);
    _list << inform("Rocco", "Frank", 3000);
}

void MainWindow::load_and_show_data_on_list() {
    // Clear the listWidget to start fresh



    ui->listWidget->clear();

    // Your array of name, surname, and numbers





#if 0
    const int NUM_ELEMENTI = 7;
    for (int i = 0; i < NUM_ELEMENTI; ++i) {
        QListWidgetItem* item = new QListWidgetItem(ui->listWidget);

        // Create a custom widget to represent each item with separate columns
        QWidget* customWidget = new QWidget(ui->listWidget);
        QHBoxLayout* layout = new QHBoxLayout(customWidget);


        QLabel* nameLabel = new QLabel(lista_nomi[i].nome);
        QLabel* surnameLabel = new QLabel(lista_nomi[i].cognome);

        QLabel* numberLabel = new QLabel(QString::number(lista_nomi[i].stipendio));

        layout->addWidget(nameLabel);
        layout->addWidget(surnameLabel);
        layout->addWidget(numberLabel);


        customWidget->setLayout(layout);

        // Set the custom widget as the item's widget
        item->setSizeHint(customWidget->sizeHint());
        ui->listWidget->setItemWidget(item, customWidget);
    }
#else


    fillData();//fai finta che questa sia una query ad un DB

    foreach (inform_t element, _list)
    {
        // QTableWidget
        QListWidgetItem* item = new QListWidgetItem(ui->listWidget);

        // Create a custom widget to represent each item with separate columns
        QWidget* customWidget = new QWidget(ui->listWidget);
        QHBoxLayout* layout = new QHBoxLayout(customWidget);


        QLabel* nameLabel = new QLabel(element.nome);
        QLabel* surnameLabel = new QLabel(element.cognome);
        QLabel* numberLabel = new QLabel(QString::number(element.stipendio));

        layout->addWidget(nameLabel);
        layout->addWidget(surnameLabel);
        layout->addWidget(numberLabel);


        customWidget->setLayout(layout);

        // Set the custom widget as the item's widget
        item->setSizeHint(customWidget->sizeHint());
        ui->listWidget->setItemWidget(item, customWidget);
    }


    //TODO: suddividere la funzione sopra in due funzioni:
    //     - initTable(); //<< qui ti prepari le colonne e il QTableWidget
    //     - fillTable(<my_type> my_list); //<< ti fai il riempimento della QTableWidget con i QTableWidgetItems

#endif


}
