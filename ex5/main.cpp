#include "Counter.h"

#include <QDebug>
#include <QMetaMethod>

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

  qDebug() << "\nbefore delete parent;";
  delete parent;
  qDebug() << "after delete parent;\n";

  //////////////////////////////////////////////////////////////////////////////

  QObject* pda = new DerivedA;
  QObject* pdb = new DerivedB;

  auto show_func_params = [](QDebug& i_debug, QMetaMethod& i_method)
    {
    auto types = i_method.parameterTypes();
    auto names = i_method.parameterNames();
    for (int i = 0; i < i_method.parameterCount(); ++i)
      {
      i_debug << types[i] << " " << names[i] 
        << (i < i_method.parameterCount() - 1 ? ", " : "");
      }
    };

  auto show_meta_object = [&show_func_params](QObject* i_obj)
    {
    qDebug() << "class " << i_obj->metaObject()->className() << " : " << i_obj->metaObject()->superClass()->className();

    qDebug() << "  {";
    QMetaMethod::Access access = QMetaMethod::Private;
    for (int i = 0; i < i_obj->metaObject()->constructorCount(); ++i)
      {
      //qDebug() << i_obj->metaObject()->constructor(i).methodSignature();
      auto method = i_obj->metaObject()->constructor(i);
      if (access != method.access())
        {
        access = method.access();
        switch (access)
          {
          case QMetaMethod::Private:
            qDebug() << "  private:";
          case QMetaMethod::Protected:
            qDebug() << "  protected:";
          case QMetaMethod::Public:
            qDebug() << "  public:";
          }
        }
      auto debug = qDebug();
      debug << method.typeName() << " " << method.name() << "(";
      show_func_params(debug, method);
      debug << ");";
      }
    qDebug() << "  };";
    };

  show_meta_object(pda);
  show_meta_object(pdb);

  static_cast<Counter*>(pda)->setValue(10);
  pda->setProperty("m_value", 100);
  qDebug().nospace() << "\n" << static_cast<Counter*>(pda)->value();
  qDebug() << pda->property("m_value").toInt();

  //Add dinamic properies:
  pda->setProperty("priority", 5);
  pda->setProperty("name", "test");
  qDebug() << pda->property("priority").toInt();
  qDebug() << pda->property("name").toString();


  delete pda;
  delete pdb;

  return 0;
  }
