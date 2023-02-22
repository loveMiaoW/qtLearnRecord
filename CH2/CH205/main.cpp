#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMap<QString,QString> map;
    map.insert("beijing","111");
    map.insert("shanghai","222");
    map.insert("nanjing","333");
    for(QMap<QString,QString>::iterator i = map.begin();i != map.end();++i)
    {
        qDebug() <<i.key() <<" "<<i.value();
    }

    QMap<QString,QString>::iterator ptr = map.find("beijing");
    if(ptr != map.end())
    {
        ptr.value() = "0000";
    }
    for(QMap<QString,QString>::const_iterator i = map.constBegin();i != map.constEnd();++i)
    {
        qDebug() << i.key() << " " <<i.value();
    }
    return a.exec();
}
