#include "deletefile.h"
#include "ui_deletefile.h"
#include <string>
#include <iostream>
using namespace std;

deleteFile::deleteFile(QDir NowDir,int i,QWidget *parent) :
    QWidget(parent)
{
  this->NowDir=NowDir;//为当前目录赋值
  if (i==0)
      deletelabel=new QLabel(QString::fromLocal8Bit("输入目录名："));
  else
      deletelabel=new QLabel(QString::fromLocal8Bit("输入文件名："));
  deletelineEdit=new QLineEdit;
  deletelabel->setBuddy(deletelineEdit);
//输入和编辑栏
  deleteButton=new QPushButton(QString::fromLocal8Bit("删除"));
  deleteButton->setDefault(true);
  deleteButton->setEnabled(false);

  closeButton=new QPushButton(QString::fromLocal8Bit("关闭"));
//新建和取消按钮
  connect(deletelineEdit,SIGNAL(textChanged(const QString &)),
          this,SLOT(enabledeleteButton(const QString &)));//判断删除按钮是否可用
  if (i==0)
      connect(deleteButton,SIGNAL(clicked()),this,SLOT(deleteButtonClicked()));//删除目录
  else
      connect(deleteButton,SIGNAL(clicked()),this,SLOT(deleteButtonClick()));//删除文件
  connect(closeButton,SIGNAL(clicked()),
          this,SLOT(close()));//点击关闭按钮结束

  QHBoxLayout *LeftLayout=new QHBoxLayout;
  LeftLayout->addWidget(deletelabel);
  LeftLayout->addWidget(deletelineEdit);
//输入编辑栏水平布局
  QVBoxLayout *rightLayout=new QVBoxLayout;
  rightLayout->addWidget(deleteButton);
  rightLayout->addWidget(closeButton);
//加上按钮
  QHBoxLayout *mainLayout=new QHBoxLayout;
  mainLayout->addLayout(LeftLayout);
  mainLayout->addLayout(rightLayout);
//总布局
  setLayout(mainLayout);

  setWindowTitle(QString::fromLocal8Bit("删除"));
  setFixedHeight(sizeHint().height());
}

void deleteFile::deleteButtonClicked()
{
  QString text=deletelineEdit->text();
  std::string str=std::string("mv ") + NowDir.absoluteFilePath(text).toStdString()
          +std::string(" ~/.local/share/Trash/files");
  int status=system (str.c_str());
  if (status==0)
  {
      cout << "您成功删除了目录"<<NowDir.absoluteFilePath(text).toStdString()<<endl;
  }
  else
  {
      cout << "删除目录"<<NowDir.absoluteFilePath(text).toStdString()<<"失败！请检查是否在该目录下没有目标目录！"<<endl;
  }
  this->close();
}

void deleteFile::deleteButtonClick()
{
    QString text=deletelineEdit->text();
    std::string str=std::string("mv ") + NowDir.absoluteFilePath(text).toStdString()
            +std::string(" ~/.local/share/Trash/files");
    int status=system (str.c_str());
    if (status==0)
    {
        cout << "您成功删除了文件"<<NowDir.absoluteFilePath(text).toStdString()<<endl;
    }
    else
    {
        cout << "删除文件"<<NowDir.absoluteFilePath(text).toStdString()<<"失败！请检查是否在该目录下没有目标文件！"<<endl;
    }
    this->close();
}

void deleteFile::enabledeleteButton(const QString &text)
{
  deleteButton->setEnabled((!text.isEmpty()));
}
