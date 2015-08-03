#ifndef EX6_H
#define EX6_H

#include <QtWidgets/QMainWindow>
#include "ui_ex6.h"

class ex6 : public QMainWindow
  {
  Q_OBJECT

  public:
    ex6(QWidget *parent = 0);
    ~ex6();

  private Q_SLOTS:
    void on_generateButton_clicked();
    void on_manipulatingButton_clicked();
    
    void updateProgressBar(int i_value);
    void receiveSortingResult(QVector<int>* ip_result);

  Q_SIGNALS:
    void sortingCancelled();
    void resultReceived();

  private:
    Ui::ex6Class ui;
  };

#endif // EX6_H
