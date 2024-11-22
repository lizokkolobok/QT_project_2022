#include "aboutus.h"
#include "ui_aboutus.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <QWidget>
#include <QDialog>
#include <QPainter>
#include <QPaintEvent>

aboutUs::aboutUs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutUs)
{
    ui->setupUi(this);

    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(close()));

}



aboutUs::~aboutUs()
{
    delete ui;
}

//paint event is called when the widget is created,
//and also if it is necessary to redraw it, for example,
//as a result of changing the size of the widget.
//QPainter object which allow to draw primitive figures

void aboutUs::paintEvent(QPaintEvent *event)
{
   QPainter painter(this);
   QPen pen(Qt::white, 10);
   painter.setPen(pen);
   QBrush figBrush(Qt::GlobalColor::green);
   painter.setBrush(figBrush);
   painter.drawEllipse(60, 60, 200, 200);
   QFont font = painter.font();
   font.setPointSize(120);
   painter.setFont(font);
   painter.drawText(QPoint(125,200), "S" );
   painter.setPen(QPen(Qt::gray));
   painter.setFont(QFont("Times", 20));
   painter.drawText(QRect(10,10,110,130), "Student 150");

}






