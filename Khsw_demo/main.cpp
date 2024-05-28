#include "mainwindow.h"
#include "logindlg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    LoginDlg dialog;
    if(dialog.exec()== QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else
    {
        return 0;
    }
}
