#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
  {
  qDebug() << "QDebug() << \"Hello, world!\";";
  std::cout << "std::cout << \"Hello, world!\" << std::endl;" << std::endl;

  return 0;
  }
