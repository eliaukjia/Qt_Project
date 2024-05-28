#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QCompleter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //  新建
    void createProject();
    // 判断是否需要保存
    bool maySave();
    // 保存操作
    bool save();
    //  保存
    bool saveAs();
    //  保存文件
    bool saveFile(const QString &fileName);

private slots:
    void on_pushButton_clicked();

    void on_action_link_triggered();

    void sendMessage();

    void on_action_Create_triggered();

private:
    Ui::MainWindow *ui;
    // 为真表示文件没有保存过，为假表示文件已经被保存过了
    bool isUntitled;
    // 保存当前文件的路径
    QString curFile;
    // tcp server
    QTcpServer *scpiServer;

    QStringList newWords;

    QCompleter *completer;
};
#endif // MAINWINDOW_H
