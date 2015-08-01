#pragma once

#include <QObject>

class Counter : public QObject
  {
  Q_OBJECT

  public:
    Counter();
    Counter(QObject* i_obj);
    ~Counter();

    int value() const;

  public slots:
    void setValue(int i_value);

  signals:
    void valueChanged(int i_new_value);

  private:
    int m_value;
  };


class DerivedA : public Counter
  {
  Q_OBJECT

  public:
    DerivedA() {}
    DerivedA(QObject* i_obj) : Counter(i_obj) {}
    DerivedA(int i_value) { setValue(i_value); }
    DerivedA(double i_double) : m_double(i_double) {}
    DerivedA(int i_value, double i_double) : m_double(i_double) { setValue(i_value); }

    void setDouble(double i_double) { m_double = i_double; }
    double getDouble() { return m_double; }

  private:
    double m_double;
  };

class DerivedB : public Counter
  {
  Q_OBJECT

  public:
    DerivedB() {}
    DerivedB(int i_value) { setValue(i_value); }
  };