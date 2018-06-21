#ifndef OPENFILE_H
#define OPENFILE_H

#include <QWidget>
#include <QtGui>


class openFile : public QWidget
{
    Q_OBJECT

public:
    static QDir getDir();
    openFile(QDir NowDir, int i,QWidget *parent = 0);


private slots:
    void openButtonClicked();//打开目录操作
    void openButtonClick();//打开文件操作
    void enableopenButton(const QString &text);//打开按钮是否可用（有输入时可用）

private:
    QLabel *openlabel;//输入xx名
    QLineEdit *openlineEdit;//编辑栏
    QPushButton *openButton;//新建按钮
    QPushButton *closeButton;//取消按钮
    static QDir NowDir;//当前目录
    QLabel *choicelabel;
    QRadioButton *geditbutton;//打开方式1
    QRadioButton *vimbutton;//打开方式2
    //文本
    QRadioButton *eogbutton;//打开方式3
    QRadioButton *displaybutton;//打开方式4
    //图像
    QRadioButton *mplayerbutton;//打开方式5
    QRadioButton *qmmpbutton;//打开方式6
    //音频
    QRadioButton *smplayerbutton;//打开方式7
    QRadioButton *totembutton;//打开方式8
    //视频
};
#endif
