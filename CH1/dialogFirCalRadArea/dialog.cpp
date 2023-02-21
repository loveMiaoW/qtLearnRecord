#include "dialog.h"
#include "ui_dialog.h"
const double PI = 3.1415926;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}
//析构函数
Dialog::~Dialog()
{
    delete ui;
}
//实现计算面积函数
void Dialog::calRadiusArea()
{
    bool ok;
    QString tmpStr;
    QString valueStr = ui->inputRadiusLineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt * valueInt * PI;
    ui->areaLabel->setText(tmpStr.setNum(area));
}
//通过QPushButton点击调用面积计算函数
void Dialog::on_countBtn_clicked()
{
    calRadiusArea();
}
//槽函数 QLineEdit 文本改变 调用执行计算面积函数
void Dialog::on_inputRadiusLineEdit_textChanged(const QString &arg1)
{
    calRadiusArea();
}
