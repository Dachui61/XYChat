#ifndef GLOBAL_H
#define GLOBAL_H
#include <QWidget>
#include <functional>
#include <QRegularExpression>
#include "QStyle"
#include <memory>
#include <iostream>
#include <mutex>
#include <QJsonObject>
#include <QFile>
#include <QDir>
#include <QSettings>

/******************************************************************************
 *
 * @file       global.h
 * @brief      常用的头文件，全局引用
 *
 * @author     XiaoYu
 * @date       2024/07/31
 * @history
 *****************************************************************************/
extern std::function<void (QWidget *)> repolish;


enum ReqId{
    ID_GET_VARIFY_CODE = 1001, // 获取验证码
    ID_REG_USER = 1002, // 注册用户
};

enum ErrorCodes{
    SUCCESS = 0,
    ERR_JSON = 1,
    ERR_NETWORK = 2,
};

enum Modules{
    REGISTERMOD = 0, //注册模块
};

extern QString gate_url_prefix;

#endif // GLOBAL_H
