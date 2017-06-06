/****************************************************************************
** Meta object code from reading C++ file 'binarymessage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../RecordService/websocket/binarymessage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'binarymessage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BinaryMessage_t {
    QByteArrayData data[29];
    char stringdata0[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BinaryMessage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BinaryMessage_t qt_meta_stringdata_BinaryMessage = {
    {
QT_MOC_LITERAL(0, 0, 13), // "BinaryMessage"
QT_MOC_LITERAL(1, 14, 11), // "modeChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "mode"
QT_MOC_LITERAL(4, 32, 13), // "userIdChanged"
QT_MOC_LITERAL(5, 46, 6), // "userId"
QT_MOC_LITERAL(6, 53, 17), // "deviceUuidChanged"
QT_MOC_LITERAL(7, 71, 10), // "deviceUuid"
QT_MOC_LITERAL(8, 82, 11), // "uuidChanged"
QT_MOC_LITERAL(9, 94, 4), // "uuid"
QT_MOC_LITERAL(10, 99, 16), // "timestampChanged"
QT_MOC_LITERAL(11, 116, 9), // "timestamp"
QT_MOC_LITERAL(12, 126, 15), // "startposChanged"
QT_MOC_LITERAL(13, 142, 8), // "startpos"
QT_MOC_LITERAL(14, 151, 13), // "statusChanged"
QT_MOC_LITERAL(15, 165, 6), // "status"
QT_MOC_LITERAL(16, 172, 11), // "sizeChanged"
QT_MOC_LITERAL(17, 184, 4), // "size"
QT_MOC_LITERAL(18, 189, 7), // "setMode"
QT_MOC_LITERAL(19, 197, 9), // "setUserId"
QT_MOC_LITERAL(20, 207, 13), // "setDeviceUuid"
QT_MOC_LITERAL(21, 221, 7), // "setUuid"
QT_MOC_LITERAL(22, 229, 12), // "setTimestamp"
QT_MOC_LITERAL(23, 242, 11), // "setStartpos"
QT_MOC_LITERAL(24, 254, 9), // "setStatus"
QT_MOC_LITERAL(25, 264, 7), // "setSize"
QT_MOC_LITERAL(26, 272, 5), // "parse"
QT_MOC_LITERAL(27, 278, 7), // "message"
QT_MOC_LITERAL(28, 286, 4) // "make"

    },
    "BinaryMessage\0modeChanged\0\0mode\0"
    "userIdChanged\0userId\0deviceUuidChanged\0"
    "deviceUuid\0uuidChanged\0uuid\0"
    "timestampChanged\0timestamp\0startposChanged\0"
    "startpos\0statusChanged\0status\0sizeChanged\0"
    "size\0setMode\0setUserId\0setDeviceUuid\0"
    "setUuid\0setTimestamp\0setStartpos\0"
    "setStatus\0setSize\0parse\0message\0make"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BinaryMessage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       8,  156, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       4,    1,  107,    2, 0x06 /* Public */,
       6,    1,  110,    2, 0x06 /* Public */,
       8,    1,  113,    2, 0x06 /* Public */,
      10,    1,  116,    2, 0x06 /* Public */,
      12,    1,  119,    2, 0x06 /* Public */,
      14,    1,  122,    2, 0x06 /* Public */,
      16,    1,  125,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,  128,    2, 0x0a /* Public */,
      19,    1,  131,    2, 0x0a /* Public */,
      20,    1,  134,    2, 0x0a /* Public */,
      21,    1,  137,    2, 0x0a /* Public */,
      22,    1,  140,    2, 0x0a /* Public */,
      23,    1,  143,    2, 0x0a /* Public */,
      24,    1,  146,    2, 0x0a /* Public */,
      25,    1,  149,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      26,    1,  152,    2, 0x02 /* Public */,
      28,    0,  155,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,

 // methods: parameters
    QMetaType::Void, QMetaType::QByteArray,   27,
    QMetaType::QByteArray,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00495103,
       5, QMetaType::QString, 0x00495103,
       7, QMetaType::QString, 0x00495103,
       9, QMetaType::QString, 0x00495103,
      11, QMetaType::Int, 0x00495103,
      13, QMetaType::Int, 0x00495103,
      15, QMetaType::Int, 0x00495103,
      17, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,

       0        // eod
};

void BinaryMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BinaryMessage *_t = static_cast<BinaryMessage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->userIdChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->deviceUuidChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->uuidChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->timestampChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->startposChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->statusChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->sizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setUserId((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->setDeviceUuid((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->setUuid((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->setTimestamp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setStartpos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->parse((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 17: { QByteArray _r = _t->make();
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BinaryMessage::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BinaryMessage::modeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BinaryMessage::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BinaryMessage::userIdChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BinaryMessage::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BinaryMessage::deviceUuidChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (BinaryMessage::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BinaryMessage::uuidChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (BinaryMessage::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BinaryMessage::timestampChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (BinaryMessage::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BinaryMessage::startposChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (BinaryMessage::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BinaryMessage::statusChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (BinaryMessage::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BinaryMessage::sizeChanged)) {
                *result = 7;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        BinaryMessage *_t = static_cast<BinaryMessage *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->mode(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->userId(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->deviceUuid(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->uuid(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->timestamp(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->startpos(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->status(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->size(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        BinaryMessage *_t = static_cast<BinaryMessage *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMode(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setUserId(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setDeviceUuid(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setUuid(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setTimestamp(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setStartpos(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setStatus(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setSize(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject BinaryMessage::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BinaryMessage.data,
      qt_meta_data_BinaryMessage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BinaryMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BinaryMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BinaryMessage.stringdata0))
        return static_cast<void*>(const_cast< BinaryMessage*>(this));
    if (!strcmp(_clname, "MessagePacket"))
        return static_cast< MessagePacket*>(const_cast< BinaryMessage*>(this));
    return QObject::qt_metacast(_clname);
}

int BinaryMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
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
void BinaryMessage::modeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BinaryMessage::userIdChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BinaryMessage::deviceUuidChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BinaryMessage::uuidChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BinaryMessage::timestampChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void BinaryMessage::startposChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void BinaryMessage::statusChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void BinaryMessage::sizeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
