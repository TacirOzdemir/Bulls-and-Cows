/****************************************************************************
** Meta object code from reading C++ file 'benternet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Server/benternet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'benternet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Benternet_t {
    QByteArrayData data[13];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Benternet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Benternet_t qt_meta_stringdata_Benternet = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Benternet"
QT_MOC_LITERAL(1, 10, 9), // "receiving"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "message"
QT_MOC_LITERAL(4, 29, 5), // "start"
QT_MOC_LITERAL(5, 35, 4), // "send"
QT_MOC_LITERAL(6, 40, 11), // "const char*"
QT_MOC_LITERAL(7, 52, 18), // "nzmqt::ZMQMessage&"
QT_MOC_LITERAL(8, 71, 9), // "subscribe"
QT_MOC_LITERAL(9, 81, 5), // "topic"
QT_MOC_LITERAL(10, 87, 11), // "unsubscribe"
QT_MOC_LITERAL(11, 99, 15), // "messageReceived"
QT_MOC_LITERAL(12, 115, 8) // "messages"

    },
    "Benternet\0receiving\0\0message\0start\0"
    "send\0const char*\0nzmqt::ZMQMessage&\0"
    "subscribe\0topic\0unsubscribe\0messageReceived\0"
    "messages"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Benternet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   82,    2, 0x0a /* Public */,
       5,    1,   83,    2, 0x0a /* Public */,
       5,    1,   86,    2, 0x0a /* Public */,
       5,    1,   89,    2, 0x0a /* Public */,
       5,    1,   92,    2, 0x0a /* Public */,
       8,    1,   95,    2, 0x0a /* Public */,
       8,    1,   98,    2, 0x0a /* Public */,
       8,    1,  101,    2, 0x0a /* Public */,
      10,    1,  104,    2, 0x0a /* Public */,
      10,    1,  107,    2, 0x0a /* Public */,
      10,    1,  110,    2, 0x0a /* Public */,
      11,    1,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 6,    3,
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Bool, QMetaType::QByteArray,    3,
    QMetaType::Bool, 0x80000000 | 7,    3,
    QMetaType::Void, 0x80000000 | 6,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, 0x80000000 | 6,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, QMetaType::QByteArrayList,   12,

       0        // eod
};

void Benternet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Benternet *_t = static_cast<Benternet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiving((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->start(); break;
        case 2: { bool _r = _t->send((*reinterpret_cast< const char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->send((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->send((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->send((*reinterpret_cast< nzmqt::ZMQMessage(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->subscribe((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 7: _t->subscribe((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->subscribe((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 9: _t->unsubscribe((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 10: _t->unsubscribe((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->unsubscribe((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 12: _t->messageReceived((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Benternet::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Benternet::receiving)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Benternet::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Benternet.data,
      qt_meta_data_Benternet,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Benternet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Benternet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Benternet.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Benternet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void Benternet::receiving(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
