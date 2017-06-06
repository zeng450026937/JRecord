/****************************************************************************
** Meta object code from reading C++ file 'textmessage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../RecordService/websocket/textmessage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textmessage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TextMessage_t {
    QByteArrayData data[28];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextMessage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextMessage_t qt_meta_stringdata_TextMessage = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TextMessage"
QT_MOC_LITERAL(1, 12, 14), // "versionChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "version"
QT_MOC_LITERAL(4, 36, 11), // "fromChanged"
QT_MOC_LITERAL(5, 48, 4), // "from"
QT_MOC_LITERAL(6, 53, 9), // "toChanged"
QT_MOC_LITERAL(7, 63, 2), // "to"
QT_MOC_LITERAL(8, 66, 11), // "modeChanged"
QT_MOC_LITERAL(9, 78, 4), // "mode"
QT_MOC_LITERAL(10, 83, 13), // "actionChanged"
QT_MOC_LITERAL(11, 97, 6), // "action"
QT_MOC_LITERAL(12, 104, 11), // "dataChanged"
QT_MOC_LITERAL(13, 116, 13), // "resultChanged"
QT_MOC_LITERAL(14, 130, 6), // "result"
QT_MOC_LITERAL(15, 137, 10), // "setVersion"
QT_MOC_LITERAL(16, 148, 7), // "setFrom"
QT_MOC_LITERAL(17, 156, 5), // "setTo"
QT_MOC_LITERAL(18, 162, 7), // "setMode"
QT_MOC_LITERAL(19, 170, 9), // "setAction"
QT_MOC_LITERAL(20, 180, 7), // "setData"
QT_MOC_LITERAL(21, 188, 4), // "data"
QT_MOC_LITERAL(22, 193, 9), // "setResult"
QT_MOC_LITERAL(23, 203, 5), // "parse"
QT_MOC_LITERAL(24, 209, 7), // "message"
QT_MOC_LITERAL(25, 217, 4), // "make"
QT_MOC_LITERAL(26, 222, 8), // "makeJson"
QT_MOC_LITERAL(27, 231, 4) // "json"

    },
    "TextMessage\0versionChanged\0\0version\0"
    "fromChanged\0from\0toChanged\0to\0modeChanged\0"
    "mode\0actionChanged\0action\0dataChanged\0"
    "resultChanged\0result\0setVersion\0setFrom\0"
    "setTo\0setMode\0setAction\0setData\0data\0"
    "setResult\0parse\0message\0make\0makeJson\0"
    "json"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextMessage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       8,  144, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,
       6,    1,  105,    2, 0x06 /* Public */,
       8,    1,  108,    2, 0x06 /* Public */,
      10,    1,  111,    2, 0x06 /* Public */,
      12,    0,  114,    2, 0x06 /* Public */,
      13,    1,  115,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  118,    2, 0x0a /* Public */,
      16,    1,  121,    2, 0x0a /* Public */,
      17,    1,  124,    2, 0x0a /* Public */,
      18,    1,  127,    2, 0x0a /* Public */,
      19,    1,  130,    2, 0x0a /* Public */,
      20,    1,  133,    2, 0x0a /* Public */,
      22,    1,  136,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      23,    1,  139,    2, 0x02 /* Public */,
      25,    0,  142,    2, 0x02 /* Public */,
      26,    0,  143,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QVariantMap,   21,
    QMetaType::Void, QMetaType::Bool,   14,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::QString,
    QMetaType::QJsonValue,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::QString, 0x00495103,
       7, QMetaType::QString, 0x00495103,
       9, QMetaType::QString, 0x00495103,
      11, QMetaType::QString, 0x00495103,
      21, QMetaType::QVariantMap, 0x00495103,
      14, QMetaType::Bool, 0x00495103,
      27, QMetaType::QJsonValue, 0x00095001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       0,

       0        // eod
};

void TextMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TextMessage *_t = static_cast<TextMessage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->versionChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->fromChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->toChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->modeChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->actionChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->dataChanged(); break;
        case 6: _t->resultChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 7: _t->setVersion((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->setFrom((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->setTo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->setMode((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->setAction((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->setData((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        case 13: _t->setResult((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 14: _t->parse((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: { QString _r = _t->make();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: { QJsonValue _r = _t->makeJson();
            if (_a[0]) *reinterpret_cast< QJsonValue*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TextMessage::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextMessage::versionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TextMessage::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextMessage::fromChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TextMessage::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextMessage::toChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TextMessage::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextMessage::modeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (TextMessage::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextMessage::actionChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (TextMessage::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextMessage::dataChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (TextMessage::*_t)(const bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextMessage::resultChanged)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        TextMessage *_t = static_cast<TextMessage *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->version(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->from(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->to(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->mode(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->action(); break;
        case 5: *reinterpret_cast< QVariantMap*>(_v) = _t->data(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->result(); break;
        case 7: *reinterpret_cast< QJsonValue*>(_v) = _t->json(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        TextMessage *_t = static_cast<TextMessage *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setVersion(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setFrom(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setTo(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setMode(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setAction(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setData(*reinterpret_cast< QVariantMap*>(_v)); break;
        case 6: _t->setResult(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject TextMessage::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TextMessage.data,
      qt_meta_data_TextMessage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TextMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TextMessage.stringdata0))
        return static_cast<void*>(const_cast< TextMessage*>(this));
    if (!strcmp(_clname, "MessagePacket"))
        return static_cast< MessagePacket*>(const_cast< TextMessage*>(this));
    return QObject::qt_metacast(_clname);
}

int TextMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
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
void TextMessage::versionChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TextMessage::fromChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TextMessage::toChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TextMessage::modeChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TextMessage::actionChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TextMessage::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void TextMessage::resultChanged(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
