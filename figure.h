#ifndef FIGURE_H
#define FIGURE_H
#include <QWidget>
#include <QPainter>
class Figure: public QWidget
{
    Q_OBJECT
    bool flag_paint;
    bool flag_resize;
    QPoint point;
    QPen pen;
    bool select;
    int type;
    int rotate1;
    int rotate2;
    int dir;
   uint64_t start_p = 150;
   uint figure_size = 6;
   uint64_t p1;
   uint64_t x1;
   uint64_t re1;
   uint64_t ra1;
   uint64_t rb1;
   uint64_t rd2;
   uint64_t rf2;
   uint64_t p2;
   uint64_t ax2;
   uint64_t bx2;
   uint64_t cx2;
   uint64_t wper;
   uint64_t hper;
   uint64_t perimeter;
   uint64_t ploshad;

public:
    explicit Figure(QWidget *parent = 0,int _type = 1);
    bool isselect(){
        return select;
    }

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);
    void calculatePlosAndPer();
signals:

public slots:
    void change_angle();
    void change_direction();
    void figure_plussize(){
        figure_size -= 1;
        if(figure_size < 3) figure_size = 3;
        this->repaint();
    }
    void figure_minussize(){
        figure_size+=1;
        this->repaint();
    }
};

#endif // FIGURE_H
