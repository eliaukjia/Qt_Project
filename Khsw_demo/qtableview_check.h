#ifndef QTABLEVIEW_CHECK_H
#define QTABLEVIEW_CHECK_H

#include <QtWidgets>
#include <QAbstractTableModel>

class qtableview_check: public QAbstractTableModel
{
    Q_OBJECT
public:
    qtableview_check(QObject *parent);
    ~qtableview_check();

    // 更新表格数据
    //void updateData(QList<File)
};

class qtableview_combox: public QAbstractTableModel
{
    Q_OBJECT
public:
    qtableview_combox(QObject *parent);
    ~qtableview_combox();
};

#endif // QTABLEVIEW_CHECK_H
