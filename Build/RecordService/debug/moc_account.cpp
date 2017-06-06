/****************************************************************************
** Meta object code from reading C++ file 'account.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../RecordService/account/account.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'account.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Account_t {
    QByteArrayData data[31];
    char stringdata0[325];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Account_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Account_t qt_meta_stringdata_Account = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Account"
QT_MOC_LITERAL(1, 8, 13), // "userIdChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "userId"
QT_MOC_LITERAL(4, 30, 15), // "userNameChanged"
QT_MOC_LITERAL(5, 46, 8), // "username"
QT_MOC_LITERAL(6, 55, 16), // "userGroupChanged"
QT_MOC_LITERAL(7, 72, 9), // "userGroup"
QT_MOC_LITERAL(8, 82, 15), // "passwordChanged"
QT_MOC_LITERAL(9, 98, 8), // "password"
QT_MOC_LITERAL(10, 107, 12), // "imageChanged"
QT_MOC_LITERAL(11, 120, 5), // "image"
QT_MOC_LITERAL(12, 126, 16), // "signatureChanged"
QT_MOC_LITERAL(13, 143, 9), // "signature"
QT_MOC_LITERAL(14, 153, 18), // "errorStringChanged"
QT_MOC_LITERAL(15, 172, 11), // "errorString"
QT_MOC_LITERAL(16, 184, 13), // "statusChanged"
QT_MOC_LITERAL(17, 198, 6), // "Status"
QT_MOC_LITERAL(18, 205, 6), // "status"
QT_MOC_LITERAL(19, 212, 13), // "activeChanged"
QT_MOC_LITERAL(20, 226, 6), // "active"
QT_MOC_LITERAL(21, 233, 9), // "setUserId"
QT_MOC_LITERAL(22, 243, 12), // "setUserGroup"
QT_MOC_LITERAL(23, 256, 11), // "setPassword"
QT_MOC_LITERAL(24, 268, 9), // "setActive"
QT_MOC_LITERAL(25, 278, 8), // "userName"
QT_MOC_LITERAL(26, 287, 8), // "Logining"
QT_MOC_LITERAL(27, 296, 5), // "Login"
QT_MOC_LITERAL(28, 302, 9), // "Logouting"
QT_MOC_LITERAL(29, 312, 6), // "Logout"
QT_MOC_LITERAL(30, 319, 5) // "Error"

    },
    "Account\0userIdChanged\0\0userId\0"
    "userNameChanged\0username\0userGroupChanged\0"
    "userGroup\0passwordChanged\0password\0"
    "imageChanged\0image\0signatureChanged\0"
    "signature\0errorStringChanged\0errorString\0"
    "statusChanged\0Status\0status\0activeChanged\0"
    "active\0setUserId\0setUserGroup\0setPassword\0"
    "setActive\0userName\0Logining\0Login\0"
    "Logouting\0Logout\0Error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Account[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       9,  118, // properties
       1,  154, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       6,    1,   85,    2, 0x06 /* Public */,
       8,    1,   88,    2, 0x06 /* Public */,
      10,    1,   91,    2, 0x06 /* Public */,
      12,    1,   94,    2, 0x06 /* Public */,
      14,    1,   97,    2, 0x06 /* Public */,
      16,    1,  100,    2, 0x06 /* Public */,
      19,    1,  103,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    1,  106,    2, 0x0a /* Public */,
      22,    1,  109,    2, 0x0a /* Public */,
      23,    1,  112,    2, 0x0a /* Public */,
      24,    1,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Bool,   20,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Bool,   20,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
      25, QMetaType::QString, 0x00495001,
       7, QMetaType::QString, 0x00495103,
       9, QMetaType::QString, 0x00495103,
      11, QMetaType::QString, 0x00495001,
      13, QMetaType::QString, 0x00495001,
      15, QMetaType::QString, 0x00495001,
      18, 0x80000000 | 17, 0x00495009,
      20, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,

 // enums: name, flags, count, data
      17, 0x0,    5,  158,

 // enum data: key, value
      26, uint(Account::Logining),
      27, uint(Account::Login),
      28, uint(Account::Logouting),
      29, uint(Account::Logout),
      30, uint(Account::Error),

       0        // eod
};

void Account::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Account *_t = static_cast<Account *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->userIdChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->userNameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->userGroupChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->passwordChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->imageChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->signatureChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->errorStringChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->statusChanged((*reinterpret_cast< const Status(*)>(_a[1]))); break;
        case 8: _t->activeChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 9: _t->setUserId((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->setUserGroup((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->setPassword((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->setActive((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Account::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::userIdChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Account::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::userNameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Account::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::userGroupChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Account::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::passwordChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Account::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::imageChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Account::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::signatureChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Account::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::errorStringChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Account::*_t)(const Status );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::statusChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Account::*_t)(const bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::activeChanged)) {
                *result = 8;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Account *_t = static_cast<Account *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->userId(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->userName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->userGroup(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->password(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->image(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->signature(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->errorString(); break;
        case 7: *reinterpret_cast< Status*>(_v) = _t->status(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->active(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Account *_t = static_cast<Account *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setUserId(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setUserGroup(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setPassword(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->setActive(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Account::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Account.data,
      qt_meta_data_Account,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Account::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Account::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Account.stringdata0))
        return static_cast<void*>(const_cast< Account*>(this));
    return QObject::qt_metacast(_clname);
}

int Account::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Account::userIdChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Account::userNameChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Account::userGroupChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Account::passwordChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Account::imageChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Account::signatureChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Account::errorStringChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Account::statusChanged(const Status _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Account::activeChanged(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
