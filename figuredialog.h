#ifndef FIGUREDIALOG_H
#define FIGUREDIALOG_H
#include <QDialog>
#include <QLineEdit>
class figureDialog : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* m_ptxtPointA;
    QLineEdit* m_ptxtPointB;
    QLineEdit* m_ptxtPointC;
    QLineEdit* m_ptxtPointD;
    QLineEdit* m_ptxtPointE;
    QLineEdit* m_ptxtPointF;
    QLineEdit* m_ptxtPointDegree;

public:
    figureDialog(QWidget* pwgt = 0);
    QString PointA() const;
    QString PointB() const;
    QString PointC() const;
    QString PointD() const;
    QString PointE() const;
    QString PointF() const;
    QString PointDegree() const;
};

#endif // FIGUREDIALOG_H
