//
// Created by jiang on 2018/11/20.
//

#ifndef SERIAL_RANDOMGEN_HPP
#define SERIAL_RANDOMGEN_HPP

#include <QtCore/QString>

class Generate
{
private:
public:
    Generate() = default;

    ~Generate() = default;

    QString genSerial(unsigned int seed);

    QString genProduct(const QString &last, const QString &type);

    static QString currentDate();

private:
    char intToChar(int i) const;
};


#endif //SERIAL_RANDOMGEN_HPP
