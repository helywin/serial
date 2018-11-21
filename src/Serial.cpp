//
// Created by jiang on 2018/11/20.
//

#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include "Serial.hpp"


Serial::Serial() :
_edit(false)
{
    _header = header();
}


QDataStream &operator<<(QDataStream &stream, const Serial &serial)
{
    return stream;
}

QDataStream &operator>>(QDataStream &stream, Serial &serial)
{
    return stream;
}

bool Serial::loadFromCsv(const QString &name)
{
    QFile f(name);
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!f.isOpen()) {
        return false;
    }
    QTextStream stream;
    stream.setDevice(&f);
    stream.setCodec("gbk");
    QString s = stream.readLine();
    while (!stream.atEnd()) {
        Cell cell;
        s = stream.readLine();
        QStringList list = s.split(',');
        if (list.isEmpty() || list.size() != 3) {
            return false;
        }
        cell.setProduct(list[0]);
        cell.setSerial(list[1]);
        cell.setInfo(list[2]);
        _cells.append(qMove(cell));
    }
    return true;
}

bool Serial::dumpToCsv(const QString &name)
{
    QFile f(name);
    f.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
    if (!f.isOpen()) {
        return false;
    }
    QTextStream stream;
    stream.setDevice(&f);
    stream.setCodec("gbk");
    stream << header().join(',') + "\n";
    for (const auto &cell : _cells) {
        QStringList list;
        list.append(cell.product());
        list.append(cell.serial());
        list.append(cell.info());
        stream << list.join(',') + "\n";
    }
    return true;
}

QStringList Serial::header() const
{
    return QStringList({"产品号", "序列号", "备注"});
}
