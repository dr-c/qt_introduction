#pragma once

#include <QObject>

class Counter : public QObject
  {
  Q_OBJECT
    int m_value;

  public:
    Counter();

    int value() const;

  public slots :
    void setValue(int i_value);

  signals:
    void valueChanged(int i_new_value);
  };
