#include "figuredialog.h"
#include <QLabel>
#include<QPushButton>
#include <QGridLayout>
figureDialog::figureDialog(QWidget* pwgt/*= 0*/):QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)

{
    m_ptxtPointA = new QLineEdit;
    m_ptxtPointB = new QLineEdit;
    m_ptxtPointC = new QLineEdit;
    m_ptxtPointD = new QLineEdit;
    m_ptxtPointE = new QLineEdit;
    m_ptxtPointF = new QLineEdit;
    m_ptxtPointDegree = new QLineEdit;
    QLabel* plblPointA = new QLabel("&PointA");
    QLabel* plblPointB = new QLabel("&PointB");
    QLabel* plblPointC = new QLabel("&PointC");
    QLabel* plblPointD = new QLabel("&PointD");
    QLabel* plblPointE = new QLabel("&PointE");
    QLabel* plblPointF = new QLabel("&PointF");
    QLabel* plblPointDegree = new QLabel("&PointDegree");
    plblPointA->setBuddy(m_ptxtPointA);
    plblPointB->setBuddy(m_ptxtPointB);
    plblPointC->setBuddy(m_ptxtPointC);
    plblPointD->setBuddy(m_ptxtPointD);
    plblPointE->setBuddy(m_ptxtPointE);
    plblPointF->setBuddy(m_ptxtPointF);
    plblPointDegree->setBuddy(m_ptxtPointDegree);
    QPushButton* pcmdOk = new QPushButton("&Ok");
    QPushButton* pcmdCancel = new QPushButton("&Cancel");
    connect(pcmdOk, SIGNAL(clicked()), SLOT(accept()));
    connect(pcmdCancel, SIGNAL(clicked()), SLOT(reject()));
    //Layout setup
    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(plblPointA, 0, 0);
    ptopLayout->addWidget(m_ptxtPointA, 0, 1);
    ptopLayout->addWidget(plblPointB, 1, 0);
    ptopLayout->addWidget(m_ptxtPointB, 1, 1);
    ptopLayout->addWidget(plblPointC, 2, 0);
    ptopLayout->addWidget(m_ptxtPointC, 2, 1);

    ptopLayout->addWidget(plblPointD, 3, 0);
    ptopLayout->addWidget(m_ptxtPointD, 3, 1);

    ptopLayout->addWidget(plblPointE, 4, 0);
    ptopLayout->addWidget(m_ptxtPointE, 4, 1);
    ptopLayout->addWidget(plblPointF, 5, 0);
    ptopLayout->addWidget(m_ptxtPointF, 5, 1);
    ptopLayout->addWidget(plblPointDegree, 6, 0);
    ptopLayout->addWidget(m_ptxtPointDegree, 6, 1);
    ptopLayout->addWidget(pcmdOk, 7,0);
    ptopLayout->addWidget(pcmdCancel, 7, 1);
    setLayout(ptopLayout);
}
QString figureDialog::PointA() const{
    return m_ptxtPointA->text();
}
QString figureDialog::PointB() const{
    return m_ptxtPointB->text();
}
QString figureDialog::PointC() const{
    return m_ptxtPointC->text();
}
QString figureDialog::PointD() const{
    return m_ptxtPointD->text();
}
QString figureDialog::PointE() const{
    return m_ptxtPointE->text();
}
QString figureDialog::PointF() const{
    return m_ptxtPointF->text();
}
QString figureDialog::PointDegree() const{
    return m_ptxtPointDegree->text();
}
