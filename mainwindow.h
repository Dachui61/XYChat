#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <logindialog.h>
#include "chatdialog.h"
#include "registerdialog.h"
/******************************************************************************
 *
 * @file       mainwindow.h
 * @brief      主界面
 *
 * @author     XiaoYu
 * @date       2024/07/30
 * @history
 *****************************************************************************/
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    LoginDialog * _login_dialog;
    registerDialog * _register_dialog;
    ChatDialog * _chat_dialog;

public slots:
    void SlotSwitchReg();
    void SlotSwitchChat();
};
#endif // MAINWINDOW_H
