#include "fileentrymodel.h"

FileEntryModel::FileEntryModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

QVariant FileEntryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    return QAbstractListModel::headerData(section, orientation, role);
}

int FileEntryModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return m_datas.count();
}

QVariant FileEntryModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}

QHash<int, QByteArray> FileEntryModel::roleNames() const
{
    return m_roleNames;
}
