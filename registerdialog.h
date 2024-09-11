#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "global.h"

/******************************************************************************
 *
 * @file       registerdialog.h
 * @brief      注册界面
 *
 * @author     XiaoYu
 * @date       2024/07/30
 * @history
 *****************************************************************************/
namespace Ui {
class registerDialog;
}

class registerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit registerDialog(QWidget *parent = nullptr);
    ~registerDialog();
    void initHttpHandlers();

private slots:
    void on_get_code_btn_clicked();
    void slot_reg_mod_finish(ReqId id,QString res, ErrorCodes code);

    void on_sure_btn_clicked();

private:
    void showTip(QString meg , bool b_ok);
    Ui::registerDialog *ui;
    QMap<ReqId, std::function<void(const QJsonObject&)>> _handlers;

};

#endif // REGISTERDIALOG_H
