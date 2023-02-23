#include "dialog.h"
#include "ui_dialog.h"
#include <QRegExp>
#include <QRegExpValidator>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init()
{
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->inputLine->setValidator(new QRegExpValidator(regExp,this));
    connect(ui->btnOk,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->btnCan,SIGNAL(clicked()),this,SLOT(reject()));
}

void Dialog::on_inputLine_textChanged(const QString &arg1)
{
    ui->btnOk->setEnabled(ui->inputLine->hasAcceptableInput());
}
