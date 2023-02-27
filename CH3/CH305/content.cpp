#include "content.h"
#include "contact.h"
#include "detail.h"
#include "baseinfo.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
Content::Content(QWidget *parent)
    : QFrame(parent)
{
    stack = new QStackedWidget(this);
    stack->setFrameStyle(QFrame::Panel|QFrame::Raised);//查文档
    baseInfo = new BaseInfo();
    contact = new Contact();
    detail = new Detail();

    stack->addWidget(baseInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);

    amendBtn = new QPushButton(tr("修改"));
    closeBtn = new QPushButton(tr("关闭"));
    QHBoxLayout *layoutBtn= new QHBoxLayout();
    layoutBtn->addStretch(1);
    layoutBtn->addWidget(amendBtn);
    layoutBtn->addWidget(closeBtn);

    QVBoxLayout *rightLayout = new QVBoxLayout();
    rightLayout->setMargin(10);
    rightLayout->setSpacing(5);
    rightLayout->addWidget(stack);
    rightLayout->addLayout(layoutBtn);
}

Content::~Content()
{

}
