#include <QCoreApplication>
#include <QDebug>
#include <QString>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QList只读迭代器
    QList<int> list;
//    list << 1 << 2 << 3 << 4 << 5;
//    QListIterator<int> i(list);
//    for(;i.hasNext();)
//    {
//        qDebug() << i.next();
//    }
//    QMutableListIterator<int> i(list);
//    for(int j = 0;j < 10;j++)
//    {
//        i.insert(j);
//    }
//    for(i.toFront();i.hasNext();)
//    {
//        qDebug() << i.next();
//    }
//    qDebug() <<" "<<endl;
//    for(i.toBack();i.hasPrevious();)
//    {
//        qDebug() << i.previous();
//    }
    for(int i = 0;i < 10;i++)
    {
        list.insert(list.end(),i);
    }
    for(QList<int>::iterator i = list.begin();i != list.end();++i)
    {
        qDebug() << (*i);
    }
    for(QList<int>::const_iterator j = list.begin();j != list.end();++j)
    {
        qDebug() << (*j);
    }
    return a.exec();
}
