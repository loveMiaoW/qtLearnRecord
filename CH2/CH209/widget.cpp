#include "widget.h"
#include "ui_widget.h"
#include <QWidgetItem>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
    connect(ui->treeWidget,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this,SLOT(treeItemChanged(QTreeWidgetItem*,int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    ui->treeWidget->clear();
    //两个分组
    QTreeWidgetItem* group1 = new QTreeWidgetItem(ui->treeWidget);
    QTreeWidgetItem* group2 = new QTreeWidgetItem(ui->treeWidget);
    //分组标题
    group1->setText(0,"group1");
    group2->setText(0,"group2");
    //可选框状态
    group1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group2->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    //未选中
    group1->setCheckState(0,Qt::Unchecked);
    group2->setCheckState(0,Qt::Unchecked);
    //自项目
    QTreeWidgetItem *subItem11 = new QTreeWidgetItem(group1);
    QTreeWidgetItem *subItem12 = new QTreeWidgetItem(group1);
    QTreeWidgetItem *subItem13 = new QTreeWidgetItem(group1);
    QTreeWidgetItem *subItem14 = new QTreeWidgetItem(group1);
    QTreeWidgetItem *subItem21 = new QTreeWidgetItem(group2);
    QTreeWidgetItem *subItem22 = new QTreeWidgetItem(group2);
    QTreeWidgetItem *subItem23 = new QTreeWidgetItem(group2);
    QTreeWidgetItem *subItem24 = new QTreeWidgetItem(group2);
    //子条目的可选状态
    subItem11->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem12->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem13->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem14->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem21->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem22->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem23->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem24->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    //子条目标题
    subItem11->setText(0,"subItem11");
    subItem12->setText(0,"subItem12");
    subItem13->setText(0,"subItem13");
    subItem14->setText(0,"subItem14");
    subItem21->setText(0,"subItem21");
    subItem22->setText(0,"subItem22");
    subItem23->setText(0,"subItem23");
    subItem24->setText(0,"subItem24");
    //初始化子条目为未选择
    subItem11->setCheckState(0,Qt::Unchecked);
    subItem12->setCheckState(0,Qt::Unchecked);
    subItem13->setCheckState(0,Qt::Unchecked);
    subItem14->setCheckState(0,Qt::Unchecked);
    subItem21->setCheckState(0,Qt::Unchecked);
    subItem22->setCheckState(0,Qt::Unchecked);
    subItem23->setCheckState(0,Qt::Unchecked);
    subItem24->setCheckState(0,Qt::Unchecked);
}

void Widget::treeItemChanged(QTreeWidgetItem *item, int column)
{
    QString itemTest = item->text(0);
    //qDebug() << itemTest;
    //选中
    if(Qt::Checked == item->checkState(0))
    {
        QTreeWidgetItem *parent = item->parent();
        int count = item->childCount();
        if(count > 0)
        {
            for(int i = 0;i < count;++i)
            {
                item->child(i)->setCheckState(0,Qt::Checked);
            }
        }
        else
        {
            upDateParentItem(item);
        }
    }
    //未选中
    else if(Qt::Unchecked == item->checkState(0))
    {
        int count = item->childCount();
        if(count > 0)
        {
            for(int i = 0;i < count;++i)
            {
                item->child(i)->setCheckState(0,Qt::Unchecked);
            }
        }
        else {
            upDateParentItem(item);
        }
    }
}

void Widget::upDateParentItem(QTreeWidgetItem *item)
{
    QTreeWidgetItem *parten = item->parent();
    if(parten == NULL)
    {
        return;
    }
    int selectItemNum = 0;
    int childCount = parten->childCount();
    //qDebug() << childCount;
    for(int i = 0;i < childCount;++i)
    {
        QTreeWidgetItem *childItem = parten->child(i);
        if(childItem->checkState(0) == Qt::Checked)
        {
            selectItemNum++;
        }
    }
    if(selectItemNum <= 0)
    {
        parten->setCheckState(0,Qt::Unchecked);
    }
    else if(selectItemNum > 0 && selectItemNum < childCount)
    {
        parten->setCheckState(0,Qt::PartiallyChecked);
    }
    else if(selectItemNum == childCount)
    {
        parten->setCheckState(0,Qt::Checked);
    }
}
