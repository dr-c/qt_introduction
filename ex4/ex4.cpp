#include "ex4.h"

#include <QMessageBox>
#include <QSpinBox>

ex4::ex4(QWidget *parent)
  : QMainWindow(parent)
  {
  ui.setupUi(this);

  QObject::connect(ui.pushButton, &QAbstractButton::clicked, [this]()
    {
    if (ui.progressBar->value() < 100)
      ui.progressBar->setValue(ui.progressBar->value() + 5);
    });

  QObject::connect(ui.pushButton_2, &QAbstractButton::clicked, [this]()
    {
    if (ui.progressBar->value() < 100)
      ui.progressBar->setValue(ui.progressBar->value() + 10);
    });

  QObject::connect(ui.pushButton_3, SIGNAL(clicked()), ui.progressBar, SLOT(reset()));

  QObject::connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(close()));

  ui.horizontalSlider->connect(ui.spinBox, SIGNAL(valueChanged(int)), SLOT(setValue(int)));
  ui.horizontalSlider_2->connect(ui.spinBox_2, SIGNAL(valueChanged(int)), SLOT(setValue(int)));
  ui.horizontalSlider_3->connect(ui.spinBox_3, SIGNAL(valueChanged(int)), SLOT(setValue(int)));

  QObject::connect(ui.horizontalSlider, &QSlider::valueChanged, ui.spinBox, &QSpinBox::setValue);
  QObject::connect(ui.horizontalSlider_2, &QSlider::valueChanged, ui.spinBox_2, &QSpinBox::setValue);
  QObject::connect(ui.horizontalSlider_3, &QSlider::valueChanged, ui.spinBox_3, &QSpinBox::setValue);

  QObject::connect(ui.actionDon_t_press, &QAction::triggered, this, &ex4::OnSpaceSymbolPressed);
  }

ex4::~ex4()
  {

  }

void ex4::OnSpaceSymbolPressed()
  {
  QMessageBox msgBox;
  msgBox.setText("Space button pressed.");
  msgBox.setInformativeText("...");
  msgBox.setStandardButtons(QMessageBox::Ok);
  msgBox.exec();
  }