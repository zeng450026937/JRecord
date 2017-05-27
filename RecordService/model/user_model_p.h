#ifndef USER_MODEL_P_H
#define USER_MODEL_P_H

#include <QObject>
#include <QHash>

class UserModel;

class UserModelPrivate
{
    Q_DISABLE_COPY(UserModelPrivate)
    Q_DECLARE_PUBLIC(UserModel)
public:
    UserModelPrivate(UserModel *q);

    UserModel *q_ptr;
    QHash<int, QByteArray> roleNames;
};

#endif // USER_MODEL_P_H
