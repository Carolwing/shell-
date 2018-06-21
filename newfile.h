#ifndef NEWFILE_H
#define NEWFILE_H

#include <QWidget>
#include <QtGui>


class newFile : public QWidget
{
    Q_OBJECT

public:
    newFile(QDir NowDir, int i,QWidget *parent = 0);


private slots:
    void newButtonClicked();//新建目录操作
    void newButtonClick();//新建文件操作
    void enablenewButton(const QString &text);//新建按钮是否可用（有输入时可用）

private:
    QLabel *newlabel;//输入目录名
    QLineEdit *newlineEdit;//编辑栏
    QPushButton *newButton;//新建按钮
    QPushButton *closeButton;//取消按钮
    QDir NowDir;//当前目录
};
#endif
