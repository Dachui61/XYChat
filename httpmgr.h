#ifndef HTTPMGR_H
#define HTTPMGR_H
#include "singleton.h"
#include "global.h"
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>

/******************************************************************************
 *
 * @file       httpmgr.h
 * @brief      HTTP请求管理类
 *
 * @version    1.0
 * @author     XiaoYu
 * @date       2024/08/01
 * @history
 *              - 2024/08/01: 创建文件，XiaoYu
 *****************************************************************************/

class HttpMgr:public QObject , public Singleton<HttpMgr> , public std::enable_shared_from_this<HttpMgr>
{
    Q_OBJECT
public:
    ~HttpMgr();
    void PostHttpReq(QUrl url, QJsonObject json, ReqId req_id, Modules mod);

private:
    friend class Singleton<HttpMgr>;
    HttpMgr();
    QNetworkAccessManager _manager;

private slots:
    void slot_http_finish(ReqId id, QString res, ErrorCodes code, Modules m);

signals:
    void sig_http_finish(ReqId id, QString res, ErrorCodes code, Modules m);
    void sig_reg_mod_finish(ReqId id,QString res, ErrorCodes code);
};

#endif // HTTPMGR_H
