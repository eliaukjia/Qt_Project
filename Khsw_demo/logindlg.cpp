#include "logindlg.h"
#include "ui_logindlg.h"
#include <QtWidgets>
#include <windows.h>

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{

    ui->setupUi(this);
    setWindowTitle("登录");

    ui->le_usr->setPlaceholderText("请输入用户名");
    ui->le_pwd-> setEchoMode(QLineEdit::Password);
    ui->le_pwd->setPlaceholderText("请输入密码");
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::on_btn_login_clicked()
{
    if(ui->le_usr->text().trimmed()=="zlf" && ui->le_pwd->text()=="admin")
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this,"Warning","usr name or password error!",QMessageBox::Yes);

        ui->le_usr->clear();
        ui->le_pwd->clear();
        ui->le_usr->setFocus();
    }
}


