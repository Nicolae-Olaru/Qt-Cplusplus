#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ModbusClass.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

static const int N_INPUTS = 8;
static const int N_OUTPUTS = 6;
typedef struct _signals {
    uint16_t inputs[N_INPUTS];
    uint32_t inputAddrOffset;
    uint16_t outputs[N_OUTPUTS];
    uint32_t outputAddrOffset;
} io;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateGUI(QPixmap on, QPixmap off);

private slots:
    void on_connectButton_clicked();

    void on_disconnectButton_clicked();

    void on_pb_U0_clicked();

    void on_pb_U1_clicked();

    void on_pb_U2_clicked();

    void on_pb_U3_clicked();

    void on_pb_U4_clicked();

    void on_pb_U5_clicked();

    void maintain_status_alive();

private:
    Ui::MainWindow *ui;
    ModbusClass plc;
    QThread *maintain= nullptr;

    io m_io;
};
#endif // MAINWINDOW_H
