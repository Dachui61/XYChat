#include "registerdialog.h"
#include "global.h"
#include "ui_registerdialog.h"
#include "httpmgr.h"

registerDialog::registerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerDialog)
{
    ui->setupUi(this);
    // ui->logolabel->adjustSize();
    ui->pass_edit->setEchoMode(QLineEdit::Password);
    ui->confirm_edit->setEchoMode(QLineEdit::Password);
    ui->err_tip->setProperty("state", "normal");
    repolish(ui->err_tip);

    connect(HttpMgr::GetInstance().get(), &HttpMgr::sig_reg_mod_finish, this, &registerDialog::slot_reg_mod_finish);
}

registerDialog::~registerDialog()
{
    delete ui;
}

void registerDialog::initHttpHandlers()
{
    //注册获取验证码回包逻辑
    _handlers.insert(ReqId::ID_GET_VARIFY_CODE, [this](QJsonObject jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS){
            showTip(tr("参数错误"),false);
            return;
        }
        auto email = jsonObj["email"].toString();
        showTip(tr("验证码已发送到邮箱，注意查收"), true);
        qDebug()<< "email is " << email ;
    });
}


void registerDialog::on_get_code_btn_clicked()
{
    auto email = ui->mail_edit->text();
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch();
    if(match){
        //发送验证码 post请求服务器
        QJsonObject json_obj;
        json_obj["email"] = email;
        HttpMgr::GetInstance()->PostHttpReq(QUrl(gate_url_prefix + "/get_verifycode"),json_obj , ReqId::ID_GET_VARIFY_CODE , Modules::REGISTERMOD);

    }else{
        showTip(tr("邮箱地址不正确"), false);
    }
}

void registerDialog::slot_reg_mod_finish(ReqId id, QString res, ErrorCodes code)
{
    //注册请求成功 返回异常结果
    if(code != ErrorCodes::SUCCESS){
        showTip(tr("网络请求异常"),false);
        return;
    }

    //返回正确的结果 解析Json
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    if(jsonDoc.isNull() || !jsonDoc.isObject()){
        //解析异常
        showTip(tr("json解析错误"),false);
        return;
    }
    QJsonObject jsonObj = jsonDoc.object();

    _handlers[id](jsonDoc.object());
    return;
}

void registerDialog::showTip(QString meg , bool b_ok){
    if(b_ok){
        ui->err_tip->setProperty("state","normal");
    }else{
        ui->err_tip->setProperty("state","err");
    }
    ui->err_tip->setText(meg);
    repolish(ui->err_tip);
}
