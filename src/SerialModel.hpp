//
// Created by jiang on 2018/11/20.
//

#ifndef SERIAL_SERIALMODEL_HPP
#define SERIAL_SERIALMODEL_HPP

#include <QtCore/QAbstractTableModel>
class Serial;

class SerialModel : public QAbstractTableModel
{
Q_OBJECT
private:
    Serial *_serial;
public:
    SerialModel(Serial *serial, QObject *parent);

    int rowCount(const QModelIndex &parent) const override;

    int columnCount(const QModelIndex &parent) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    QVariant data(const QModelIndex &index, int role) const override;
//
//    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
//
//    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void genData();
};


#endif //SERIAL_SERIALMODEL_HPP
