#ifndef DESIGNDIALOG_H
#define DESIGNDIALOG_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class DesignDialog;
}

class DesignDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DesignDialog(QWidget *parent = nullptr);
    ~DesignDialog();

private slots:
    void on_sbx_incount_valueChanged(int arg1);

private:
    Ui::DesignDialog *ui;
    QStandardItemModel *contentModel ;
};

#endif // DESIGNDIALOG_H
