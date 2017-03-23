#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QDebug>


class Logger
{
public:
  template<typename T>
  static void log(T &obj, QString &text ){
    qDebug() << text
             << "\n============\n"
             << obj << endl;
  }
};

#endif // LOGGER_H
