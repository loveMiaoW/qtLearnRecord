#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
    void init();
private:
    //left
    QLabel *userNameLabel;
    QLabel *nameLable;
    QLabel *sexLabel;
    QLabel *departmentLabel;
    QLabel *ageLabel;
    QLabel *otherLabel;
    QLineEdit *userNameLineEdit;
    QLineEdit *nameLineEdit;
    QComboBox *sexComboBox;
    QTextEdit *departmentTextEdit;
    QLineEdit *ageLineEdit;
    QGridLayout *leftLayout;
    //rigth
    QLabel *headLabel;
    QLabel *headIconLabel;
    QPushButton *updateHeadIconbtn;
    QHBoxLayout *topRightLayout;
    QLabel *introductionLabel;
    QTextEdit *introductionTextEdit;
    QVBoxLayout *rightLayout;

    //底部
    QPushButton *okBtn;
    QPushButton *calcelBtn;
    QHBoxLayout *buttomLayout;
};

#endif // DIALOG_H
