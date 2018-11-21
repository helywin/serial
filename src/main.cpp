//
// Created by jiang on 2018/11/19.
//

#include <QtGui/QFontDatabase>
#include <QtWidgets/QApplication>
#include <QtCore/QDebug>
#include "Window.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window win;
    win.show();
    return QApplication::exec();
}