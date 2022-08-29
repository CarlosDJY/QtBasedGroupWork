/****************************************************************************
** Meta object code from reading C++ file 'accountdetail.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainCode/accountdetail.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accountdetail.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AccountDetail_t {
    const uint offsetsAndSize[24];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AccountDetail_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AccountDetail_t qt_meta_stringdata_AccountDetail = {
    {
QT_MOC_LITERAL(0, 13), // "AccountDetail"
QT_MOC_LITERAL(14, 23), // "on_ReturnButton_clicked"
QT_MOC_LITERAL(38, 0), // ""
QT_MOC_LITERAL(39, 21), // "on_SaveButton_clicked"
QT_MOC_LITERAL(61, 27), // "on_NameEdit_editingFinished"
QT_MOC_LITERAL(89, 21), // "on_MaleChoose_clicked"
QT_MOC_LITERAL(111, 23), // "on_FemaleChoose_clicked"
QT_MOC_LITERAL(135, 23), // "on_SecretChoose_clicked"
QT_MOC_LITERAL(159, 28), // "on_PhoneEdit_editingFinished"
QT_MOC_LITERAL(188, 27), // "on_MailEdit_editingFinished"
QT_MOC_LITERAL(216, 30), // "on_AddressEdit_editingFinished"
QT_MOC_LITERAL(247, 31) // "on_PasswordEdit_editingFinished"

    },
    "AccountDetail\0on_ReturnButton_clicked\0"
    "\0on_SaveButton_clicked\0"
    "on_NameEdit_editingFinished\0"
    "on_MaleChoose_clicked\0on_FemaleChoose_clicked\0"
    "on_SecretChoose_clicked\0"
    "on_PhoneEdit_editingFinished\0"
    "on_MailEdit_editingFinished\0"
    "on_AddressEdit_editingFinished\0"
    "on_PasswordEdit_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccountDetail[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    1 /* Private */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    0,   79,    2, 0x08,    6 /* Private */,
       8,    0,   80,    2, 0x08,    7 /* Private */,
       9,    0,   81,    2, 0x08,    8 /* Private */,
      10,    0,   82,    2, 0x08,    9 /* Private */,
      11,    0,   83,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AccountDetail::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AccountDetail *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_ReturnButton_clicked(); break;
        case 1: _t->on_SaveButton_clicked(); break;
        case 2: _t->on_NameEdit_editingFinished(); break;
        case 3: _t->on_MaleChoose_clicked(); break;
        case 4: _t->on_FemaleChoose_clicked(); break;
        case 5: _t->on_SecretChoose_clicked(); break;
        case 6: _t->on_PhoneEdit_editingFinished(); break;
        case 7: _t->on_MailEdit_editingFinished(); break;
        case 8: _t->on_AddressEdit_editingFinished(); break;
        case 9: _t->on_PasswordEdit_editingFinished(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject AccountDetail::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_AccountDetail.offsetsAndSize,
    qt_meta_data_AccountDetail,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AccountDetail_t
, QtPrivate::TypeAndForceComplete<AccountDetail, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *AccountDetail::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccountDetail::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AccountDetail.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AccountDetail::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
