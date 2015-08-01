#include "Counter.h"

#include <QDebug>

int main(int argc, char *argv[])
  {
  Counter* parent = new Counter;
  DerivedA* a1 = new DerivedA(parent);
  Counter* c2 = new Counter(parent);
  Counter* c3 = new Counter(parent);
  Counter* c4 = new Counter(c3);
  QObject* o5 = new QObject(parent);

  parent->setObjectName("parent");
  a1->setObjectName("a1");
  c2->setObjectName("c2");
  c3->setObjectName("c3");
  c4->setObjectName("c4");
  o5->setObjectName("o5");

  //parent->setValue(0);
  //a1->setValue(1);
  //a1->setDouble(111.111);
  //c2->setValue(2);
  //c3->setValue(3);
  //c4->setValue(4);

  auto show_destroy_msg = [](QObject* i_obj)
    {
    QDebug debug = qDebug() << i_obj->objectName();
    //if (DerivedA* p = qobject_cast<DerivedA*>(i_obj))
    //  debug << p->value() << p->getDouble();
    //else if (Counter* p = qobject_cast<Counter*>(i_obj))
    //  debug << p->value();
    //if (i_obj->inherits("Counter"))
    //  qDebug() << static_cast<Counter*>(i_obj)->value();
    //if (Counter* p = dynamic_cast<Counter*>(i_obj))
    //  qDebug() << p->value();
    //else
    //  qDebug() << "Some other object";
    };

  QObject::connect(parent, &QObject::destroyed, show_destroy_msg);
  QObject::connect(parent, &QObject::destroyed, show_destroy_msg); //connected twice!
  QObject::connect(a1, &QObject::destroyed, show_destroy_msg);
  QObject::connect(c2, &QObject::destroyed, show_destroy_msg);
  QObject::connect(c3, &QObject::destroyed, show_destroy_msg);
  QObject::connect(c4, &QObject::destroyed, show_destroy_msg);
  QObject::connect(o5, &QObject::destroyed, show_destroy_msg);

  qDebug() << "before delete parent;";
  delete parent;
  qDebug() << "after delete parent;";

  //qDebug() << i_obj->metaObject()->className();

  //qDebug() << o1->metaObject()->className();
  //qDebug() << o2->metaObject()->className();

  //qDebug() << a.metaObject()->constructorCount();
  //qDebug() << b.metaObject()->constructorCount();
  
  return 0;
  }
