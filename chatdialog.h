#ifndef CHATDIALOG_H
#define CHATDIALOG_H
/******************************************************************************
 *
 * @file       chatdialog.h
 * @brief      聊天界面
 *
 * @author     XiaoYu
 * @date       2024/09/11
 * @history
 *****************************************************************************/
#include <QDialog>

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();

private:
    Ui::ChatDialog *ui;
};

#endif // CHATDIALOG_H
