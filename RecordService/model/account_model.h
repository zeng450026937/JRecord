#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H

#include <QSqlQueryModel>

class AccountModel : public QSqlQueryModel
{
    Q_OBJECT

public:
    explicit AccountModel(QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QHash<int, QByteArray> m_roleNames;
};

#endif // ACCOUNTMODEL_H
