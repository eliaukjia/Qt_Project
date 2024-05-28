#ifndef GRID_CHECK_DELEGATE_H
#define GRID_CHECK_DELEGATE_H

#include <QItemDelegate>
#include <QWidget>

class grid_check_delegate:public QItemDelegate
{
    Q_OBJECT
public:
    grid_check_delegate(QObject *parent = 0);

    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option,const QModelIndex &index) const;
};

#endif // GRID_CHECK_DELEGATE_H
