//
// Created by jiang on 2018/11/20.
//

#ifndef SERIAL_SERIALSORTMODEL_HPP
#define SERIAL_SERIALSORTMODEL_HPP

#include <QtCore/QSortFilterProxyModel>

class SerialSortModel : public QSortFilterProxyModel
{
Q_OBJECT
private:
public:
    explicit SerialSortModel(QObject *parent);
};


#endif //SERIAL_SERIALSORTMODEL_HPP
