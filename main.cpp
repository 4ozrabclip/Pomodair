#include "main.h"
#include "ui_main.h"
#include <QDebug>
#include <QTime>
#include <QUrl>


Main::Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Main)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(1000);

    timerEndSound = new QSoundEffect(this);
    timerEndSound->setSource(QUrl(":/sounds/timer-end.wav"));


    m_CurrentTime = 10;

    ui->TimerDisplay_Label->setText(GetFormattedTime(m_CurrentTime));

    connect(timer, &QTimer::timeout, this, &Main::TimerCountdown);
    connect(ui->StartTimer_Button, &QPushButton::clicked, this, [this]() {
        timer->start();
    });

}

QString Main::GetFormattedTime(const uint8_t inTime)
{
    QTime Time(0,0,0);
    Time = Time.addSecs(inTime);
    return (Time.toString("mm:ss"));
}

Main::~Main()
{
    delete ui;
    delete timer;
    delete timerEndSound;
}

void Main::TimerCountdown()
{
    m_CurrentTime--;

    if (m_CurrentTime == 0)
    {
        OnTimerFinished();
    }

    ui->TimerDisplay_Label->setText(GetFormattedTime(m_CurrentTime));
}
void Main::OnTimerFinished()
{
    timer->stop();
    if (!timerEndSound->isLoaded())
    {
        qDebug() << "Timer end sound not loaded";
        return;
    }

    timerEndSound->play();

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Main w;
    w.show();
    return a.exec();
}
