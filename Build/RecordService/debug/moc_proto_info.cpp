/****************************************************************************
** Meta object code from reading C++ file 'proto_info.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../RecordService/websocket/protocol/proto_info.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proto_info.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProtoInfo_t {
    QByteArrayData data[15];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProtoInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProtoInfo_t qt_meta_stringdata_ProtoInfo = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ProtoInfo"
QT_MOC_LITERAL(1, 10, 13), // "actionRecived"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "Actions"
QT_MOC_LITERAL(4, 33, 6), // "action"
QT_MOC_LITERAL(5, 40, 4), // "data"
QT_MOC_LITERAL(6, 45, 4), // "beat"
QT_MOC_LITERAL(7, 50, 4), // "push"
QT_MOC_LITERAL(8, 55, 7), // "Device*"
QT_MOC_LITERAL(9, 63, 6), // "device"
QT_MOC_LITERAL(10, 70, 4), // "pull"
QT_MOC_LITERAL(11, 75, 9), // "heartBeat"
QT_MOC_LITERAL(12, 85, 16), // "updateDeviceInfo"
QT_MOC_LITERAL(13, 102, 13), // "getDeviceList"
QT_MOC_LITERAL(14, 116, 11) // "ActionCount"

    },
    "ProtoInfo\0actionRecived\0\0Actions\0"
    "action\0data\0beat\0push\0Device*\0device\0"
    "pull\0heartBeat\0updateDeviceInfo\0"
    "getDeviceList\0ActionCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProtoInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       1,   44, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   39,    2, 0x0a /* Public */,
       7,    1,   40,    2, 0x0a /* Public */,
      10,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QJsonValue,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

 // enums: name, flags, count, data
       3, 0x0,    4,   48,

 // enum data: key, value
      11, uint(ProtoInfo::heartBeat),
      12, uint(ProtoInfo::updateDeviceInfo),
      13, uint(ProtoInfo::getDeviceList),
      14, uint(ProtoInfo::ActionCount),

       0        // eod
};

void ProtoInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProtoInfo *_t = static_cast<ProtoInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actionRecived((*reinterpret_cast< Actions(*)>(_a[1])),(*reinterpret_cast< const QJsonValue(*)>(_a[2]))); break;
        case 1: _t->beat(); break;
        case 2: _t->push((*reinterpret_cast< Device*(*)>(_a[1]))); break;
        case 3: _t->pull(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProtoInfo::*_t)(Actions , const QJsonValue & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProtoInfo::actionRecived)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ProtoInfo::staticMetaObject = {
    { &ProtoBase::staticMetaObject, qt_meta_stringdata_ProtoInfo.data,
      qt_meta_data_ProtoInfo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ProtoInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProtoInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProtoInfo.stringdata0))
        return static_cast<void*>(const_cast< ProtoInfo*>(this));
    return ProtoBase::qt_metacast(_clname);
}

int ProtoInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ProtoBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ProtoInfo::actionRecived(Actions _t1, const QJsonValue & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
