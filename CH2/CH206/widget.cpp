#include "widget.h"
#include <QDebug>
#include <QVariant>
#include <QColor>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVariant v(709);
    qDebug() << v.toInt();
    QVariant w("How are you?");
    qDebug() << w.toString();

    QMap<QString,QVariant> map;
    map["int"] = 999;
    map["double"] = 999.999;
    map["string"] = "loveMiaoW";
    map["color"] = QColor(255,0,0);
    QStringList s1;
    s1 << "A" <<"B"<<"C";


    QVariant slv(s1);
    if(slv.type() == QVariant::StringList)
    {
        QStringList list = slv.toStringList();
        for(int i = 0;i < list.size();++i)
        {
            qDebug() << list[i];
        }
    }

}

Widget::~Widget()
{

}
