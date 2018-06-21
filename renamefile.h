#ifndef RENAMEFILE_H
#define RENAMEFILE_H

#include <QWidget>
#include <QtGui>


class renameFile : public QWidget
{
    Q_OBJECT

public:
    renameFile(QDir NowDir, int i,QWidget *parent = 0);


private slots:
    void renameButtonClicked();//重命名目录操作
    void renameButtonClick();//重命名文件操作
    void enablerenameButton(const QString &text);//重命名按钮是否可用（有输入时可用）

private:
    QLabel *renamelabel;//输入目录名
    QLineEdit *renamelineEdit;//编辑栏1
    QLabel *renamenewlabel;//输入新目录名
    QLineEdit *renamenewlineEdit;//编辑栏2
    QPushButton *renameButton;//重命名按钮
    QPushButton *closeButton;//取消按钮
    QDir NowDir;//当前目录
};
#endif
