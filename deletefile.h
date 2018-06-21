#ifndef DELETDFILE_H
#define DELETDFILE_H

#include <QWidget>
#include <QtGui>


class deleteFile : public QWidget
{
    Q_OBJECT

public:
    deleteFile(QDir NowDir, int i,QWidget *parent = 0);


private slots:
    void deleteButtonClicked();//删除目录操作
    void deleteButtonClick();//删除文件操作
    void enabledeleteButton(const QString &text);//删除按钮是否可用（有输入时可用）

private:
    QLabel *deletelabel;//输入目录名
    QLineEdit *deletelineEdit;//编辑栏
    QPushButton *deleteButton;//删除按钮
    QPushButton *closeButton;//取消按钮
    QDir NowDir;//当前目录
};
#endif
