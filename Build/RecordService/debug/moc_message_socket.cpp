/****************************************************************************
** Meta object code from reading C++ file 'message_socket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../RecordService/websocket/message_socket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'message_socket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MessageSocket_t {
    QByteArrayData data[18];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MessageSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MessageSocket_t qt_meta_stringdata_MessageSocket = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MessageSocket"
QT_MOC_LITERAL(1, 14, 13), // "activeChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 6), // "active"
QT_MOC_LITERAL(4, 36, 14), // "requestChanged"
QT_MOC_LITERAL(5, 51, 15), // "QNetworkRequest"
QT_MOC_LITERAL(6, 67, 7), // "request"
QT_MOC_LITERAL(7, 75, 12), // "errorChanged"
QT_MOC_LITERAL(8, 88, 5), // "error"
QT_MOC_LITERAL(9, 94, 9), // "connected"
QT_MOC_LITERAL(10, 104, 12), // "disconnected"
QT_MOC_LITERAL(11, 117, 12), // "textReceived"
QT_MOC_LITERAL(12, 130, 7), // "message"
QT_MOC_LITERAL(13, 138, 14), // "binaryReceived"
QT_MOC_LITERAL(14, 153, 9), // "setActive"
QT_MOC_LITERAL(15, 163, 10), // "setRequest"
QT_MOC_LITERAL(16, 174, 8), // "sendText"
QT_MOC_LITERAL(17, 183, 10) // "sendBinary"

    },
    "MessageSocket\0activeChanged\0\0active\0"
    "requestChanged\0QNetworkRequest\0request\0"
    "errorChanged\0error\0connected\0disconnected\0"
    "textReceived\0message\0binaryReceived\0"
    "setActive\0setRequest\0sendText\0sendBinary"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageSocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       3,   98, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       7,    1,   75,    2, 0x06 /* Public */,
       9,    0,   78,    2, 0x06 /* Public */,
      10,    0,   79,    2, 0x06 /* Public */,
      11,    1,   80,    2, 0x06 /* Public */,
      13,    1,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   86,    2, 0x0a /* Public */,
      15,    1,   89,    2, 0x0a /* Public */,
      16,    1,   92,    2, 0x0a /* Public */,
      17,    1,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QByteArray,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QByteArray,   12,

 // properties: name, type, flags
       3, QMetaType::Bool, 0x00495103,
       6, 0x80000000 | 5, 0x0049510b,
       8, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void MessageSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MessageSocket *_t = static_cast<MessageSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activeChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->requestChanged((*reinterpret_cast< const QNetworkRequest(*)>(_a[1]))); break;
        case 2: _t->errorChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->connected(); break;
        case 4: _t->disconnected(); break;
        case 5: _t->textReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->binaryReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 7: _t->setActive((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 8: _t->setRequest((*reinterpret_cast< const QNetworkRequest(*)>(_a[1]))); break;
        case 9: _t->sendText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->sendBinary((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkRequest >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkRequest >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MessageSocket::*_t)(const bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageSocket::activeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MessageSocket::*_t)(const QNetworkRequest & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageSocket::requestChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MessageSocket::*_t)(const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageSocket::errorChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MessageSocket::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageSocket::connected)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MessageSocket::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageSocket::disconnected)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MessageSocket::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageSocket::textReceived)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MessageSocket::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageSocket::binaryReceived)) {
                *result = 6;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkRequest >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        MessageSocket *_t = static_cast<MessageSocket *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->active(); break;
        case 1: *reinterpret_cast< QNetworkRequest*>(_v) = _t->request(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->error(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        MessageSocket *_t = static_cast<MessageSocket *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setActive(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setRequest(*reinterpret_cast< QNetworkRequest*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject MessageSocket::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MessageSocket.data,
      qt_meta_data_MessageSocket,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MessageSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MessageSocket.stringdata0))
        return static_cast<void*>(const_cast< MessageSocket*>(this));
    return QObject::qt_metacast(_clname);
}

int MessageSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MessageSocket::activeChanged(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MessageSocket::requestChanged(const QNetworkRequest & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MessageSocket::errorChanged(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MessageSocket::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MessageSocket::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MessageSocket::textReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MessageSocket::binaryReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
