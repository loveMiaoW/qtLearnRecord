#include "mainwindow.h"
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init();
}

MainWindow::~MainWindow()
{

}

void MainWindow::init()
{
    setWindowTitle(tr("DockWindow"));
    QTextEdit *te = new QTextEdit(this);
    te->setText(tr("MainWindow"));
    te->setAlignment(Qt::AlignCenter);
    setCentralWidget(te);
    QDockWidget *dock = new QDockWidget(tr("DockWidget1"),this);
    //DockWidget1可移动
    dock->setFeatures(QDockWidget::DockWidgetMovable);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    QTextEdit *tel = new QTextEdit();
    tel->setText(tr("loveMiaoW"));
    dock->setWidget(tel);
    addDockWidget(Qt::RightDockWidgetArea,dock);


    dock = new QDockWidget(tr("DockWindow2"),this);
    dock->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable);
    QTextEdit *tel2 = new QTextEdit();
    tel2->setText(tr("loveLoveLoveLove"));
    dock->setWidget(tel2);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    dock = new QDockWidget(tr("DockWindow3"),this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    QTextEdit *tel3 = new QTextEdit();
    tel3->setText(tr("llllllllllllllllllllllllllllllllllllllllllllllllllll"));
    dock->setWidget(tel3);

    addDockWidget(Qt::RightDockWidgetArea,dock);
}
