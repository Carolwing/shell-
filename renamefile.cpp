#include "renamefile.h"
#include "ui_renamefile.h"
#include <string>
#include <iostream>
using namespace std;

renameFile::renameFile(QDir NowDir,int i,QWidget *parent) :
    QWidget(parent)
{
  this->NowDir=NowDir;//为当前目录赋值
  if (i==0)
  {
      renamelabel=new QLabel(QString::fromLocal8Bit("输入原目录名："));
      renamenewlabel=new QLabel(QString::fromLocal8Bit("输入新目录名："));
  }
  else
  {
      renamelabel=new QLabel(QString::fromLocal8Bit("输入原文件名："));
      renamenewlabel=new QLabel(QString::fromLocal8Bit("输入新文件名："));
  }
  renamelineEdit=new QLineEdit;
  renamenewlineEdit=new QLineEdit;
  renamelabel->setBuddy(renamelineEdit);
  renamenewlabel->setBuddy(renamenewlineEdit);
//输入和编辑栏
  renameButton=new QPushButton(QString::fromLocal8Bit("重命名"));
  renameButton->setDefault(true);
  renameButton->setEnabled(false);

  closeButton=new QPushButton(QString::fromLocal8Bit("关闭"));
//新建和取消按钮
  connect(renamelineEdit,SIGNAL(textChanged(const QString &)),
          this,SLOT(enablerenameButton(const QString &)));//判断重命名按钮是否可用
  if (i==0)
      connect(renameButton,SIGNAL(clicked()),this,SLOT(renameButtonClicked()));//重命名目录
  else
      connect(renameButton,SIGNAL(clicked()),this,SLOT(renameButtonClick()));//重命名文件
  connect(closeButton,SIGNAL(clicked()),
          this,SLOT(close()));//点击关闭按钮结束

  QHBoxLayout *LeftLayout=new QHBoxLayout;
  LeftLayout->addWidget(renamelabel);
  LeftLayout->addWidget(renamelineEdit);
//输入编辑栏水平布局

  QHBoxLayout *newLayout=new QHBoxLayout;
  newLayout->addWidget(renamenewlabel);
  newLayout->addWidget(renamenewlineEdit);

  QVBoxLayout *rightLayout=new QVBoxLayout;
  rightLayout->addWidget(renameButton);
  rightLayout->addWidget(closeButton);
//加上按钮

  QVBoxLayout *EnterLayout=new QVBoxLayout;
  EnterLayout->addLayout(LeftLayout);
  EnterLayout->addLayout(newLayout);

  QHBoxLayout *mainLayout=new QHBoxLayout;
  mainLayout->addLayout(EnterLayout);
  mainLayout->addLayout(rightLayout);
//总布局
  setLayout(mainLayout);

  setWindowTitle(QString::fromLocal8Bit("重命名"));
  setFixedHeight(sizeHint().height());
}

void renameFile::renameButtonClicked()
{
  QString text=renamelineEdit->text();
  QString text2=renamenewlineEdit->text();
  std::string str=std::string("mv ") + NowDir.absoluteFilePath(text).toStdString()
          +std::string(" ")+NowDir.absoluteFilePath(text2).toStdString();
  int status=system (str.c_str());
  if (status==0)
  {
      cout << "您成功重命名了目录"<<NowDir.absoluteFilePath(text).toStdString()
           <<"为"<<NowDir.absoluteFilePath(text2).toStdString()<<endl;
  }
  else
  {
      cout << "重命名目录"<<NowDir.absoluteFilePath(text).toStdString()<<"失败！请检查是否在该目录下没有原目录或已有同名目录！"<<endl;
  }
  this->close();
}

void renameFile::renameButtonClick()
{
    QString text=renamelineEdit->text();
    QString text2=renamenewlineEdit->text();
    std::string str=std::string("mv ") + NowDir.absoluteFilePath(text).toStdString()
            +std::string(" ")+NowDir.absoluteFilePath(text2).toStdString();
    int status=system (str.c_str());
    if (status==0)
    {
        cout << "您成功重命名了文件"<<NowDir.absoluteFilePath(text).toStdString()
             <<"为"<<NowDir.absoluteFilePath(text2).toStdString()<<endl;
    }
    else
    {
        cout << "重命名文件"<<NowDir.absoluteFilePath(text).toStdString()<<"失败！请检查是否在该目录下没有原文件或已有同名文件！"<<endl;
    }
    this->close();
}

void renameFile::enablerenameButton(const QString &text)
{
  renameButton->setEnabled((!text.isEmpty()));
}

