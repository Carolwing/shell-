#include "openfile.h"
#include "ui_openfile.h"
#include <string>
#include <iostream>
using namespace  std;

openFile::openFile(QDir NowDir,int i,QWidget *parent) :
    QWidget(parent)
{
  this->NowDir=NowDir;//为当前目录赋值
  if (i==0)
      openlabel=new QLabel(QString::fromLocal8Bit("输入目录名："));
  else
      openlabel=new QLabel(QString::fromLocal8Bit("输入文件名："));
  openlineEdit=new QLineEdit;
  openlabel->setBuddy(openlineEdit);
//输入和编辑栏
  openButton=new QPushButton(QString::fromLocal8Bit("打开"));
  openButton->setDefault(true);
  openButton->setEnabled(false);

  closeButton=new QPushButton(QString::fromLocal8Bit("关闭"));
//打开和取消按钮
  if (i==1)
  {
      choicelabel=new QLabel(QString::fromLocal8Bit("打开方式:"));
      geditbutton=new QRadioButton(QString::fromLocal8Bit("Gedit编辑器"));
      vimbutton=new QRadioButton(QString::fromLocal8Bit("Vim编辑器   "));
      eogbutton=new QRadioButton(QString::fromLocal8Bit("eog图像查看器                  "));
      displaybutton=new QRadioButton(QString::fromLocal8Bit("imagemagick图像查看器"));
      mplayerbutton=new QRadioButton(QString::fromLocal8Bit("MPlayer播放器 "));
      qmmpbutton=new QRadioButton(QString::fromLocal8Bit("qmmp播放器   "));
      smplayerbutton=new QRadioButton(QString::fromLocal8Bit("SMplayer播放器"));
      totembutton=new QRadioButton(QString::fromLocal8Bit("totem播放器"));

  }

  connect(openlineEdit,SIGNAL(textChanged(const QString &)),
          this,SLOT(enableopenButton(const QString &)));//判断打开按钮是否可用

  if (i==0)
      connect(openButton,SIGNAL(clicked()),this,SLOT(openButtonClicked()));//打开目录
  else
      connect(openButton,SIGNAL(clicked()),this,SLOT(openButtonClick()));//打开文件

  connect(closeButton,SIGNAL(clicked()),
          this,SLOT(close()));//点击关闭按钮结束

  QHBoxLayout *LeftLayout=new QHBoxLayout;
  LeftLayout->addWidget(openlabel);
  LeftLayout->addWidget(openlineEdit);
//输入编辑栏水平布局
  QVBoxLayout *rightLayout=new QVBoxLayout;
  rightLayout->addWidget(openButton);
  rightLayout->addWidget(closeButton);
//加上按钮
  if (i==1)
  {
      QHBoxLayout *choicelayout=new QHBoxLayout;
      choicelayout->addWidget(geditbutton);
      choicelayout->addWidget(vimbutton);

      QHBoxLayout *choicepiclayout=new QHBoxLayout;
      choicepiclayout->addWidget(eogbutton);
      choicepiclayout->addWidget(displaybutton);

      QHBoxLayout *choicemuslayout=new QHBoxLayout;
      choicemuslayout->addWidget(mplayerbutton);
      choicemuslayout->addWidget(qmmpbutton);

      QHBoxLayout *choicemovlayout=new QHBoxLayout;
      choicemovlayout->addWidget(smplayerbutton);
      choicemovlayout->addWidget(totembutton);

      QVBoxLayout *openfilelayout=new QVBoxLayout;
      openfilelayout->addLayout(LeftLayout);
      openfilelayout->addWidget(choicelabel);
      openfilelayout->addLayout(choicelayout);
      openfilelayout->addLayout(choicepiclayout);
      openfilelayout->addLayout(choicemuslayout);
      openfilelayout->addLayout(choicemovlayout);

      QHBoxLayout *mainLayout=new QHBoxLayout;
      mainLayout->addLayout(openfilelayout);
      mainLayout->addLayout(rightLayout);

      setLayout(mainLayout);
  }
  else
  {
      QHBoxLayout *mainLayout=new QHBoxLayout;
      mainLayout->addLayout(LeftLayout);
      mainLayout->addLayout(rightLayout);

      setLayout(mainLayout);
  }
  setWindowTitle(QString::fromLocal8Bit("打开"));
  setFixedHeight(sizeHint().height());
}

void openFile::openButtonClicked()
{
  QString text=openlineEdit->text();//获取当前打开文件
  std::string str=std::string("cd ")+NowDir.absolutePath().toStdString()
          +std::string("/")+text.toStdString();
  int status=system (str.c_str());//改变目录
  if (status==0)//如果成功改变
  {
    cout << "您成功打开了目录"<< (NowDir.absoluteFilePath(text)).toStdString()<<endl;
    std::string stringnow=NowDir.absolutePath().toStdString()
          +std::string("/")+text.toStdString();
    QString now=QString(QString::fromLocal8Bit(stringnow.c_str()));
    NowDir.setPath(now);//则成功改变类下的当前目录
  }
  else
  {
      cout << "打开目录"<< NowDir.absoluteFilePath(text).toStdString()<<"失败！请检查是否在该目录下没有目标目录！"<<endl;
  }
  this->close();
}

void openFile::openButtonClick()
{
    QString text=openlineEdit->text();
    QString way;
    if (geditbutton->isChecked())
        way=QString::fromLocal8Bit("gedit ");
    else if (vimbutton->isChecked())
        way=QString::fromLocal8Bit("vim ");
    else if (eogbutton->isChecked())
        way=QString::fromLocal8Bit("eog ");
    else if (displaybutton->isChecked())
        way=QString::fromLocal8Bit("display ");
    else if (mplayerbutton->isChecked())
        way=QString::fromLocal8Bit("mplayer ");
    else if (qmmpbutton->isChecked())
        way=QString::fromLocal8Bit("qmmp ");
    else if (smplayerbutton->isChecked())
        way=QString::fromLocal8Bit("smplayer ");
    else if (totembutton->isChecked())
        way=QString::fromLocal8Bit("totem ");
    else
    {
        cout<<"请选择打开方式"<<endl;
        this->close();
    }
    std::string str=way.toStdString()+NowDir.absoluteFilePath(text).toStdString();
    int status=system (str.c_str());
    if (status==0)
    {
        cout<<"您成功打开了文件"<< NowDir.absoluteFilePath(text).toStdString()<<endl;
    }
    else
    {
        cout << "打开文件"<<NowDir.absoluteFilePath(text).toStdString()<<"失败！请检查是否在该目录下没有目标文件！"<<endl;
    }
    this->close();
}

void openFile::enableopenButton(const QString &text)
{
  openButton->setEnabled((!text.isEmpty()));
}

QDir openFile::getDir()
{
    return NowDir;
}

QDir openFile::NowDir=QDir(QString::fromLocal8Bit("/home/carolwing/FileOperatorTest"));
