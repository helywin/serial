//
// Created by jiang on 2018/11/20.
//

#ifndef SERIAL_SERIAL_HPP
#define SERIAL_SERIAL_HPP

#include <QtCore/QString>
#include <QtCore/qvector.h>

class Serial
{
public:
    class Cell
    {
    private:
        QString _product;
        QString _serial;
        QString _info;
    public:
        inline const QString &product() const { return _product; }

        inline void setProduct(const QString &v) { _product = v; }

        inline const QString &serial() const { return _serial; }

        inline void setSerial(const QString &v) { _serial = v; }

        inline const QString &info() const { return _info; }

        inline void setInfo(const QString &v) { _info = v; }
    };

private:
    QVector<Cell> _cells;
    QStringList _header;
    bool _edit;
public:
    Serial();

    friend QDataStream &operator<<(QDataStream &stream, const Serial &serial);

    friend QDataStream &operator>>(QDataStream &stream, Serial &serial);

    bool loadFromCsv(const QString &name);

    bool dumpToCsv(const QString &name);

    inline int size() const
    {
        if (_cells.isEmpty()) {
            return 0;
        } else {
            return _cells.size();
        }
    };

    QStringList header() const;

    inline const Cell &operator[](int index) const
    {
        Q_ASSERT(index >=0 && index < _cells.size());
        return _cells[index];
    }

    inline Cell &operator[](int index)
    {
        Q_ASSERT(index >=0 && index < _cells.size());
        return _cells[index];
    }

    inline const QVector<Cell> &cells() const { return _cells; }

    inline QVector<Cell> &cells() { return _cells; }

    inline void setEdited() { _edit = true; }

    inline bool edited() const { return _edit; }
};

QDataStream &operator<<(QDataStream &stream, const Serial &serial);

QDataStream &operator>>(QDataStream &stream, Serial &serial);


#endif //SERIAL_SERIAL_HPP
