#include "widget.h"
#include<QLabel>
#include <QPushButton>
#include <qDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
   QWidget *win = new QWidget(this);
   win->resize(320,240);
   win->show();
   QPushButton *button = new QPushButton(tr("press me"),win);
   button->move(100,100);
   button->show();
   //connect(button,SIGNAL(clicked()),this,SLOT(quit()));
}

Widget::~Widget()
{

}

void Widget::pressClose()
{
   close();
}
