/****************************************************************************
** Meta object code from reading C++ file 'service_base.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../RecordService/service/service_base.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'service_base.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ServiceBase_t {
    QByteArrayData data[33];
    char stringdata0[352];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServiceBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServiceBase_t qt_meta_stringdata_ServiceBase = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ServiceBase"
QT_MOC_LITERAL(1, 12, 13), // "statusChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "Status"
QT_MOC_LITERAL(4, 34, 6), // "status"
QT_MOC_LITERAL(5, 41, 13), // "activeChanged"
QT_MOC_LITERAL(6, 55, 6), // "active"
QT_MOC_LITERAL(7, 62, 10), // "urlChanged"
QT_MOC_LITERAL(8, 73, 3), // "url"
QT_MOC_LITERAL(9, 77, 13), // "userIdChanged"
QT_MOC_LITERAL(10, 91, 6), // "userId"
QT_MOC_LITERAL(11, 98, 16), // "userGroupChanged"
QT_MOC_LITERAL(12, 115, 9), // "userGroup"
QT_MOC_LITERAL(13, 125, 15), // "userNameChanged"
QT_MOC_LITERAL(14, 141, 8), // "userName"
QT_MOC_LITERAL(15, 150, 17), // "deviceTypeChanged"
QT_MOC_LITERAL(16, 168, 10), // "deviceType"
QT_MOC_LITERAL(17, 179, 17), // "deviceUuidChanged"
QT_MOC_LITERAL(18, 197, 10), // "deviceUuid"
QT_MOC_LITERAL(19, 208, 15), // "protocolChanged"
QT_MOC_LITERAL(20, 224, 12), // "protocolName"
QT_MOC_LITERAL(21, 237, 9), // "setActive"
QT_MOC_LITERAL(22, 247, 6), // "setUrl"
QT_MOC_LITERAL(23, 254, 9), // "setUserId"
QT_MOC_LITERAL(24, 264, 12), // "setUserGroup"
QT_MOC_LITERAL(25, 277, 11), // "setUserName"
QT_MOC_LITERAL(26, 289, 13), // "setDeviceType"
QT_MOC_LITERAL(27, 303, 11), // "errorString"
QT_MOC_LITERAL(28, 315, 10), // "Connecting"
QT_MOC_LITERAL(29, 326, 4), // "Open"
QT_MOC_LITERAL(30, 331, 7), // "Closing"
QT_MOC_LITERAL(31, 339, 6), // "Closed"
QT_MOC_LITERAL(32, 346, 5) // "Error"

    },
    "ServiceBase\0statusChanged\0\0Status\0"
    "status\0activeChanged\0active\0urlChanged\0"
    "url\0userIdChanged\0userId\0userGroupChanged\0"
    "userGroup\0userNameChanged\0userName\0"
    "deviceTypeChanged\0deviceType\0"
    "deviceUuidChanged\0deviceUuid\0"
    "protocolChanged\0protocolName\0setActive\0"
    "setUrl\0setUserId\0setUserGroup\0setUserName\0"
    "setDeviceType\0errorString\0Connecting\0"
    "Open\0Closing\0Closed\0Error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServiceBase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       8,  134, // properties
       1,  166, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       5,    1,   92,    2, 0x06 /* Public */,
       7,    1,   95,    2, 0x06 /* Public */,
       9,    1,   98,    2, 0x06 /* Public */,
      11,    1,  101,    2, 0x06 /* Public */,
      13,    1,  104,    2, 0x06 /* Public */,
      15,    1,  107,    2, 0x06 /* Public */,
      17,    1,  110,    2, 0x06 /* Public */,
      19,    1,  113,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    1,  116,    2, 0x0a /* Public */,
      22,    1,  119,    2, 0x0a /* Public */,
      23,    1,  122,    2, 0x0a /* Public */,
      24,    1,  125,    2, 0x0a /* Public */,
      25,    1,  128,    2, 0x0a /* Public */,
      26,    1,  131,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QUrl,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   20,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QUrl,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   16,

 // properties: name, type, flags
       6, QMetaType::Bool, 0x00495103,
      27, QMetaType::QString, 0x00095001,
       8, QMetaType::QUrl, 0x00495103,
      10, QMetaType::QString, 0x00495103,
      12, QMetaType::QString, 0x00495103,
      14, QMetaType::QString, 0x00495103,
      16, QMetaType::QString, 0x00495103,
      18, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       1,
       0,
       2,
       3,
       4,
       5,
       6,
       7,

 // enums: name, flags, count, data
       3, 0x0,    5,  170,

 // enum data: key, value
      28, uint(ServiceBase::Connecting),
      29, uint(ServiceBase::Open),
      30, uint(ServiceBase::Closing),
      31, uint(ServiceBase::Closed),
      32, uint(ServiceBase::Error),

       0        // eod
};

void ServiceBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServiceBase *_t = static_cast<ServiceBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->statusChanged((*reinterpret_cast< Status(*)>(_a[1]))); break;
        case 1: _t->activeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->urlChanged((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 3: _t->userIdChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->userGroupChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->userNameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->deviceTypeChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->deviceUuidChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->protocolChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->setActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 11: _t->setUserId((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->setUserGroup((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->setUserName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->setDeviceType((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ServiceBase::*_t)(Status );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServiceBase::statusChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ServiceBase::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServiceBase::activeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ServiceBase::*_t)(const QUrl & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServiceBase::urlChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ServiceBase::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServiceBase::userIdChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ServiceBase::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServiceBase::userGroupChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ServiceBase::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServiceBase::userNameChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ServiceBase::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServiceBase::deviceTypeChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (ServiceBase::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServiceBase::deviceUuidChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (ServiceBase::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServiceBase::protocolChanged)) {
                *result = 8;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ServiceBase *_t = static_cast<ServiceBase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->active(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->errorString(); break;
        case 2: *reinterpret_cast< QUrl*>(_v) = _t->url(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->userId(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->userGroup(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->userName(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->deviceType(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->deviceUuid(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ServiceBase *_t = static_cast<ServiceBase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setActive(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setUrl(*reinterpret_cast< QUrl*>(_v)); break;
        case 3: _t->setUserId(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setUserGroup(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setUserName(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setDeviceType(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ServiceBase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ServiceBase.data,
      qt_meta_data_ServiceBase,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ServiceBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServiceBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ServiceBase.stringdata0))
        return static_cast<void*>(const_cast< ServiceBase*>(this));
    return QObject::qt_metacast(_clname);
}

int ServiceBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ServiceBase::statusChanged(Status _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ServiceBase::activeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ServiceBase::urlChanged(const QUrl & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ServiceBase::userIdChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ServiceBase::userGroupChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ServiceBase::userNameChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ServiceBase::deviceTypeChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ServiceBase::deviceUuidChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ServiceBase::protocolChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
