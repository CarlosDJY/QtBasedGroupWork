/****************************************************************************
** Meta object code from reading C++ file 'balance.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainCode/balance.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'balance.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Balance_t {
    const uint offsetsAndSize[16];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Balance_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Balance_t qt_meta_stringdata_Balance = {
    {
QT_MOC_LITERAL(0, 7), // "Balance"
QT_MOC_LITERAL(8, 9), // "onTimeOut"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 17), // "on_plus10_clicked"
QT_MOC_LITERAL(37, 17), // "on_plus50_clicked"
QT_MOC_LITERAL(55, 18), // "on_plus100_clicked"
QT_MOC_LITERAL(74, 24), // "on_plusNum_returnPressed"
QT_MOC_LITERAL(99, 21) // "on_BackButton_clicked"

    },
    "Balance\0onTimeOut\0\0on_plus10_clicked\0"
    "on_plus50_clicked\0on_plus100_clicked\0"
    "on_plusNum_returnPressed\0on_BackButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Balance[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Balance::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Balance *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onTimeOut(); break;
        case 1: _t->on_plus10_clicked(); break;
        case 2: _t->on_plus50_clicked(); break;
        case 3: _t->on_plus100_clicked(); break;
        case 4: _t->on_plusNum_returnPressed(); break;
        case 5: _t->on_BackButton_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject Balance::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Balance.offsetsAndSize,
    qt_meta_data_Balance,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Balance_t
, QtPrivate::TypeAndForceComplete<Balance, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Balance::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Balance::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Balance.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Balance::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
