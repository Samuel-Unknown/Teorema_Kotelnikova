#include <graphics.h>
#include <math.h>
#include <QPainter>
#include <QDebug>

MyPaint::MyPaint(QWidget *parent) // конструктор класса MyPaint наследник QWidget
    : QWidget(parent)
{
    lower = -1000;
    top = 1000;
}

MyPaint::~MyPaint()
{
}

void MyPaint::paintEvent(QPaintEvent * /*event*/)
{
}

void MyPaint::setTopF(double F)
{
    top_F = F;
}

double MyPaint::myFunction(double x) {
//    return 2 * cos(11 * x);
    return 7*cos(3*x)+8*sin(7*x)-2*cos(11*x);
}

double MyPaint::sinc(double x) {

    if ( x == 0)
        return 1;
    else
        return sin(x) / (x);
}

double MyPaint::recoverFunction(double x) {
    double S = 0;
    double top_W = M_PI / deltaT;

    for(int i = lower; i < top; i++) {
        S += myFunction( i * deltaT ) * sinc( top_W * (x - i * deltaT) );
    }

    return S;
}
