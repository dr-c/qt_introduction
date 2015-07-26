#include <QDebug>
#include <iostream>

#include "Counter.h"

int main(int argc, char *argv[])
  {
  Counter a, b;

  qDebug() << "0) init\ta=" << a.value() << "\tb=" << b.value();

  QObject::connect(&a, SIGNAL(valueChanged(int)), &b, SLOT(setValue(int)));
  qDebug() << endl << "a connected to b" << endl;

  a.setValue(12); // a.value() == 12, b.value() == 12
  qDebug() << "1) a changed to 12\ta=" << a.value() << "\tb=" << b.value();
  
  b.setValue(48); // a.value() == 12, b.value() == 48
  qDebug() << "2) b changed to 48\ta=" << a.value() << "\tb=" << b.value();

  QObject::connect(&b, SIGNAL(valueChanged(int)), &a, SLOT(setValue(int)));
  qDebug() << endl << "b connected to a" << endl;

  b.setValue(148); // a.value() == 148, b.value() == 148
  qDebug() << "3) b changed to 148\ta=" << a.value() << "\tb=" << b.value();

  QObject::disconnect(&a, SIGNAL(valueChanged(int)), 0, 0);
  qDebug() << endl << "a disconnected from b" << endl;

  a.setValue(212); // a.value() == 212, b.value() == 148
  qDebug() << "4) a changed to 212\ta=" << a.value() << "\tb=" << b.value() << endl;

  return 0;
  }