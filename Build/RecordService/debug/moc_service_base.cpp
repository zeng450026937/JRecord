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
    QByteArrayData data[26];
    char stringdata0[254];
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
QT_MOC_LITERAL(9, 77, 13), // "deviceChanged"
QT_MOC_LITERAL(10, 91, 13), // "const Device*"
QT_MOC_LITERAL(11, 105, 6), // "device"
QT_MOC_LITERAL(12, 112, 15), // "protocolChanged"
QT_MOC_LITERAL(13, 128, 12), // "protocolName"
QT_MOC_LITERAL(14, 141, 9), // "setActive"
QT_MOC_LITERAL(15, 151, 6), // "setUrl"
QT_MOC_LITERAL(16, 158, 9), // "setDevice"
QT_MOC_LITERAL(17, 168, 7), // "Device*"
QT_MOC_LITERAL(18, 176, 13), // "deviceManager"
QT_MOC_LITERAL(19, 190, 14), // "DeviceManager*"
QT_MOC_LITERAL(20, 205, 11), // "errorString"
QT_MOC_LITERAL(21, 217, 10), // "Connecting"
QT_MOC_LITERAL(22, 228, 4), // "Open"
QT_MOC_LITERAL(23, 233, 7), // "Closing"
QT_MOC_LITERAL(24, 241, 6), // "Closed"
QT_MOC_LITERAL(25, 248, 5) // "Error"

    },
    "ServiceBase\0statusChanged\0\0Status\0"
    "status\0activeChanged\0active\0urlChanged\0"
    "url\0deviceChanged\0const Device*\0device\0"
    "protocolChanged\0protocolName\0setActive\0"
    "setUrl\0setDevice\0Device*\0deviceManager\0"
    "DeviceManager*\0errorString\0Connecting\0"
    "Open\0Closing\0Closed\0Error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServiceBase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       4,   84, // properties
       1,  100, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       7,    1,   65,    2, 0x06 /* Public */,
       9,    1,   68,    2, 0x06 /* Public */,
      12,    1,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   74,    2, 0x0a /* Public */,
      15,    1,   77,    2, 0x0a /* Public */,
      16,    1,   80,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      18,    0,   83,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QUrl,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QUrl,    8,
    QMetaType::Void, 0x80000000 | 17,   11,

 // methods: parameters
    0x80000000 | 19,

 // properties: name, type, flags
       6, QMetaType::Bool, 0x00495103,
      20, QMetaType::QString, 0x00095001,
       8, QMetaType::QUrl, 0x00495103,
      11, 0x80000000 | 17, 0x0049510b,

 // properties: notify_signal_id
       1,
       0,
       2,
       3,

 // enums: name, flags, count, data
       3, 0x0,    5,  104,

 // enum data: key, value
      21, uint(ServiceBase::Connecting),
      22, uint(ServiceBase::Open),
      23, uint(ServiceBase::Closing),
      24, uint(ServiceBase::Closed),
      25, uint(ServiceBase::Error),

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
        case 3: _t->deviceChanged((*reinterpret_cast< const Device*(*)>(_a[1]))); break;
        case 4: _t->protocolChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 7: _t->setDevice((*reinterpret_cast< Device*(*)>(_a[1]))); break;
        case 8: { DeviceManager* _r = _t->deviceManager();
            if (_a[0]) *reinterpret_cast< DeviceManager**>(_a[0]) = std::move(_r); }  break;
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
            typedef void (ServiceBase::*_t)(const Device * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServiceBase::deviceChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ServiceBase::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServiceBase::protocolChanged)) {
                *result = 4;
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
        case 3: *reinterpret_cast< Device**>(_v) = _t->device(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ServiceBase *_t = static_cast<ServiceBase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setActive(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setUrl(*reinterpret_cast< QUrl*>(_v)); break;
        case 3: _t->setDevice(*reinterpret_cast< Device**>(_v)); break;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
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
void ServiceBase::deviceChanged(const Device * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ServiceBase::protocolChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
