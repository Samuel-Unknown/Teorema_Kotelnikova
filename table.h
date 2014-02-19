#ifndef TABLE_H
#define TABLE_H
#include <graphics.h>
#include <QVector>
#include <QTableWidget>
#include <QString>

class Table : public MyPaint {

    Q_OBJECT // нужно ибо используем сигналы

public:
    explicit Table(QWidget *parent = 0);
    ~Table();
    int rows; // строк в таблице
    int columns; // столбцов в таблице
    QVector < QVector <double> >  table; // таблица для сравнения Y-ов исходной функции и восстановленной функции

protected:
    void paintEvent(QPaintEvent * event); // обработчик события отрисовки
};

#endif // TABLE_H
