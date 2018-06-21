#ifndef COPYFILE_H
#define COPYFILE_H

#include <QWidget>
#include <QtGui>


class copyFile : public QWidget
{
    Q_OBJECT

public:
    copyFile(QDir NowDir, int i,QWidget *parent = 0);


private slots:
    void copyButtonClicked();//复制目录操作
    void copyButtonClick();//复制文件操作
    void enablecopyButton(const QString &text);//复制按钮是否可用（有输入时可用）

private:
    QLabel *copylabel;//输入目录名
    QLineEdit *copylineEdit;//编辑栏
    QPushButton *copyButton;//复制按钮
    QPushButton *closeButton;//取消按钮
    QDir NowDir;//当前目录
};
#endif
