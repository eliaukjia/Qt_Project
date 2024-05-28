#include "grid_check_delegate.h"
#include <QCheckBox>

grid_check_delegate::grid_check_delegate(QObject *parent):QItemDelegate(parent)
{

}

QWidget *grid_check_delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QCheckBox *editor = new QCheckBox();
    editor->installEventFilter(const_cast<grid_check_delegate*>(this));
    return editor;
}

void   grid_check_delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(!index.isValid())
        return;
}

void grid_check_delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{

}

void grid_check_delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

}
