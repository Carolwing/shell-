#include "newfile.h"
#include "ui_newfile.h"
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

newFile::newFile(QDir NowDir,int i,QWidget *parent) :
    QWidget(parent)
{
  this->NowDir=NowDir;//为当前目录赋值
  if (i==0)
      newlabel=new QLabel(QString::fromLocal8Bit("输入目录名："));
  else
      newlabel=new QLabel(QString::fromLocal8Bit("输入文件名："));
  newlineEdit=new QLineEdit;
  newlabel->setBuddy(newlineEdit);
//输入和编辑栏
  newButton=new QPushButton(QString::fromLocal8Bit("新建"));
  newButton->setDefault(true);
  newButton->setEnabled(false);

  closeButton=new QPushButton(QString::fromLocal8Bit("关闭"));
//新建和取消按钮
  connect(newlineEdit,SIGNAL(textChanged(const QString &)),
          this,SLOT(enablenewButton(const QString &)));//判断新建按钮是否可用
  if (i==0)
      connect(newButton,SIGNAL(clicked()),this,SLOT(newButtonClicked()));//新建目录
  else
      connect(newButton,SIGNAL(clicked()),this,SLOT(newButtonClick()));//新建文件
  connect(closeButton,SIGNAL(clicked()),
          this,SLOT(close()));//点击关闭按钮结束

  QHBoxLayout *LeftLayout=new QHBoxLayout;
  LeftLayout->addWidget(newlabel);
  LeftLayout->addWidget(newlineEdit);
//输入编辑栏水平布局
  QVBoxLayout *rightLayout=new QVBoxLayout;
  rightLayout->addWidget(newButton);
  rightLayout->addWidget(closeButton);
//加上按钮
  QHBoxLayout *mainLayout=new QHBoxLayout;
  mainLayout->addLayout(LeftLayout);
  mainLayout->addLayout(rightLayout);
//总布局
  setLayout(mainLayout);

  setWindowTitle(QString::fromLocal8Bit("新建"));
  setFixedHeight(sizeHint().height());
}

void newFile::newButtonClicked()
{
  QString text=newlineEdit->text();
  std::string str=std::string("mkdir ")+NowDir.absolutePath().toStdString()
          +std::string("/")+text.toStdString();
  int status=system (str.c_str());
  std::string path=NowDir.absoluteFilePath(text).toStdString();
  if (status==0)
  {
      std::string path=NowDir.absoluteFilePath(text).toStdString();
      cout << "您成功新建了目录"<< path<<endl;
  }
  else
  {
      cout << "新建目录"<< path<< "失败！请检查是否在该目录下有相同目录！"<< endl;
  }
  this->close();
}

void newFile::newButtonClick()
{
    QString text=newlineEdit->text();
    std::string str=std::string("touch ")+NowDir.absolutePath().toStdString()
            +std::string("/")+text.toStdString();
    int status=system (str.c_str());
    std::string path=NowDir.absoluteFilePath(text).toStdString();
    if (status==0)
    {
        std::string path=NowDir.absoluteFilePath(text).toStdString();
        cout << "您成功新建了文件"<< path<<endl;
    }
    else
    {
        cout << "新建文件"<< path<< "失败！请检查是否在该目录下有相同目录！"<< endl;
    }
    this->close();
}

void newFile::enablenewButton(const QString &text)
{
  newButton->setEnabled((!text.isEmpty()));
}
