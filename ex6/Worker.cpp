#include "Worker.h"
#include <utility>

Worker::Worker(const QVector<int>& i_data)
  : m_is_interrupted(false)
  , m_data(i_data)
  {
  }

Worker::Worker(QVector<int>&& i_data)
  : m_is_interrupted(false)
  {
  m_data.swap(i_data);
  }


Worker::~Worker()
  {
  }

void Worker::sort()
  {
  int i = 0;
  int progress = 0;
  while (i < m_data.size() - 1)
    {
    if (m_is_interrupted)
      {
      emit finished();
      return;
      }
    if (i > progress)
      {
      progress = i;
      emit processed(progress);
      }
    if (m_data[i + 1] < m_data[i])
      {
      std::swap(m_data[i + 1], m_data[i]);
      i = 0;
      }
    else
      ++i;
    }
  emit resultReady(&m_data);
  }

void Worker::cancel()
  {
  m_is_interrupted = true;
  }
