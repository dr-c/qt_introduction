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

  parent->dumpObjectTree();

  auto show_destroy_msg = [](QObject* i_obj)
    {
    qDebug() << i_obj->objectName();
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

  return 0;
  }
