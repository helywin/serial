//
// Created by jiang on 2018/11/19.
//

#include <QtCore/QTime>
#include <QtCore/QDebug>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include "Window.hpp"
#include "SerialView.hpp"
#include "SerialModel.hpp"
#include "SerialSortModel.hpp"
#include "Serial.hpp"
#include "Generate.hpp"

Window::Window(QWidget *parent) :
        QMainWindow(parent)
{
    setup();
}

void Window::setup()
{
    setWindowTitle("序列号生成");
    resize(800, 600);
    QApplication::setStyle("fusion");
    QApplication::setFont(QFont("微软雅黑", 9));
    _central = new QWidget(this);
    setCentralWidget(_central);
    _layout = new QVBoxLayout(_central);
    _central->setLayout(_layout);
    _gen = new Generate;
    _serial = new Serial;
    _serial->loadFromCsv("data.csv");
    _serial_model = new SerialModel(_serial, _central);
    _serial_sort_model = new SerialSortModel(_central);
    _serial_sort_model->setSourceModel(_serial_model);
    _serial_view = new SerialView(_serial_sort_model, _central);
    _layout->addWidget(_serial_view);

    _edit_group = new QGroupBox("编辑", _central);
    _group_layout = new QGridLayout(_edit_group);
    _edit_group->setLayout(_group_layout);
    _serial_number = new QLineEdit(_edit_group);
    _serial_number->setReadOnly(true);
    _product_number = new QLineEdit(_edit_group);
    _product_number->setReadOnly(true);
    _info = new QLineEdit(_edit_group);
    _type = new QLineEdit(_edit_group);
    _type->setInputMask(QString("99"));
    _type->setText("01");
    _generate = new QPushButton("生成", _edit_group);
    _insert = new QPushButton("保存", _edit_group);
    _gen_insert = new QPushButton("一键", _edit_group);
    _times = new QSpinBox(_edit_group);
    _times->setPrefix("生成");
    _times->setSuffix("次");
    _times->setValue(1);
    _times->setMinimum(1);
    _times->setMaximum(99999);
    _group_layout->addWidget(new QLabel("产品号", _edit_group), 0, 0);
    _group_layout->addWidget(new QLabel("序列号", _edit_group), 1, 0);
    _group_layout->addWidget(new QLabel("备注", _edit_group), 2, 0);
    _group_layout->addWidget(new QLabel("产品类型(00-99)", _edit_group), 3, 0);
    _group_layout->addWidget(_product_number, 0, 1);
    _group_layout->addWidget(_serial_number, 1, 1);
    _group_layout->addWidget(_info, 2, 1);
    _group_layout->addWidget(_type, 3, 1);
    _group_layout->addWidget(_generate, 0, 2, 1, 2);
    _group_layout->addWidget(_insert, 1, 2, 1, 2);
    _group_layout->addWidget(_times, 2, 2);
    _group_layout->addWidget(_gen_insert, 3, 2);
    _layout->addWidget(_edit_group);

    connect(_generate, &QPushButton::clicked, this, &Window::genSerial, Qt::DirectConnection);
    connect(_insert, &QPushButton::clicked, this, &Window::insertData, Qt::DirectConnection);
    connect(_gen_insert, &QPushButton::clicked, this, &Window::genAndInsert, Qt::DirectConnection);
}

bool Window::genSerial(int i)
{
    Generate::currentDate();
    QString serial = _gen->genSerial((unsigned) QTime::currentTime().msecsSinceStartOfDay() + i);
    _serial_number->setText(serial);
    QString product;
    if (_serial->cells().isEmpty()) {
        product = _gen->genProduct(QString(), _type->text());
    } else {
        product = _gen->genProduct(_serial->cells().last().product(), _type->text());
    }
//    qDebug() << product;
    if (product.isEmpty()) {
        return false;
    }
    _product_number->setText(product);
    return true;
}

void Window::insertData()
{
    Serial::Cell cell;
    cell.setProduct(_product_number->text());
    cell.setSerial(_serial_number->text());
    cell.setInfo(_info->text().replace(",", ""));
    _serial->cells().append(qMove(cell));
    _serial_model->genData();
}

void Window::closeEvent(QCloseEvent *event)
{
    if (_serial->edited()) {
        _serial->dumpToCsv("data.csv");
    }
}

void Window::genAndInsert()
{
    setCursor(Qt::CursorShape::BusyCursor);
    for (int i = 0; i < _times->value(); ++i) {
        if (!genSerial(i)) {
            QMessageBox::warning(this, "警告", "今日生成数据超过99999！");
            break;
        }
        insertData();
        _serial_view->scrollToBottom();
        _serial->setEdited();
    }
    setCursor(Qt::CursorShape::ArrowCursor);
}
