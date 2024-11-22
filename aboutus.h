#ifndef ABOUTUS_H
#define ABOUTUS_H

#include <QWidget>
#include <QPainter>
#include <QtGui>
#include <QtCore>
#include <QPaintEvent>


namespace Ui {
class aboutUs;
}

class aboutUs : public QWidget
{
    Q_OBJECT

public:
    explicit aboutUs(QWidget *parent = nullptr);
    ~aboutUs();
private slots:


protected:
    void paintEvent(QPaintEvent *event);



private:
    Ui::aboutUs *ui;


};

#endif // ABOUTUS_H
