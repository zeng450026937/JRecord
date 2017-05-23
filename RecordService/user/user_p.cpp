#include "user_p.h"

UserPrivate::UserPrivate(User *q) :
    q_ptr(q),
    userGroup(QStringLiteral("ND"))
{

}
