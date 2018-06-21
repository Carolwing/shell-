#include "mainwindow.h"
#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cout << " 欢迎使用文件管理系统！" << endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
