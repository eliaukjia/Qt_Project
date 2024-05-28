#include "designdialog.h"
#include "ui_designdialog.h"
#include <QStandardItemModel>

DesignDialog::DesignDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DesignDialog)
{
    ui->setupUi(this);

    contentModel = new QStandardItemModel();
    contentModel->setColumnCount(12);


    for(int i=0;i<12;i++)
    {
        for(int j=0;j<12;j++)
        {
            QString p  =QString::number(j+1);
            contentModel->setHeaderData(j,Qt::Horizontal,"Port "+p);

            contentModel->setItem(i,j,new QStandardItem("Enable!"));
        }
        QString p = QString::number(i+1);
        contentModel->setHeaderData(i,Qt::Vertical,"Port "+p);
    }

    ui->tableView->setModel(contentModel);
}

DesignDialog::~DesignDialog()
{
    delete ui;
}


void DesignDialog::on_sbx_incount_valueChanged(int arg1)
{
    qint32 rowCount = ui->sbx_incount->value();

    int32_t  originRow = contentModel->rowCount();
    int32_t originColumn = contentModel->columnCount();

    contentModel->removeRows(0,originRow);

    for(int i=0;i<rowCount;i++)
    {
        for(int j=0;j<originColumn;j++)
        {
            contentModel->setItem(i,j,new QStandardItem("Disable!"));
        }
    }
}
