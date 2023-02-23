#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void treeItemChanged(QTreeWidgetItem* item,int column);//信号参数某一个QTreeWidget对象和第几行
public:
    void init();    //初始化
    void upDateParentItem(QTreeWidgetItem* item);       //更新选中状态
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
