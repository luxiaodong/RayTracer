#include "widget.h"
#include "ui_widget.h"

#include "World.h"

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
    World* w = new World();
    w->build();
    w->render_scene();
    m_image = w->image;
    QWidget::show();
}

void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawImage( QRectF(0,0,this->width(), this->height()), *m_image);
}
