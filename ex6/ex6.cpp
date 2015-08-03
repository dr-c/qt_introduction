#include "ex6.h"

#include "Worker.h"

#include <QTime>
#include <QTextStream>
#include <QThread>

ex6::ex6(QWidget *parent)
  : QMainWindow(parent)
  {
  ui.setupUi(this);
  }

ex6::~ex6()
  {
  }

void ex6::on_generateButton_clicked()
  {
  qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
  QString string;
  QTextStream text_stream(&string);
  for (int i = 0; i < ui.randomNumberCounter->value(); ++i)
    text_stream << qrand() << " ";
  ui.dataInput->setPlainText(string);
  }

void ex6::on_manipulatingButton_clicked()
  {
  if (ui.manipulatingButton->text() == "&Start sorting")
    {
    ui.manipulatingButton->setText("&Stop sorting");
    ui.progressBar->reset();
    ui.dataResult->clear();

    QStringList list = ui.dataInput->toPlainText().split(" ", QString::SkipEmptyParts);
    QVector<int> vector;
    for (auto& str : list)  //foreach(QString str, list)
      vector.push_back(str.toInt());

    ui.progressBar->setRange(0, vector.size());

    QThread* thread = new QThread;
    Worker* worker = new Worker(qMove(vector));
    worker->moveToThread(thread);

    QObject::connect(thread, &QThread::started, worker, &Worker::sort);
    QObject::connect(worker, &Worker::processed, this, &ex6::updateProgressBar);

    QObject::connect(this, &ex6::sortingCancelled, worker, &Worker::cancel);

    QObject::connect(worker, &Worker::resultReady, this, &ex6::receiveSortingResult);
    QObject::connect(this, &ex6::resultReceived, worker, &Worker::finished);

    QObject::connect(worker, &Worker::finished, worker, &Worker::deleteLater);
    QObject::connect(worker, &Worker::finished, thread, &QThread::quit);

    QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
    }
  else
    {
    ui.manipulatingButton->setText("&Start sorting");
    ui.dataResult->clear();
    ui.dataResult->setPlainText("Sorting was cancelled.");
    emit sortingCancelled();
    }
  }

void ex6::updateProgressBar(int i_value)
  {
  ui.progressBar->setValue(i_value);
  }

void ex6::receiveSortingResult(QVector<int>* ip_result)
  {
  ui.manipulatingButton->setText("&Start sorting");
  ui.progressBar->setValue(ip_result->size());

  QString string;
  QTextStream text_stream(&string);
  for (int i = 0; i < ip_result->size(); ++i)
    text_stream << ip_result->operator[](i) << " ";
  ui.dataResult->setPlainText(string);
  }
