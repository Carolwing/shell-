#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stdio.h>
using namespace std;
#define CURRENT "/home/carolwing/FileOperatorTest"
#define WHEREFIND "/home/carolwing/fileoperator/findfile.sh"
MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent)
{
    system("cd "CURRENT);
    createNewfile();
    createOpenfile();
    createCopyfile();
    createDeletefile();
    createRenamefile();
    createZipfile();
    createUnzipfile();
    createFindfile();
    createabutton();
    createexitbutton();
//创建按钮们

    allfile=new QTextBrowser();
    dir=QDir(CURRENT);
    nowdir=new QLabel(dir.absolutePath());
    QStringList nameFilters;
    nameFilters<<"*";
    QStringList files=dir.entryList
            (nameFilters,
             QDir::Dirs,
             QDir::Name);
    int i;
    QString filename;
    for (i=0;i<files.size();i++)
    {
        filename+=files[i];
        filename+=QString::fromLocal8Bit("/");
        filename+="\n";
    }//读取所有目录
    files=dir.entryList
            (nameFilters,
             QDir::Files,
             QDir::Name);
    for (i=0;i<files.size();i++)
    {
        filename+=files[i];
        filename+="\n";
    }//读取所有文件
    allfile->setText(filename);
//创建状态栏以及文件列表
    QHBoxLayout *ButtonLayout=new QHBoxLayout;
    ButtonLayout->addWidget(newfile);
    ButtonLayout->addWidget(openfile);
    ButtonLayout->addWidget(copyfile);
    ButtonLayout->addWidget(deletefile);
    ButtonLayout->addWidget(renamefile);
    ButtonLayout->addWidget(zipfile);
    ButtonLayout->addWidget(unzipfile);
    ButtonLayout->addWidget(findfile);
    ButtonLayout->addWidget(exitbutton);
    ButtonLayout->addWidget(abutton);
//按钮水平布局
    QVBoxLayout *MidiumLayout=new QVBoxLayout;
    MidiumLayout->addLayout(ButtonLayout);
    MidiumLayout->addWidget(nowdir);
//按钮状态栏垂直布局
    QVBoxLayout *AllFileLayout=new QVBoxLayout;
    AllFileLayout->addLayout(MidiumLayout);
    AllFileLayout->addWidget(allfile);
//总布局
    setLayout(AllFileLayout);
    setWindowTitle(QString::fromLocal8Bit("文件管理系统"));
    setFixedHeight(sizeHint().height());
//界面初始化

    //按钮新建动作
    connect(newdirname,SIGNAL(triggered()),this,SLOT(gotonewdir()));
    connect(newfilename,SIGNAL(triggered()),this,SLOT(gotonewfile()));

    //按钮打开动作
    connect(opendirname,SIGNAL(triggered()),this,SLOT(gotoopendir()));
    connect(openfilename,SIGNAL(triggered()),this,SLOT(gotoopenfile()));

    //按钮复制动作
    connect(copydirname,SIGNAL(triggered()),this,SLOT(gotocopydir()));
    connect(copyfilename,SIGNAL(triggered()),this,SLOT(gotocopyfile()));

    //按钮删除动作
    connect(deletedirname,SIGNAL(triggered()),this,SLOT(gotodeletedir()));
    connect(deletefilename,SIGNAL(triggered()),this,SLOT(gotodeletefile()));

    //按钮重命名动作
    connect(renamedirname,SIGNAL(triggered()),this,SLOT(gotorenamedir()));
    connect(renamefilename,SIGNAL(triggered()),this,SLOT(gotorenamefile()));

    //按钮压缩动作
    connect(zipfile,SIGNAL(clicked()),this,SLOT(gotozip()));

    //按钮解压缩动作
    connect(unzipfile,SIGNAL(clicked()),this,SLOT(gotounzip()));

    //按钮查找动作
    connect(findfile,SIGNAL(clicked()),this,SLOT(gotofind()));


    connect(abutton,SIGNAL(clicked()),this,SLOT(RushText()));
    connect(exitbutton,SIGNAL(clicked()),this,SLOT(exitWindow()));
}

void MainWindow::createNewfile()
{
    newfile=new QPushButton();
    newmenu=new QMenu();
    newdirname=new QAction(newmenu);
    newfilename=new QAction(newmenu);
    newmenu->addAction(newdirname);
    newmenu->addAction(newfilename);

    newfile->setMenu(newmenu);

    newfile->setText(QString::fromLocal8Bit("新建"));
    newdirname->setText(QString::fromLocal8Bit("新建目录"));
    newfilename->setText(QString::fromLocal8Bit("新建文件"));
}

void MainWindow::createOpenfile()
{
    openfile=new QPushButton();
    openmenu=new QMenu();
    opendirname=new QAction(openmenu);
    openfilename=new QAction(openmenu);
    openmenu->addAction(opendirname);
    openmenu->addAction(openfilename);

    openfile->setMenu(openmenu);

    openfile->setText(QString::fromLocal8Bit("打开"));
    opendirname->setText(QString::fromLocal8Bit("打开目录"));
    openfilename->setText(QString::fromLocal8Bit("打开文件"));
}


void MainWindow::createCopyfile()
{
    copyfile=new QPushButton();
    copymenu=new QMenu();
    copydirname=new QAction(copymenu);
    copyfilename=new QAction(copymenu);
    copymenu->addAction(copydirname);
    copymenu->addAction(copyfilename);

    copyfile->setMenu(copymenu);

    copyfile->setText(QString::fromLocal8Bit("复制"));
    copydirname->setText(QString::fromLocal8Bit("复制目录"));
    copyfilename->setText(QString::fromLocal8Bit("复制文件"));
}

void MainWindow::createDeletefile()
{
    deletefile=new QPushButton();
    deletemenu=new QMenu();
    deletedirname=new QAction(deletemenu);
    deletefilename=new QAction(deletemenu);
    deletemenu->addAction(deletedirname);
    deletemenu->addAction(deletefilename);

    deletefile->setMenu(deletemenu);

    deletefile->setText(QString::fromLocal8Bit("删除"));
    deletedirname->setText(QString::fromLocal8Bit("删除目录"));
    deletefilename->setText(QString::fromLocal8Bit("删除文件"));
}

void MainWindow::createRenamefile()
{
    renamefile=new QPushButton();
    renamemenu=new QMenu();
    renamedirname=new QAction(renamemenu);
    renamefilename=new QAction(renamemenu);
    renamemenu->addAction(renamedirname);
    renamemenu->addAction(renamefilename);

    renamefile->setMenu(renamemenu);

    renamefile->setText(QString::fromLocal8Bit("重命名"));
    renamedirname->setText(QString::fromLocal8Bit("重命名目录"));
    renamefilename->setText(QString::fromLocal8Bit("重命名文件"));
}

void MainWindow::createZipfile()
{
    zipfile=new QPushButton();
    zipfile->setText(QString::fromLocal8Bit("压缩"));
}

void MainWindow::createUnzipfile()
{
    unzipfile=new QPushButton();
    unzipfile->setText(QString::fromLocal8Bit("解压缩"));
}

void MainWindow::createFindfile()
{
    findfile=new QPushButton();
    findfile->setText(QString::fromLocal8Bit("查找"));
}

void MainWindow::createabutton()
{
    abutton=new QPushButton();
    abutton->setText(QString::fromLocal8Bit("刷新"));
}

void MainWindow::createexitbutton()
{
    exitbutton=new QPushButton();
    exitbutton->setText(QString::fromLocal8Bit("退出"));
}




void MainWindow::gotonewdir()
{
    newFile *NewWidget=new newFile(dir,0);
    NewWidget->show();
}

void MainWindow::gotonewfile()
{
    newFile *NewWidget=new newFile(dir,1);
    NewWidget->show();
}

void MainWindow::gotoopendir()
{
    openFile *OpenWidget=new openFile(dir,0);
    OpenWidget->show();
}

void MainWindow::gotoopenfile()
{
    openFile *OpenWidget=new openFile(dir,1);
    OpenWidget->show();
}

void MainWindow::gotocopydir()
{
    copyFile *copyWidget=new copyFile(dir,0);
    copyWidget->show();
}

void MainWindow::gotocopyfile()
{
    copyFile *copyWidget=new copyFile(dir,1);
    copyWidget->show();
}

void MainWindow::gotodeletedir()
{
    deleteFile *deleteWidget=new deleteFile(dir,0);
    deleteWidget->show();
}

void MainWindow::gotodeletefile()
{
    deleteFile *deleteWidget=new deleteFile(dir,1);
    deleteWidget->show();
}

void MainWindow::gotorenamedir()
{
    renameFile *renameWidget=new renameFile(dir,0);
    renameWidget->show();
}

void MainWindow::gotorenamefile()
{
    renameFile *renameWidget=new renameFile(dir,1);
    renameWidget->show();
}

void MainWindow::gotozip()
{
    cout << "压缩文件" << "————————————————" << endl;
    QString f=QString::fromLocal8Bit("ls -ups1 ")+dir.absolutePath();
    system(f.toStdString().c_str());
    cout<< "输入想压缩的目录或文件数目："<<endl;
    int num;
    cin >>num;
    if (num!=0)
    {
        cout <<"输入新的压缩文件名称："<<endl;
        string newName;
        cin>>newName;
        for (int i=0;i<num;i++)
        {
            cout << "输入想压缩的第"<<i+1<<"个目录或文件名"<<endl;
            string name;
            cin >>name;
            if (name!="")
            {
                std::string str=std::string("cp -r ") + dir.absolutePath().toStdString()//cp 目录/文件 目录/文件.copy
                        +std::string("/") + name
                        +std::string(" ")
                        +std::string("./")+name;
                int status=system (str.c_str());
                if (status==0)
                {
                  string yasuo=("zip -r ")+dir.absolutePath().toStdString()
                        +"/"+newName+" "+"./"+name;
                  system(yasuo.c_str());
                  string shanchu=string("rm -rf ")+"./"+name;
                  system(shanchu.c_str());
                }
            }
        }
    }
            cout << "压缩结束" << "——————————————————"<< endl;
}

void MainWindow::gotounzip()
{
    cout << "解压缩文件" << "————————————————" << endl;
    QString f=QString::fromLocal8Bit("ls -ups1 ")+dir.absolutePath();
    system(f.toStdString().c_str());
    cout << "输入压缩文件名称：" <<endl;
    string name;
    cin>>name;
    cout << "解压缩到的目录名称(可新建)：" <<endl;
    string d;
    cin >> d;
    string jieyasuo=string("unzip -d ")+dir.absolutePath().toStdString()+string("/")+d
            +string(" ")+dir.absolutePath().toStdString()+string("/")+name;
    system(jieyasuo.c_str());
    cout << "解压缩结束"<< "—————————————————"<<endl;
}

void MainWindow::gotofind()
{
    cout << "查找文件" << "————————————————" << endl;
    system("chmod +x "WHEREFIND);
    system(WHEREFIND);
    cout << "查找结束" << endl;
}




void MainWindow::RushText()
{
    dir=openFile::getDir();
    nowdir->setText(dir.absolutePath());
    allfile->clear();
    QStringList nameFilters;
    nameFilters<<"*";
    QStringList files=dir.entryList
            (nameFilters,
             QDir::Dirs,
             QDir::Name);
    int i;
    QString filename;
    for (i=0;i<files.size();i++)
    {
        filename+=files[i];
        filename+=QString::fromLocal8Bit("/");
        filename+="\n";
    }
    files=dir.entryList
            (nameFilters,
             QDir::Files,
             QDir::Name);
    for (i=0;i<files.size();i++)
    {
        filename+=files[i];
        filename+="\n";
    }
    QApplication::processEvents();
    allfile->setText(filename);
    this->show();
}

void MainWindow::exitWindow()
{
    printf("%s","最后祝您身体健康，再见！\n");
    close();
}
