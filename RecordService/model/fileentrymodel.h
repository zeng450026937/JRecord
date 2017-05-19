#ifndef FILEENTRYMODEL_H
#define FILEENTRYMODEL_H

#include <QAbstractListModel>

class FileEntryModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit FileEntryModel(QObject *parent = 0);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // return the roles mapping to be used by QML
    virtual QHash<int, QByteArray> roleNames() const override;

private:
    QVariantList m_datas;
    QHash<int, QByteArray> m_roleNames;
};

#endif // FILEENTRYMODEL_H
