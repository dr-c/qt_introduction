#ifndef EX4_H
#define EX4_H

#include <QtWidgets/QMainWindow>
#include "ui_ex4.h"

class ex4 : public QMainWindow
  {
  Q_OBJECT

  public:
    ex4(QWidget *parent = 0);
    ~ex4();

  private slots:
    void OnSpaceSymbolPressed();
    void on_actionReturn_triggered();

  private:
    Ui::ex4Class ui;
  };

#endif // EX4_H
