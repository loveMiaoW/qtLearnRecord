#include "mainwindow.h"
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    QFont font("ZYSong18030",12);
    a.setFont(font);
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal,0);
    QTextEdit *textEdit = new QTextEdit(QObject::tr("Left Widget"),splitterMain);
    textEdit->setAlignment(Qt::AlignCenter);

    QSplitter *splitterRight = new QSplitter(Qt::Vertical,splitterMain);
    splitterRight->setOpaqueResize(false);
    QTextEdit *textUp = new QTextEdit(QObject::tr("Top Widget"),splitterRight);
    textUp->setAlignment(Qt::AlignCenter);

    QTextEdit *textBottom = new QTextEdit(QObject::tr("bottom text"),splitterRight);
    textBottom->setAlignment(Qt::AlignCenter);
    splitterMain->setStretchFactor(0,0);            //设置空间伸缩性
    splitterMain->setStretchFactor(1,0);            //参数一控件编号 参数二 是否可伸缩
    splitterMain->setWindowTitle(QObject::tr("splitter"));
    splitterMain->show();
    return a.exec();
}
