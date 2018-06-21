#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QtGui>
#include "newfile.h"
#include "openfile.h"
#include "copyfile.h"
#include "deletefile.h"
#include "renamefile.h"


class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);//构造函数
    void createNewfile();//创建新建菜单
    void createOpenfile();//创建打开菜单
    void createCopyfile();//创建复制菜单
    void createDeletefile();//创建删除菜单
    void createRenamefile();//创建重命名菜单
    void createZipfile();//创建压缩按钮
    void createUnzipfile();//创建解压缩按钮
    void createFindfile();//创建查找按钮
    void createabutton();//创建刷新按钮
    void createexitbutton();//创造退出按钮

private slots:
    void gotonewdir();//新建目录操作
    void gotonewfile();//新建文件操作
    void gotoopendir();//打开目录操作
    void gotoopenfile();//打开文件操作
    void gotocopydir();//复制目录操作
    void gotocopyfile();//复制文件操作
    void gotodeletedir();//删除目录操作
    void gotodeletefile();//删除文件操作
    void gotorenamedir();//重命名目录操作
    void gotorenamefile();//重命名文件操作
    void gotozip();//压缩文件操作
    void gotounzip();//解压缩文件操作
    void gotofind();//查找文件操作


    void RushText();//刷新操作
    void exitWindow();

private:
    QDir dir;//当前目录
    QPushButton *newfile;
    QPushButton *openfile;
    QPushButton *copyfile;
    QPushButton *deletefile;
    QPushButton *renamefile;
    QPushButton *zipfile;
    QPushButton *unzipfile;
    QPushButton *findfile;
    QPushButton *abutton;
    QPushButton *exitbutton;
    //选项们
    QLabel *nowdir;//当前状态栏/地址
    QTextBrowser *allfile;//当前状态栏下所有文件

    QMenu *newmenu;
    QAction *newdirname;
    QAction *newfilename;

    QMenu *openmenu;
    QAction *opendirname;
    QAction *openfilename;

    QMenu *copymenu;
    QAction *copydirname;
    QAction *copyfilename;

    QMenu *deletemenu;
    QAction *deletedirname;
    QAction *deletefilename;

    QMenu *renamemenu;
    QAction *renamedirname;
    QAction *renamefilename;
//下拉菜单们
};

#endif // MAINWINDOW_H
