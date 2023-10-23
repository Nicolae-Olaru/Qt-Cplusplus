#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmediaplayer.h"
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

private slots:
    void on_volumeSlider_sliderMoved(int position);

    void on_progressSlider_sliderMoved(int position);

    void on_start_Button_clicked();

    void on_stop_Button_clicked();

    void on_position_changed(qint64 position);

    void on_duration_changed(qint64 position);


private:
    Ui::MainWindow *ui;
    QMediaPlayer *player = nullptr;
};
#endif // MAINWINDOW_H
