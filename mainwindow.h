#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <vector>
#include "figure.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QMenu    *menuFigure;
    QAction  *actionFigure1;
    QToolBar* createToolBar();
    std::vector<Figure*> figures;
    bool figure_1 = true,figure_2 = true;

protected:
    void contextMenuEvent(QContextMenuEvent *event);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionfigure1_toggled(bool arg1);

    void on_actionfigure2_toggled(bool arg1);

    void on_actionadd_triggered();

    void on_actiondelete_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
