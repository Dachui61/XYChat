#ifndef TIMERBTN_H
#define TIMERBTN_H
/******************************************************************************
 *
 * @file       timerbtn.cpp
 * @brief      定时按钮，用于发出请求验证码功能
 *
 * @author     XiaoYu
 * @date       2024/08/21
 * @history
 *****************************************************************************/
#include <QPushButton>
#include <QTimer>
#include <QMouseEvent>


class TimerBtn:public QPushButton
{
public:
    TimerBtn(QWidget *parent = nullptr);
    ~ TimerBtn();

    virtual void mouseReleaseEvent(QMouseEvent *e) override;
private:
    QTimer *_timer;
    int _count;
};

#endif // TIMERBTN_H
