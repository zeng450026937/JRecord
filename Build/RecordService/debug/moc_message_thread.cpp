/****************************************************************************
** Meta object code from reading C++ file 'message_thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../RecordService/websocket/message_thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'message_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MessageThread_t {
    QByteArrayData data[16];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MessageThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MessageThread_t qt_meta_stringdata_MessageThread = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MessageThread"
QT_MOC_LITERAL(1, 14, 13), // "activeChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 6), // "active"
QT_MOC_LITERAL(4, 36, 12), // "queueChanged"
QT_MOC_LITERAL(5, 49, 13), // "socketChanged"
QT_MOC_LITERAL(6, 63, 8), // "setQueue"
QT_MOC_LITERAL(7, 72, 13), // "MessageQueue*"
QT_MOC_LITERAL(8, 86, 5), // "queue"
QT_MOC_LITERAL(9, 92, 9), // "setSocket"
QT_MOC_LITERAL(10, 102, 14), // "MessageSocket*"
QT_MOC_LITERAL(11, 117, 6), // "socket"
QT_MOC_LITERAL(12, 124, 9), // "setActive"
QT_MOC_LITERAL(13, 134, 11), // "pushMessage"
QT_MOC_LITERAL(14, 146, 14), // "MessagePacket*"
QT_MOC_LITERAL(15, 161, 7) // "message"

    },
    "MessageThread\0activeChanged\0\0active\0"
    "queueChanged\0socketChanged\0setQueue\0"
    "MessageQueue*\0queue\0setSocket\0"
    "MessageSocket*\0socket\0setActive\0"
    "pushMessage\0MessagePacket*\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       3,   66, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   54,    2, 0x0a /* Public */,
       9,    1,   57,    2, 0x0a /* Public */,
      12,    1,   60,    2, 0x0a /* Public */,
      13,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 14,   15,

 // properties: name, type, flags
       8, 0x80000000 | 7, 0x0049510b,
      11, 0x80000000 | 10, 0x0049510b,
       3, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       1,
       2,
       0,

       0        // eod
};

void MessageThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MessageThread *_t = static_cast<MessageThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->queueChanged(); break;
        case 2: _t->socketChanged(); break;
        case 3: _t->setQueue((*reinterpret_cast< MessageQueue*(*)>(_a[1]))); break;
        case 4: _t->setSocket((*reinterpret_cast< MessageSocket*(*)>(_a[1]))); break;
        case 5: _t->setActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->pushMessage((*reinterpret_cast< MessagePacket*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MessageThread::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageThread::activeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MessageThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageThread::queueChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MessageThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageThread::socketChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        MessageThread *_t = static_cast<MessageThread *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< MessageQueue**>(_v) = _t->queue(); break;
        case 1: *reinterpret_cast< MessageSocket**>(_v) = _t->socket(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->active(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        MessageThread *_t = static_cast<MessageThread *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setQueue(*reinterpret_cast< MessageQueue**>(_v)); break;
        case 1: _t->setSocket(*reinterpret_cast< MessageSocket**>(_v)); break;
        case 2: _t->setActive(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject MessageThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MessageThread.data,
      qt_meta_data_MessageThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MessageThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MessageThread.stringdata0))
        return static_cast<void*>(const_cast< MessageThread*>(this));
    return QThread::qt_metacast(_clname);
}

int MessageThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
void MessageThread::activeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MessageThread::queueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MessageThread::socketChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
