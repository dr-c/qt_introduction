#pragma once

#include <QObject>

class TestObject : public QObject
  {
  Q_OBJECT

  public:
    TestObject();
    virtual ~TestObject();

    void public_func1();
    bool public_func2(int i_arg1, double i_arg2);

  public slots:
    void public_slot1();
    bool public_slot2(int i_arg1, double i_arg2);

  signals:
    void signal1();
    void signal2(int i_arg1, double i_arg2);
  };
