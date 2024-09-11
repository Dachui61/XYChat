#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("XYChat");
    _login_dialog = new LoginDialog(this);
    setCentralWidget(_login_dialog);
    // _login_dialog->show();

    //注册消息连接
    connect(_login_dialog , &LoginDialog::switchRegister, this , &MainWindow::SlotSwitchReg);
    _register_dialog = new registerDialog(this);
    _chat_dialog = new ChatDialog(this);

    _login_dialog->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    _register_dialog->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    _chat_dialog->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    //Test 展示设置为Chatdialog
    setCentralWidget(_chat_dialog);
}

MainWindow::~MainWindow()
{
    delete ui;
    // if(_login_dialog){
    //     delete _login_dialog;
    //     _login_dialog = nullptr;
    // }
    // if(_register_dialog){
    //     delete _register_dialog;
    //     _register_dialog = nullptr;
    // }
}

void MainWindow::SlotSwitchReg()
{
    setCentralWidget(_register_dialog);
    _login_dialog->hide();
    _chat_dialog->hide();
    _register_dialog->show();
}

void MainWindow::SlotSwitchChat()
{
    setCentralWidget(_chat_dialog);
    _login_dialog->hide();
    _register_dialog->hide();
    _chat_dialog->show();
}
