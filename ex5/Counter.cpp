#include "Counter.h"


Counter::Counter()
  : QObject()
  , m_value(0)
  {
  }

Counter::Counter(QObject* i_obj)
  : QObject(i_obj)
  , m_value(0)
  {
  }

Counter::~Counter()
  {
  }

int Counter::value() const
  {
  return m_value;
  }

void Counter::setValue(int i_value)
  {
  if (i_value != m_value)
    {
    m_value = i_value;
    emit valueChanged(m_value);
    }
  }
