#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "data.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void fillData();

private slots:
    //void on_listWidget_indexesMoved(const QModelIndexList &indexes);
    void load_and_show_data_on_list();

private:
    Ui::MainWindow *ui;
    QList<inform_t> _list;


    /*
    inform lista_nomi[7] =
        {
            {"Olaru","Nicolae", 1500},
            {"Marco","Rossi", 2000},
            {"Federico","Bianchi",1200},
            {"Haid","Mohamed", 1550},
            {"Anna","Gianluca",1000},
            {"Rocco","Frank",3000},
            {"Bianchi","Luca",2800}
        };
*/
};
#endif // MAINWINDOW_H
