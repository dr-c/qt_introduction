#pragma once

#include <QObject>

class Counter : public QObject
  {
  Q_OBJECT
  Q_PROPERTY(int m_value READ value WRITE setValue NOTIFY valueChanged);

  public:
    Q_INVOKABLE Counter();
    Q_INVOKABLE Counter(QObject* i_obj);
    ~Counter();

    int value() const;

  public slots:
    Q_INVOKABLE void setValue(int i_value);

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
    Q_INVOKABLE DerivedA(QObject* i_obj) : Counter(i_obj) {}
    Q_INVOKABLE DerivedA(int i_value) { setValue(i_value); }
    Q_INVOKABLE DerivedA(double i_double) : m_double(i_double) {}
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
    Q_INVOKABLE DerivedB() {}
    DerivedB(int i_value) { setValue(i_value); }
  };