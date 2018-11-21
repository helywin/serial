//
// Created by jiang on 2018/11/20.
//

#include <QtCore/QDebug>
#include <QtWidgets/QHeaderView>
#include "SerialView.hpp"

SerialView::SerialView(QAbstractItemModel *model, QWidget *parent) :
        QTableView(parent)
{
    setModel(model);
    setup();
}

void SerialView::setup()
{
    _font = QFont("\"Consolas\",\"微软雅黑\"", 12);
    _font.setLetterSpacing(QFont::PercentageSpacing, 100);
    _font.setWeight(400);
    setFont(_font);
    setSelectionMode(QTableView::SingleSelection);
    setSelectionBehavior(QTableView::SelectRows);
    setHorizontalScrollMode(QTableView::ScrollPerPixel);
    setVerticalScrollMode(QTableView::ScrollPerPixel);
    setAlternatingRowColors(true);

    verticalHeader()->setMinimumWidth(30);
    verticalHeader()->setDefaultAlignment(Qt::AlignCenter);

    setColumnWidth(0, 130);
    setColumnWidth(1, 155);
    setColumnWidth(2, 430);
}
