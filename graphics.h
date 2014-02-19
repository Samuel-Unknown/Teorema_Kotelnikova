#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>
#include <QString>
#include <QTableWidget>
#include <QVector>

class MyPaint : public QWidget {

   Q_OBJECT // нужно ибо используем сигналы

public:
    double top_F; // расчитать! верхняя частота (Гц)
    double deltaT; // отсчёты
    int lower, top; // нижнее и верхнее значение суммирования в формуле

    MyPaint(QWidget *parent = 0);
    ~MyPaint();
    double myFunction(double x);  // фуннкция для преобразования
    double recoverFunction(double x);  // восстановленная фуннкция
    void setTopF(double F); // задаём наивысшую частоту
    double sinc(double x);     // функция sinc(x) = sin(x) / x при x != 0,  sinc(0) = 1;

protected:
    void paintEvent(QPaintEvent * event); // обработчик события отрисовки
};

#endif // GRAPHICS_H
