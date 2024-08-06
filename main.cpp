#include "mainwindow.h"
#include "global.h"
#include <QApplication>

/******************************************************************************
 *
 * @file       main.cpp
 * @brief      main Function
 *
 * @author     XiaoYu
 * @date       2024/07/30
 * @history
 *****************************************************************************/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 设置应用程序图标


    QIcon appIcon(":/rec/chat.png");
    a.setWindowIcon(appIcon);
    QFile qss(":/style/stylesheet.qss");
    if(qss.open(QFile::ReadOnly)){
        qDebug("open success");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }else{
        qDebug("open failed");
    }

    QString app_path = QCoreApplication::applicationDirPath();

    QString filename = "config.ini";
    QString config_path = QDir::toNativeSeparators( app_path + QDir::separator() + filename ) ;
    QSettings setting(config_path , QSettings::IniFormat);
    QString gate_host = setting.value("GateServer/host").toString();
    QString gate_port = setting.value("GateServer/port").toString();
    gate_url_prefix = "http://" + gate_host + ":" + gate_port;

    MainWindow w;
    w.setWindowIcon(appIcon);
    w.show();
    return a.exec();
}
