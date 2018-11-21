//
// Created by jiang on 2018/11/20.
//

#include <QtCore/QDebug>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDate>
#include "Generate.hpp"

#define GEN_NUM_START 0
#define GEN_NUM_END 9
#define REAL_NUM_START '0'
#define GEN_UCH_START (GEN_NUM_END + 1)
#define GEN_UCH_END (GEN_NUM_END + 26)
#define REAL_UCH_START 'A'
#define GEN_LCH_START (GEN_UCH_END + 1)
#define GEN_LCH_END (GEN_UCH_END + 26)
#define REAL_LCH_START 'a'
#define GEN_NUM1_START (GEN_LCH_END + 1)
#define GEN_NUM1_END (GEN_LCH_END + 10)
#define GEN_NUM2_START (GEN_NUM1_END + 1)
#define GEN_NUM2_END (GEN_NUM1_END + 10)

#define SERIAL_LENGTH 16

QString Generate::genSerial(unsigned int seed)
{
    QRandomGenerator generator(seed);
    //48~57 [0-10] 65~90 [A-Z] 97~122 [a-z]
    //0 ~ 9     [0-9]
    //10 ~ 45   [A-Z]
    //46 ~ 71   [a-z]
    QString s;
    for (int i = 0; i < SERIAL_LENGTH; ++i) {
        s += intToChar(generator.bounded(GEN_NUM_START, GEN_NUM2_END));
    }
    return s;
}

char Generate::intToChar(int i) const
{
    if (i < GEN_NUM_START) {
        return char('-');
    } else if (i <= GEN_NUM_END) {
        return char(i - GEN_NUM_START + REAL_NUM_START);
    } else if (i <= GEN_UCH_END) {
        return char(i - GEN_UCH_START + REAL_UCH_START);
    } else if (i <= GEN_LCH_END) {
        return char(i - GEN_LCH_START + REAL_LCH_START);
    } else if (i <= GEN_NUM1_END) {
        return char(i - GEN_NUM1_START + REAL_NUM_START);
    } else if (i <= GEN_NUM2_END) {
        return char(i - GEN_NUM2_START + REAL_NUM_START);
    } else {
        return char('-');
    }
}

QString Generate::currentDate()
{
    return QDate::currentDate().toString("yyMMdd");
}

QString Generate::genProduct(const QString &last, const QString &type)
{
    int last_index = 0;
    if (last.left(6) == currentDate()) {
        last_index = last.right(5).toUInt();
    }
    if (last_index >= 99999) {
        return QString();
    }
    return currentDate() + type.left(2) + QString("%1").arg(last_index + 1, 5, 10, QChar('0'));
}


