//
// Created by jiang on 2018/11/20.
//

#include "Serial.hpp"
#include "SerialModel.hpp"

SerialModel::SerialModel(Serial *serial, QObject *parent) :
        QAbstractTableModel(parent),
        _serial(serial)
{

}

int SerialModel::rowCount(const QModelIndex &parent) const
{
    return _serial->cells().size();
}

int SerialModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant SerialModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal) {
        switch (role) {
            case Qt::DisplayRole:
                return QVariant(_serial->header()[section]);
            default:
                return QVariant();
        }
    } else {
        switch (role) {
            case Qt::DisplayRole:
                return QVariant(section);
            default:
                return QVariant();
        }
    }
}

QVariant SerialModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }
    int row = index.row();
    int col = index.column();
    if (row >= _serial->size()) {
        qCritical("CurveModel::data 数组越界");
    }
    const Serial::Cell &cell = (*_serial)[row];
    switch (role) {
        case Qt::DisplayRole:
            switch (col) {
                case 0:
                    return QVariant(cell.product());
                case 1:
                    return QVariant(cell.serial());
                case 2:
                    return QVariant(cell.info());
                default:
                    return QVariant();
            }
        case Qt::EditRole:
        default:
            return QVariant();
    }
}


void SerialModel::genData()
{
    beginResetModel();
    endResetModel();
}
