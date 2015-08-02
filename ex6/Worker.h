#pragma once

#include <QObject>
#include <QThread>
#include <QVector>

class Worker : public QObject
  {
  Q_OBJECT

  public:
    Worker(const QVector<int>& i_data); // Creates copy
    Worker(QVector<int>&& i_data); // Swaps i_data and m_data
    ~Worker();

  public slots:
    void sort();
    void cancel();

  signals:
    void resultReady(QVector<int>*);
    void processed(int);
    void finished();

  private:
    bool m_is_interrupted;
    QVector<int> m_data;
  };

class WorkerThread : public QThread
  {
  Q_OBJECT

  public:
    WorkerThread();
    ~WorkerThread();


  };