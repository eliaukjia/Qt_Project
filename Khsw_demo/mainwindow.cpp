#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include "designdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    isUntitled = true;
    curFile="未命名.txt";
    setWindowTitle(curFile);

    scpiServer = new QTcpServer(this);

    if(!scpiServer->listen(QHostAddress::LocalHost,6666))
    {
        qDebug()<<scpiServer->errorString();
        close();
    }

    connect(scpiServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));

    newWords<<"apple"<<"abondon"<<"banana"<<"basakar"<<"data"<<"date";
    completer = new QCompleter(newWords,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    ui->le_command->setCompleter(completer);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QDialog *dialog= new QDialog(this);
    dialog->show();
}

void MainWindow::createProject()
{
    if (maySave()) {
        isUntitled = true;
        curFile = tr("未命名.txt");
        setWindowTitle(curFile);
        ui->textEdit->clear();
        ui->textEdit->setVisible(true);
    }
}

bool MainWindow::maySave()
{
    // 如果文档被更改了
    if (ui->textEdit->document()->isModified()) {
        // 自定义一个警告对话框
        QMessageBox box;
        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile + tr(" 尚未保存，是否保存？"));
        QPushButton *yesBtn = box.addButton(tr("是(&Y)"),
                                            QMessageBox::YesRole);
        box.addButton(tr("否(&N)"), QMessageBox::NoRole);
        QPushButton *cancelBut = box.addButton(tr("取消"),
                                               QMessageBox::RejectRole);
        box.exec();
        if (box.clickedButton() == yesBtn)
            return save();
        else if (box.clickedButton() == cancelBut)
            return false;
    }
    // 如果文档没有被更改，则直接返回true
    return true;
}

bool MainWindow::save()
{
    if (isUntitled) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("另存为"),curFile);
    if (fileName.isEmpty()) return false;
    return saveFile(fileName);
}

bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {

        // %1和%2分别对应后面arg两个参数，/n起换行的作用
        QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法写入文件 %1：/n %2")
                             .arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    // 鼠标指针变为等待状态
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << ui->textEdit->toPlainText();
    // 鼠标指针恢复原来的状态
    QApplication::restoreOverrideCursor();
    isUntitled = false;
    // 获得文件的标准路径
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

void MainWindow:: sendMessage()
{
    //用于暂存我们要发送的数据
    QByteArray block;

    //使用数据流写入数据
    QDataStream out(&block,QIODevice::WriteOnly);

    //设置数据流的版本，客户端和服务器端使用的版本要相同
    out.setVersion(QDataStream::Qt_4_6);

    out<<(quint16) 0;
    out<<tr("hello Tcp!!!");
    out.device()->seek(0);
    out<<(quint16) (block.size() - sizeof(quint16));

    //我们获取已经建立的连接的子套接字
    QTcpSocket *clientConnection = scpiServer->nextPendingConnection();

    connect(clientConnection,SIGNAL(disconnected()),clientConnection,
            SLOT(deleteLater()));
    clientConnection->write(block);
    clientConnection->disconnectFromHost();

    //发送数据成功后，显示提示
    ui->statusLabel->setText("send message successful!!!");
}

void MainWindow::on_action_link_triggered()
{
    sendMessage();
}

void MainWindow::on_action_Create_triggered()
{
    DesignDialog  *design = new DesignDialog();
    design->show();
}
