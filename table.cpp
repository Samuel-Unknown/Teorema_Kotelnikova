#include "table.h"
#include <graphics.h>
#include <math.h>
#include <QDebug>

Table::Table(QWidget *parent) : MyPaint(parent)
{
    rows = 20;
    columns = 2;
    table = QVector< QVector<double> >(rows, QVector<double> (columns) );

    top_F = 11.0 / (M_PI * 2);

    deltaT = 1 / (2 * top_F );

    for (int i = 0; i < rows; i++) {
        table[i][0] = myFunction(i);
        table[i][1] = recoverFunction(i);
    }
}

Table::~Table()
{
}

void Table::paintEvent(QPaintEvent *event)
{
}
