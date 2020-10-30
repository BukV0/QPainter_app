#include "figure.h"

#include <QPainter>
#include <QMessageBox>
#include <QMouseEvent>
#include <QLabel>
#include <QDebug>
#include <QAction>
#include <QDialog>
#include <QMenu>
#include <QPushButton>
#include <QLineEdit>
#include<QInputDialog>
#include "figuredialog.h"
#include<string>
#include<cmath>
Figure::Figure(QWidget *parent, int _type) :
    QWidget(parent),
    flag_paint(false), flag_resize(false)
{
    type = _type;
    pen.setColor(Qt::black);
    select = false;
    rotate1 = 0;
    rotate2 = 0;
    dir = 1;
    figure_size = 3;
    rd2 = (height()-1)*4/5;
    rf2 = (height()-1)*4/3;
    p2 = (width()-1)*4/12;
    ax2 = (height()-1)*4/3;
    bx2 = (height()-1)*4/3;
    cx2 = (height()-1)*4/3;

    p1 = (width()-1)*4/12;
    x1 = (height()-1)*4/3;
    re1 = (height()-1)*4/3;
    ra1 = (height()-1)*4/3;
    rb1 = (height()-1)*4/5;
    wper = width()-1;
    hper = height()-1;
}


void Figure::paintEvent(QPaintEvent *event)
{
   const int mult = 4;

   auto w = width()  -1;
   auto h = height() -1;
   wper = w;
   hper = h;

   if( !flag_paint ) flag_paint = true;
   if( flag_paint && !flag_resize ) this->resize(mult*w+mult,mult*h+mult);
//   if( flag_paint && !flag_resize ) this->resize(600,400);
//   qDebug() << "paint2: " << height();


   QPainter painter(this);
//   painter.translate(250,100);
   painter.setPen(pen);
 painter.translate(w/2,h/2-12);
//   painter.translate(start_p+0+w/2,start_p+0+h/2)
//   painter.translate(start_p+0,start_p+0);
//   qDebug() << rotate;
//   qDebug() << this->size();

   if(type == 1){
       painter.rotate(rotate1);
       if(figure_size < 3) figure_size = 3;
       painter.scale(1.0/figure_size,1.0/figure_size);
       uint64_t xs = 0;
       uint64_t ys = 0;
       if(p1 <= 0 || p1 > w/4) {p1 = w/4;}
       if(x1 <= 0 || x1 >h/3 ) x1 = h/3;
       if(re1 <= 0 || re1 > w/8) re1 = w/8;
       if(ra1 <= 0 || ra1 > h/3) ra1 = h/3;
       if(rb1 <= 0 || rb1 > h/3) rb1 = h/3;
//    qDebug() << "paint: " << ra1;
   //top
   painter.drawLine(xs,ys,xs+w/2-re1,ys);
    painter.drawArc(xs+w/2-re1,ys-re1,re1*2,re1*2,0*16,180*16);
    painter.drawLine(xs+w/2+re1,ys,xs+w-ra1,ys);
    painter.drawArc(xs+w-ra1,ys-ra1,ra1*2,ra1*2,180*16,90*16);
    //right
    painter.drawLine(xs+w,ys+ra1,xs+w,ys+h-rb1);
    painter.drawArc(xs+w-rb1,ys+h-rb1,rb1*2,rb1*2,90*16,90*16);
   //botton
    painter.drawLine(xs+w-rb1,ys+h,xs+w/2+p1/2,ys+h);
    painter.drawLine(xs+w/2+p1/2,ys+h,xs+w/2+p1/2,ys+h+p1/2);
    painter.drawLine(xs+w/2+p1/2,ys+h+p1/2,xs+w/2-p1/2,ys+h+p1/2);
    painter.drawLine(xs+w/2-p1/2,ys+h+p1/2,xs+w/2-p1/2,ys+h);
    painter.drawLine(xs+w/2-p1/2,ys+h,xs+x1,ys+h);
    painter.drawLine(xs+x1,ys+h,xs+x1,ys+h-x1);
    //right
    painter.drawLine(xs+x1,ys+h-x1,xs,ys+h-x1);
    painter.drawLine(xs,ys+h-x1,xs,ys);
   }
   if(type == 2){
       painter.rotate(rotate2);
       if(figure_size < 3) figure_size = 3;
       painter.scale(1.0/figure_size,1.0/figure_size);
       uint64_t xs = 0;
       uint64_t ys = 0;
       if(rd2 <= 0 || rd2 > h/3) rd2 = h/3;
       if(rf2 <= 0 || rf2 > w/8) rf2 = w/8;
       if(p2 <= 0 || p2 > w/4) p2 = w/4;
       if(ax2 <= 0 || ax2 > h/3) ax2 = h/3;
       if(bx2 <= 0 || bx2 > h/3) bx2 = h/3;
       if(cx2 <= 0 || cx2 > h/3) cx2 = h/3;
       //top
       painter.drawLine(xs+rd2,ys,xs+w/2-p2/2,ys);
       painter.drawArc(xs-rd2,ys-rd2,rd2*2,rd2*2,270*16,90*16);
       painter.drawLine(xs+w/2-p2/2,ys,xs+w/2-p2/2,ys-p2/2);
       painter.drawLine(xs+w/2-p2/2,ys-p2/2,xs+w/2+p2/2,ys-p2/2);
       painter.drawLine(xs+w/2+p2/2,ys-p2/2,xs+w/2+p2/2,ys);
       painter.drawLine(xs+w/2+p2/2,ys,xs+w-ax2,ys);
       //right
       painter.drawLine(xs+w-ax2,ys,xs+w,ys+ax2);
       painter.drawLine(xs+w,ys+ax2,xs+w,ys+h-bx2);
       //botton
       painter.drawLine(xs+w,ys+h-bx2,xs+w-bx2,ys+h);
       painter.drawLine(xs+w-bx2,ys+h,xs+w/2+rf2,ys+h);
       painter.drawArc(xs+w/2-rf2,ys+h-rf2,rf2*2,rf2*2,180*16,180*16);
       painter.drawLine(xs+w/2-rf2,ys+h,xs+cx2,ys+h);
       //right
       painter.drawLine(xs+cx2,ys+h,xs,ys+h-cx2);
       painter.drawLine(xs,ys+h-cx2,xs,ys+rd2);
   }





//   painter.drawLine(start_p+w,start_p+0,start_p+w,start_p+h);	// rigth
//   painter.drawLine(start_p+w,start_p+h,start_p+0,start_p+h); 	// botton
//   painter.drawLine(start_p+0,start_p+h,start_p+0,start_p+0+mult*15);	// left
//   painter.drawLine(start_p+0,start_p+0+mult*15,start_p+0+mult*15,start_p+0);	// diag

}

void Figure::resizeEvent(QResizeEvent *event)
{
   if( flag_paint && !flag_resize ) flag_resize = true;
}

void Figure::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        point = event->pos();
        if(pen.color() == Qt::blue) pen.setColor(Qt::black);
        else
        {
            pen.setColor(Qt::blue);
            select = true;
        }
        this->repaint();

    }

}
void Figure::mouseMoveEvent(QMouseEvent *event){
    if((event->buttons() & Qt::LeftButton)){
        auto new_point = mapToParent(event->pos() - point);
        figure_size = 4;
        if(type == 1) rotate1 = 0;
        else rotate2 = 0;
//        QRect r = geometry();
//        qDebug() << this->size() << ' ' << frameSize();
//        qDebug() << "new_rx : " << new_point.x() << "new_ry" << new_point.y();
        if(new_point.x() > -197 && new_point.y() > 10 && new_point.x() < 300 && new_point.y() < 320) this->move(new_point);




    }
}
void Figure::contextMenuEvent(QContextMenuEvent *event){
    QDialog *qd = new QDialog(this);
    qd->setModal(true);
    qd->resize(200,200);
    this->calculatePlosAndPer();
    std::string perim_str = "perimeter: ";
    perim_str+=std::to_string(perimeter);
    std::string plos_str = "ploshad: ";
    plos_str +=std::to_string(ploshad);
   QLabel *l = new QLabel(QString::fromStdString(perim_str),qd);
   QLabel *l1 = new QLabel(QString::fromStdString(plos_str),qd);
    pen.setColor(Qt::blue);
    select = true;
    QPushButton *button = new QPushButton("Change params", qd);
    connect(button, SIGNAL(clicked()), this, SLOT(change_angle()));

    QPushButton *button_2 = new QPushButton("Change Direction", qd);
    connect(button_2, SIGNAL(clicked()), this, SLOT(change_direction()));
    button_2->move(0,20);
    QPushButton *button_3 = new QPushButton("Plus size", qd);
    connect(button_3, SIGNAL(clicked()), this, SLOT(figure_plussize()));
    button_3->move(0,40);
    QPushButton *button_4 = new QPushButton("Minus size", qd);
    connect(button_4, SIGNAL(clicked()), this, SLOT(figure_minussize()));
    button_4->move(0,60);
   l->show();
   l1->show();
   l->move(0,80);
   l1->move(0,100);
    //z->move(0,20);
    //z->show();
    qd->exec();

    delete qd;



}

void Figure::change_angle(){
    figureDialog* pInputDialog = new figureDialog;
    if (pInputDialog->exec() == QDialog::Accepted) {
        if(type == 1){
            if(pInputDialog->PointA().size() > 0){
                ra1 = std::stoi(pInputDialog->PointA().toStdString());
            }
            if(pInputDialog->PointB().size() > 0){
                rb1 = std::stoi(pInputDialog->PointB().toStdString());
            }
            if(pInputDialog->PointC().size() > 0){
                x1 = std::stoi(pInputDialog->PointC().toStdString());
            }
            if(pInputDialog->PointE().size() > 0){
                re1 = std::stoi(pInputDialog->PointE().toStdString());
            }
            if(pInputDialog->PointF().size() > 0){
                p1 = std::stoi(pInputDialog->PointF().toStdString());
            }
            if(pInputDialog->PointDegree().size() > 0){
                rotate1 = std::stoi(pInputDialog->PointDegree().toStdString());
                if(figure_size < 6) figure_size = 6;
            }

            this->repaint();
        }
        if(type == 2){
            if(pInputDialog->PointA().size() > 0){
                ax2 = std::stoi(pInputDialog->PointA().toStdString());
            }
            if(pInputDialog->PointB().size() > 0){
                bx2 = std::stoi(pInputDialog->PointB().toStdString());
            }
            if(pInputDialog->PointC().size() > 0){
                cx2 = std::stoi(pInputDialog->PointC().toStdString());
            }
            if(pInputDialog->PointD().size() > 0){
                rd2 = std::stoi(pInputDialog->PointD().toStdString());
            }
            if(pInputDialog->PointE().size() > 0){
                p2 = std::stoi(pInputDialog->PointE().toStdString());
            }
            if(pInputDialog->PointF().size() > 0){
                rf2 = std::stoi(pInputDialog->PointF().toStdString());
            }
            if(pInputDialog->PointDegree().size() > 0){
                rotate2 = std::stoi(pInputDialog->PointDegree().toStdString());
                if(figure_size < 6) figure_size = 6;
            }
            this->repaint();
        }
        //this->calculatePlosAndPer();
    }
    delete pInputDialog;

}
void Figure::change_direction(){
    dir *=-1;
}
void Figure::calculatePlosAndPer(){

  if(type == 1){
    perimeter = (wper+hper)*2 - 4*x1+(p1+p2/2)/2-2*ra1+ra1/2-2*rb1+rb1/2 + re1/2;
    ploshad = wper*hper - x1*x1+p1*p1/2 -3.14*ra1*ra1/4+3.14*re1*re1/2-rb1*rb1+3.14*rb1*rb1/4;
  }
  else{
    perimeter = (wper+hper)*2-3.14*2*rd2/4+(p2+p2/2)*2-sqrt(ax2*ax2*2)-sqrt(bx2*bx2*2)+rf2*2*3.14/2-sqrt(cx2*cx2*2);
    ploshad = wper*hper - p2*p2/2-3.14*rd2*rd2/4-ax2*ax2/2-bx2*bx2/2+3.14*rf2*rf2*2-cx2*cx2/2;
  }

}
