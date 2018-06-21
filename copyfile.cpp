#include "copyfile.h"
#include "ui_copyfile.h"
#include <string>
#include <iostream>
using namespace std;

copyFile::copyFile(QDir NowDir,int i,QWidget *parent) :
    QWidget(parent)
{
  this->NowDir=NowDir;//为当前目录赋值
  if (i==0)
      copylabel=new QLabel(QString::fromLocal8Bit("输入目录名："));
  else
      copylabel=new QLabel(QString::fromLocal8Bit("输入文件名："));
  copylineEdit=new QLineEdit;
  copylabel->setBuddy(copylineEdit);
//输入和编辑栏
  copyButton=new QPushButton(QString::fromLocal8Bit("复制"));
  copyButton->setDefault(true);
  copyButton->setEnabled(false);

  closeButton=new QPushButton(QString::fromLocal8Bit("关闭"));
//新建和取消按钮
  connect(copylineEdit,SIGNAL(textChanged(const QString &)),
          this,SLOT(enablecopyButton(const QString &)));//判断复制按钮是否可用
  if (i==0)
      connect(copyButton,SIGNAL(clicked()),this,SLOT(copyButtonClicked()));//复制目录
  else
      connect(copyButton,SIGNAL(clicked()),this,SLOT(copyButtonClick()));//复制文件
  connect(closeButton,SIGNAL(clicked()),
          this,SLOT(close()));//点击关闭按钮结束

  QHBoxLayout *LeftLayout=new QHBoxLayout;
  LeftLayout->addWidget(copylabel);
  LeftLayout->addWidget(copylineEdit);
//输入编辑栏水平布局
  QVBoxLayout *rightLayout=new QVBoxLayout;
  rightLayout->addWidget(copyButton);
  rightLayout->addWidget(closeButton);
//加上按钮
  QHBoxLayout *mainLayout=new QHBoxLayout;
  mainLayout->addLayout(LeftLayout);
  mainLayout->addLayout(rightLayout);
//总布局
  setLayout(mainLayout);

  setWindowTitle(QString::fromLocal8Bit("复制"));
  setFixedHeight(sizeHint().height());
}

void copyFile::copyButtonClicked()
{
  QString text=copylineEdit->text();
  std::string str=std::string("cp -r ") + NowDir.absolutePath().toStdString()//cp -r 目录/文件 目录/文件.copy
          +std::string("/") + text.toStdString()
          +std::string(" ") + NowDir.absolutePath().toStdString()
          +std::string("/")+text.toStdString()+std::string(".copy");
  int status=system (str.c_str());
  if (status==0)
  {
      cout << "您复制了目录"<<NowDir.absoluteFilePath(text).toStdString()<<"为"<<NowDir.absoluteFilePath(text).toStdString()<<".copy"<<endl;
  }
  else
  {
      cout << "复制目录"<<NowDir.absoluteFilePath(text).toStdString()<<"失败！请检查在该目录下是否有已复制的目录！"<<endl;
  }
  this->close();
}

void copyFile::copyButtonClick()
{
    QString text=copylineEdit->text();
    std::string str=std::string("cp ") + NowDir.absolutePath().toStdString()//cp 目录/文件 目录/文件.copy
            +std::string("/") + text.toStdString()
            +std::string(" ") + NowDir.absolutePath().toStdString()
            +std::string("/")+text.toStdString()+std::string(".copy");
    int status=system (str.c_str());
    if (status==0)
    {
        cout << "您复制了文件"<<NowDir.absoluteFilePath(text).toStdString()<<"为"<<NowDir.absoluteFilePath(text).toStdString()<<".copy"<<endl;
    }
    else
    {
        cout << "复制文件"<<NowDir.absoluteFilePath(text).toStdString()<<"失败！请检查在该目录下是否有已复制的目录！"<<endl;
    }
    this->close();
}

void copyFile::enablecopyButton(const QString &text)
{
  copyButton->setEnabled((!text.isEmpty()));
}
