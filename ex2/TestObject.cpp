#include "TestObject.h"

TestObject::TestObject()
  : QObject()
  {
  }


TestObject::~TestObject()
  {
  }

void TestObject::public_func1()
  {
  }

bool TestObject::public_func2(int i_arg1, double i_arg2)
  {
  Q_UNUSED(i_arg1);
  Q_UNUSED(i_arg2);
  return true;
  }

void TestObject::public_slot1()
  {
  }

bool TestObject::public_slot2(int i_arg1, double i_arg2)
  {
  Q_UNUSED(i_arg1);
  Q_UNUSED(i_arg2);
  return true;
  }