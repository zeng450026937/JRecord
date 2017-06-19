/****************************************************************************
** Meta object code from reading C++ file 'proto_conf.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../RecordService/websocket/protocol/proto_conf.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proto_conf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProtoConf_t {
    QByteArrayData data[35];
    char stringdata0[361];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProtoConf_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProtoConf_t qt_meta_stringdata_ProtoConf = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ProtoConf"
QT_MOC_LITERAL(1, 10, 13), // "actionRecived"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "Actions"
QT_MOC_LITERAL(4, 33, 6), // "action"
QT_MOC_LITERAL(5, 40, 4), // "data"
QT_MOC_LITERAL(6, 45, 4), // "lock"
QT_MOC_LITERAL(7, 50, 6), // "unlock"
QT_MOC_LITERAL(8, 57, 6), // "create"
QT_MOC_LITERAL(9, 64, 5), // "title"
QT_MOC_LITERAL(10, 70, 7), // "content"
QT_MOC_LITERAL(11, 78, 7), // "members"
QT_MOC_LITERAL(12, 86, 7), // "devices"
QT_MOC_LITERAL(13, 94, 5), // "start"
QT_MOC_LITERAL(14, 100, 4), // "uuid"
QT_MOC_LITERAL(15, 105, 5), // "pause"
QT_MOC_LITERAL(16, 111, 6), // "resume"
QT_MOC_LITERAL(17, 118, 4), // "stop"
QT_MOC_LITERAL(18, 123, 4), // "join"
QT_MOC_LITERAL(19, 128, 5), // "leave"
QT_MOC_LITERAL(20, 134, 5), // "query"
QT_MOC_LITERAL(21, 140, 10), // "lockDevice"
QT_MOC_LITERAL(22, 151, 12), // "unlockDevice"
QT_MOC_LITERAL(23, 164, 16), // "createConference"
QT_MOC_LITERAL(24, 181, 17), // "getConferenceInfo"
QT_MOC_LITERAL(25, 199, 17), // "getConferenceList"
QT_MOC_LITERAL(26, 217, 14), // "joinConference"
QT_MOC_LITERAL(27, 232, 17), // "leveaveConference"
QT_MOC_LITERAL(28, 250, 15), // "startConference"
QT_MOC_LITERAL(29, 266, 16), // "resumeConference"
QT_MOC_LITERAL(30, 283, 15), // "pauseConference"
QT_MOC_LITERAL(31, 299, 14), // "stopConference"
QT_MOC_LITERAL(32, 314, 17), // "setConferenceInfo"
QT_MOC_LITERAL(33, 332, 20), // "deleteConferenceInfo"
QT_MOC_LITERAL(34, 353, 7) // "unknown"

    },
    "ProtoConf\0actionRecived\0\0Actions\0"
    "action\0data\0lock\0unlock\0create\0title\0"
    "content\0members\0devices\0start\0uuid\0"
    "pause\0resume\0stop\0join\0leave\0query\0"
    "lockDevice\0unlockDevice\0createConference\0"
    "getConferenceInfo\0getConferenceList\0"
    "joinConference\0leveaveConference\0"
    "startConference\0resumeConference\0"
    "pauseConference\0stopConference\0"
    "setConferenceInfo\0deleteConferenceInfo\0"
    "unknown"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProtoConf[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       1,  112, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   79,    2, 0x0a /* Public */,
       7,    0,   80,    2, 0x0a /* Public */,
       8,    4,   81,    2, 0x0a /* Public */,
      13,    1,   90,    2, 0x0a /* Public */,
      15,    1,   93,    2, 0x0a /* Public */,
      16,    1,   96,    2, 0x0a /* Public */,
      17,    1,   99,    2, 0x0a /* Public */,
      18,    1,  102,    2, 0x0a /* Public */,
      19,    1,  105,    2, 0x0a /* Public */,
      20,    1,  108,    2, 0x0a /* Public */,
      20,    0,  111,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QJsonValue,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,

 // enums: name, flags, count, data
       3, 0x0,   14,  116,

 // enum data: key, value
      21, uint(ProtoConf::lockDevice),
      22, uint(ProtoConf::unlockDevice),
      23, uint(ProtoConf::createConference),
      24, uint(ProtoConf::getConferenceInfo),
      25, uint(ProtoConf::getConferenceList),
      26, uint(ProtoConf::joinConference),
      27, uint(ProtoConf::leveaveConference),
      28, uint(ProtoConf::startConference),
      29, uint(ProtoConf::resumeConference),
      30, uint(ProtoConf::pauseConference),
      31, uint(ProtoConf::stopConference),
      32, uint(ProtoConf::setConferenceInfo),
      33, uint(ProtoConf::deleteConferenceInfo),
      34, uint(ProtoConf::unknown),

       0        // eod
};

void ProtoConf::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProtoConf *_t = static_cast<ProtoConf *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actionRecived((*reinterpret_cast< Actions(*)>(_a[1])),(*reinterpret_cast< const QJsonValue(*)>(_a[2]))); break;
        case 1: _t->lock(); break;
        case 2: _t->unlock(); break;
        case 3: _t->create((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 4: _t->start((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->pause((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->resume((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->stop((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->join((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->leave((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->query((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->query(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProtoConf::*_t)(Actions , const QJsonValue & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProtoConf::actionRecived)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ProtoConf::staticMetaObject = {
    { &ProtoBase::staticMetaObject, qt_meta_stringdata_ProtoConf.data,
      qt_meta_data_ProtoConf,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ProtoConf::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProtoConf::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProtoConf.stringdata0))
        return static_cast<void*>(const_cast< ProtoConf*>(this));
    return ProtoBase::qt_metacast(_clname);
}

int ProtoConf::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ProtoBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ProtoConf::actionRecived(Actions _t1, const QJsonValue & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
