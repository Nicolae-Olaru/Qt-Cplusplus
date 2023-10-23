#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <modbus/modbus.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbConn_clicked();

    void on_pbDisconn_clicked();

    void on_pbOut1_clicked();

    void on_pbOut2_clicked();

    void on_pbOut3_clicked();

private:
    Ui::MainWindow *ui;
    modbus_t *_connector=nullptr;
};
#endif // MAINWINDOW_H
