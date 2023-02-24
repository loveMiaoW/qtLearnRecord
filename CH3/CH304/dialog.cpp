#include "dialog.h"
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QFrame>
#include <QGridLayout>
#include <QPixmap>
#include <QHBoxLayout>
/*
    真正喜欢你的人,会督促你变的优秀,而不是蹉跎你的光阴
*/
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    init();
}

Dialog::~Dialog()
{

}

void Dialog::init()
{
    setWindowTitle(tr("userInfo"));
    setWindowIcon(QIcon("./yy.ico"));
    //left

    userNameLabel = new QLabel(tr("用户名: "));
    userNameLineEdit = new QLineEdit();

    nameLable = new QLabel(tr("姓名: "));
    nameLineEdit = new QLineEdit();

    sexLabel = new QLabel(tr("性别: "));
    sexComboBox = new QComboBox();
    sexComboBox->addItem(tr("男"));
    sexComboBox->addItem(tr("女"));

    departmentLabel = new QLabel(tr("部门: "));
    departmentTextEdit = new QTextEdit();

    ageLabel = new QLabel(tr("年龄: "));
    ageLineEdit = new QLineEdit();

    otherLabel = new QLabel(tr("备注: "));
    otherLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    leftLayout = new QGridLayout();

    leftLayout->addWidget(userNameLabel,0,0);
    leftLayout->addWidget(nameLineEdit,0,1);
    leftLayout->addWidget(nameLable,1,0);
    leftLayout->addWidget(nameLineEdit,1,1);
    leftLayout->addWidget(sexLabel,2,0);
    leftLayout->addWidget(sexComboBox,2,1);
    leftLayout->addWidget(departmentLabel,3,0);
    leftLayout->addWidget(departmentTextEdit,3,1);
    leftLayout->addWidget(ageLabel,4,0);
    leftLayout->addWidget(ageLineEdit,4,1);

    leftLayout->addWidget(otherLabel,5,0,1,2);
    leftLayout->setColumnStretch(0,1);
    leftLayout->setColumnStretch(1,3);

    //右侧
    headLabel = new QLabel(tr("头像"));
    headIconLabel = new QLabel();
    QPixmap icon("./src/yy.ico");
    headIconLabel->setPixmap(icon);
    headIconLabel->resize(icon.width(),icon.height());
    updateHeadIconbtn = new QPushButton(tr("更新"));

    //右上侧头像
    topRightLayout = new QHBoxLayout();
    topRightLayout->setSpacing(20);

    topRightLayout->addWidget(headLabel);
    topRightLayout->addWidget(headIconLabel);
    topRightLayout->addWidget(updateHeadIconbtn);
    //
    introductionLabel = new QLabel(tr("个人说明: "));
    introductionTextEdit = new QTextEdit();

    rightLayout = new QVBoxLayout();
    rightLayout->setMargin(10);
    rightLayout->addLayout(topRightLayout);
    rightLayout->addWidget(introductionLabel);
    rightLayout->addWidget(introductionTextEdit);

    //底部
    okBtn = new QPushButton(tr("确定"));
    calcelBtn = new QPushButton(tr("取消"));
    buttomLayout = new QHBoxLayout();
    buttomLayout->addStretch();
    buttomLayout->addWidget(okBtn);
    buttomLayout->addWidget(calcelBtn);

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(leftLayout,0,0);
    mainLayout->addLayout(rightLayout,0,1);
    mainLayout->addLayout(buttomLayout,1,0,1,2);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

}
