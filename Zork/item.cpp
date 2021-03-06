  #include "item.h"
  #include <QDebug>

  Item::Item(QString inDescription) {
      description = inDescription;
  }

  Item::~Item(){
     qDebug() << "Item's destructor has been called" << endl;
  }

  QString Item::getDescription()
  {
      return description;
  }

  QDebug &operator<<( QDebug &out, Item &I ){
    out << I.getDescription();
    return out;
  }
