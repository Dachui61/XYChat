#include "httpmgr.h"

HttpMgr::HttpMgr() {



    connect(this , &HttpMgr::sig_http_finish, &HttpMgr::slot_http_finish);
}

//ReqId req_id, Modules mod为了实现消息透传 知道消息是从哪里来的
void HttpMgr::PostHttpReq(QUrl url, QJsonObject json, ReqId req_id, Modules mod)
{
    //创建一个POST请求
    QByteArray data = QJsonDocument(json).toJson();

    //构造请求
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));

    auto self = shared_from_this();

    QNetworkReply* reply = _manager.post(request,data);

    connect(reply , &QNetworkReply::finished , [reply , self , req_id, mod](){
        if(reply->error() != QNetworkReply::NoError){
            //处理错误情况
            qDebug() << reply->errorString();
            //发送信号通知完成
            emit self->sig_http_finish(req_id , "", ErrorCodes::ERR_NETWORK , mod);
            reply->deleteLater();
            return;
        }
        QString data = reply->readAll();
        //发送信号通知完成
        emit self->sig_http_finish(req_id , data, ErrorCodes::SUCCESS , mod);
        reply->deleteLater();
        return;

    });
}

void HttpMgr::slot_http_finish(ReqId id, QString res, ErrorCodes code, Modules m)
{
    if(m == Modules::REGISTERMOD){
        emit sig_reg_mod_finish(id, res, code);
    }
}

HttpMgr::~HttpMgr()
{

}
