#include "optimalgraph.h"

#include "lessgraph.h"
#include <QPainter>

optimalGraph::optimalGraph(QWidget *parent) : MyPaint(parent)
{
}

optimalGraph::~optimalGraph()
{
}

void optimalGraph::paintEvent(QPaintEvent * /*event*/)
{
    QPainter painter(this);
    QPoint *firstP = new QPoint;        // начальная точка
    QPoint *secondP = new QPoint;   // конечная точка

    int recSizeX = 210, recSizeY = 210;  // размер прямоугольника в котором рисуем
    double multiplyX; // масштаб оси X (*)
    double multiplyY; // масштаб оси Y (*)
    int intervalXleft;      // начало оси X
    int intervalXRight;   // конец оси X
    double step = 0.01; // шаг по оси X

//  рисуем фоновый прямоугольник в котором рисуем
    painter.setBrush(Qt::black);
    painter.setPen(QPen(Qt::blue, 2));
    painter.drawRect(0, 0, recSizeY, recSizeX);

// выбираем цвет для осей
    painter.setPen(QPen(Qt::gray, 1));

// рисуем оси X и Y
    // x
    painter.drawLine(QPointF(0, recSizeY / 2), QPointF(recSizeY, recSizeY / 2));
    // y
    painter.drawLine(QPointF(recSizeX /2, 0), QPointF(recSizeX / 2, recSizeX ));

    multiplyX = 20;
    multiplyY = 5;
    painter.setPen(QPen(Qt::green, 1));         // цвет построенной функции

    intervalXleft = - 10;
    intervalXRight = 10;

    firstP->setX(recSizeX /2 + intervalXleft * multiplyX);
    firstP->setY(recSizeY / 2 -  recoverFunction(intervalXleft) * multiplyY);

    deltaT = 1 / (2 * top_F);
//                qDebug() << "opt: " << deltaT;

    for (double i = intervalXleft + step; i <= intervalXRight; i+=step) {
        secondP->setX(recSizeX /2 + i * multiplyX);
        secondP->setY(recSizeY / 2 -  recoverFunction(i) * multiplyY);
        painter.drawLine(*firstP, *secondP);
        *firstP = *secondP;
    }

    //-------------накладываем поверх исходную функцию
    painter.setPen(QPen(Qt::darkBlue, 1));        // цвет построенной функции

    intervalXleft = - 10;
    intervalXRight = 10;

    firstP->setX(recSizeX /2 + intervalXleft * multiplyX);
    firstP->setY(recSizeY / 2 -  myFunction(intervalXleft)* multiplyY);

    for (double i = intervalXleft + 1; i <= intervalXRight; i+=step) {
        secondP->setX(recSizeX /2 + i * multiplyX);
        secondP->setY(recSizeY / 2 -  myFunction(i) * multiplyY);
        painter.drawLine(*firstP, *secondP);
        *firstP = *secondP;
    }
    //-------------
}
