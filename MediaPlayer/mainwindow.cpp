#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMultimedia>
#include <QMediaPlayer>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);

    connect(player, &QMediaPlayer::positionChanged,this, &MainWindow::on_position_changed);
    connect(player, &QMediaPlayer::durationChanged,this, &MainWindow::on_duration_changed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_volumeSlider_sliderMoved(int position)
{
    player->setVolume(position);
}


void MainWindow::on_progressSlider_sliderMoved(int position)
{
    player->setPosition(position);
}


void MainWindow::on_start_Button_clicked()
{
    player->setMedia(QUrl::fromLocalFile("/home/nicolae/QtProjects/MediaPlayer/IDK _URBANIST SESSIONS.mp3"));
    player->play();
    ui->label_nameMusic->setText("IDK URBANIST SESSIONS");
    qDebug() << player->errorString();
}


void MainWindow::on_stop_Button_clicked()
{
    player->stop();
}

void MainWindow::on_position_changed(qint64 position)
{
    ui->progressSlider->setValue(position);
}

void MainWindow::on_duration_changed(qint64 position)
{
    ui->progressSlider->setMaximum(position);
}

