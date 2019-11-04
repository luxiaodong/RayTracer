#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QDebug>

#include "raytracer.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void show();

protected:
    void paintEvent(QPaintEvent* );

private:
    Ui::Widget *ui;

    RayTracer* m_rayTracer;
};

#endif // WIDGET_H
