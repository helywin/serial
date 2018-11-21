//
// Created by jiang on 2018/11/20.
//

#ifndef SERIAL_SERIALVIEW_HPP
#define SERIAL_SERIALVIEW_HPP

#include <QtWidgets/QTableView>
#include <QtCore/QSortFilterProxyModel>

class SerialView : public QTableView
{
Q_OBJECT
private:
    QFont _font;
public:
    explicit SerialView(QAbstractItemModel *model, QWidget *parent);

private:
    void setup();
};


#endif //SERIAL_SERIALVIEW_HPP
