#ifndef USER_MODEL_H
#define USER_MODEL_H

#include <QSqlTableModel>

class UserModel : public QSqlTableModel
{
    Q_OBJECT
public:
    explicit UserModel(QObject *parent = 0);

signals:

public slots:
};

#endif // USER_MODEL_H
