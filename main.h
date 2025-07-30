#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>
#include <QTimer>
#include <QSoundEffect>

QT_BEGIN_NAMESPACE
namespace Ui {
class Main;
}
QT_END_NAMESPACE

class Main : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main(QWidget *parent = nullptr);
    ~Main();

    QString GetFormattedTime(const uint8_t inTime);
private slots:
    void TimerCountdown();

    void OnTimerFinished();

private:
    Ui::Main *ui;
    QTimer* timer;
    QSoundEffect* timerEndSound;
    uint16_t m_CurrentTime;
};
#endif // MAIN_H
