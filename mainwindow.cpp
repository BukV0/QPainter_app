#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include <QContextMenuEvent>
#include <QMessageBox>
#include <QDialog>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actionFigure1 = new QAction(tr("&Act"), this);
    connect(actionFigure1,SIGNAL(triggered()),
            QApplication::instance(),SLOT(quit()));

    menuFigure = menuBar()->addMenu(tr("&Figure"));
    menuFigure->addAction(actionFigure1);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
  //menuFigure->exec(event->globalPos());
    QDialog *qd = new QDialog(this);
    qd->setModal(true);
    qd->resize(200,200);
    QLabel *l = new QLabel("Helloooo...",qd);
    l->show();
    qd->exec();
    delete qd;
}


void MainWindow::on_actionfigure1_toggled(bool arg1)
{
    figure_1 = arg1;
}

void MainWindow::on_actionfigure2_toggled(bool arg1)
{
    figure_2 = arg1;
}

void MainWindow::on_actionadd_triggered()
{
   if(figure_1 == true && figure_2 == true){
       Figure *f = new Figure(this);
       Figure *f2 = new Figure(this,2);
       figures.push_back(f);
       figures.push_back(f2);
       f2->move(150,150);
       f->move(100,100);
       f->show();
       f2->show();
   }
   else{
       if(figure_1 == true){
           Figure *f = new Figure(this);
           figures.push_back(f);
           f->move(100,100);
           f->show();
       }
       else{
           if(figure_2){
               Figure *f = new Figure(this,2);
               figures.push_back(f);
               f->move(100,100);
               f->show();
           }
       }
   }
}

void MainWindow::on_actiondelete_triggered()
{
    for(uint i = 0; i < figures.size();i++){
        if(figures[i]->isselect() == true){
            figures[i]->close();
            figures.erase(figures.begin()+i);
            i--;
        }
    }
}
