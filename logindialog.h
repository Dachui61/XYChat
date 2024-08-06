#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
/******************************************************************************
 *
 * @file       logindialog.h
 * @brief      登录界面
 *
 * @author     XiaoYu
 * @date       2024/07/30
 * @history
 *****************************************************************************/
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private:
    Ui::LoginDialog *ui;

signals:
    void switchRegister();
};

#endif // LOGINDIALOG_H
