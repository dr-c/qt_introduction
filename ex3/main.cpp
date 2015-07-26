#include <QDebug>
#include <iostream>

#include "Counter.h"

int main(int argc, char *argv[])
  {
  qDebug() << "QDebug() << \"Hello, world!\";";
  std::cout << "std::cout << \"Hello, world!\" << std::endl;" << std::endl;

  Counter a, b;
  QObject::connect(&a, SIGNAL(valueChanged(int)), &b, SLOT(setValue(int)));

  qDebug() << endl << "before a.setValue(12):\ta=" << a.value() << "\tb=" << b.value();
  a.setValue(12); // a.value() == 12, b.value() == 12
  qDebug() << "after a.setValue(12):\ta=" << a.value() << "\tb=" << b.value() << endl;

  qDebug() << "before b.setValue(48):\ta=" << a.value() << "\tb=" << b.value();
  b.setValue(48); // a.value() == 12, b.value() == 48
  qDebug() << "after b.setValue(48):\ta=" << a.value() << "\tb=" << b.value() << endl;

  QObject::connect(&b, SIGNAL(valueChanged(int)), &a, SLOT(setValue(int)));

  qDebug() << "before b.setValue(148):\ta=" << a.value() << "\tb=" << b.value();
  b.setValue(148); // a.value() == 148, b.value() == 148
  qDebug() << "after b.setValue(148):\ta=" << a.value() << "\tb=" << b.value() << endl;

  QObject::disconnect(&a, SIGNAL(valueChanged(int)), 0, 0);

  qDebug() << endl << "before a.setValue(212):\ta=" << a.value() << "\tb=" << b.value();
  a.setValue(212); // a.value() == 212, b.value() == 148
  qDebug() << "after a.setValue(212):\ta=" << a.value() << "\tb=" << b.value() << endl;

  return 0;
  }
