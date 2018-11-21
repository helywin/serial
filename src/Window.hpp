//
// Created by jiang on 2018/11/19.
//

#ifndef SERIAL_WINDOW_HPP
#define SERIAL_WINDOW_HPP

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QSpinBox>

//
class Generate;

class Serial;

class SerialView;

class SerialModel;

class SerialSortModel;

class Window : public QMainWindow
{
Q_OBJECT
private:
    QWidget *_central;
    QVBoxLayout *_layout;
    Serial *_serial;
    SerialView *_serial_view;
    SerialModel *_serial_model;
    SerialSortModel *_serial_sort_model;

    QGroupBox *_edit_group;
    QGridLayout *_group_layout;
    QLineEdit *_serial_number;
    QLineEdit *_product_number;
    QLineEdit *_info;
    QLineEdit *_type;
    QSpinBox *_times;
    QPushButton *_generate;
    QPushButton *_insert;
    QPushButton *_gen_insert;
    Generate *_gen;

public:
    explicit Window(QWidget *parent = nullptr);

private:
    void setup();

private slots:

    bool genSerial(int i);

    void insertData();

    void genAndInsert();

protected:
    void closeEvent(QCloseEvent *event) override;
};


#endif //SERIAL_WINDOW_HPP
