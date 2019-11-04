#include "widget.h"
#include "ui_widget.h"

#include "raytracer.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::show()
{
    m_rayTracer = new RayTracer();
    m_rayTracer->build();
    m_rayTracer->render();
    QWidget::show();
}

void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawImage( QRectF(0,0,this->width(), this->height()), *m_rayTracer->image());
}
