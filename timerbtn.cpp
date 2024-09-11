#include "timerbtn.h"
/******************************************************************************
 *
 * @file       timerbtn.cpp
 * @brief      定时按钮，用于发出请求验证码功能
 *
 * @author     XiaoYu
 * @date       2024/08/21
 * @history
 *****************************************************************************/


TimerBtn::TimerBtn(QWidget *parent):QPushButton(parent),_count(30)
{
    _timer = new QTimer(this);

    connect(_timer, &QTimer::timeout, [this](){
        _count--;
        if(_count <= 0 ){
            _timer->stop();
            _count = 10;
            this->setText("获取");
            this->setEnabled(true);
            return;
        }
        this->setText("("+QString::number(_count)+")s");
    });
}

TimerBtn::~TimerBtn()
{
    _timer->stop();
}

void TimerBtn::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        qDebug() << "LeftMouseButton Release";
        this->setEnabled(false);
        this->setText("("+QString::number(_count)+")s");
        _timer->start(1000);
        emit click();
    }
    QPushButton::mouseMoveEvent(e);
}
