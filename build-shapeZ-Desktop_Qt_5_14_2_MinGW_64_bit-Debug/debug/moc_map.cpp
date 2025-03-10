/****************************************************************************
** Meta object code from reading C++ file 'map.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../shapeZ/map.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'map.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Map_t {
    QByteArrayData data[16];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Map_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Map_t qt_meta_stringdata_Map = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Map"
QT_MOC_LITERAL(1, 4, 10), // "stopCreate"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 5), // "order"
QT_MOC_LITERAL(4, 22, 9), // "removeAll"
QT_MOC_LITERAL(5, 32, 1), // "x"
QT_MOC_LITERAL(6, 34, 1), // "y"
QT_MOC_LITERAL(7, 36, 9), // "passLevel"
QT_MOC_LITERAL(8, 46, 10), // "enterStore"
QT_MOC_LITERAL(9, 57, 13), // "createMineral"
QT_MOC_LITERAL(10, 71, 12), // "differDigger"
QT_MOC_LITERAL(11, 84, 5), // "shang"
QT_MOC_LITERAL(12, 90, 5), // "index"
QT_MOC_LITERAL(13, 96, 3), // "xia"
QT_MOC_LITERAL(14, 100, 3), // "zuo"
QT_MOC_LITERAL(15, 104, 3) // "you"

    },
    "Map\0stopCreate\0\0order\0removeAll\0x\0y\0"
    "passLevel\0enterStore\0createMineral\0"
    "differDigger\0shang\0index\0xia\0zuo\0you"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Map[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    2,   67,    2, 0x06 /* Public */,
       7,    0,   72,    2, 0x06 /* Public */,
       8,    0,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   74,    2, 0x0a /* Public */,
      10,    1,   79,    2, 0x08 /* Private */,
      11,    2,   82,    2, 0x08 /* Private */,
      13,    2,   87,    2, 0x08 /* Private */,
      14,    2,   92,    2, 0x08 /* Private */,
      15,    2,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,    3,

       0        // eod
};

void Map::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Map *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stopCreate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->removeAll((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->passLevel(); break;
        case 3: _t->enterStore(); break;
        case 4: _t->createMineral((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->differDigger((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->shang((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->xia((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->zuo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->you((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Map::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::stopCreate)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Map::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::removeAll)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Map::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::passLevel)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Map::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::enterStore)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Map::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Map.data,
    qt_meta_data_Map,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Map::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Map::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Map.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Map::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Map::stopCreate(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Map::removeAll(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Map::passLevel()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Map::enterStore()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
