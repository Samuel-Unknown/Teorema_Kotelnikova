#ifndef LARGERGRAPH_H
#define LARGERGRAPH_H

#include <graphics.h>
#include <QWidget>
#include <QVector>

class largerGraph : public MyPaint {

   Q_OBJECT // нужно ибо используем сигналы

public:
    explicit largerGraph(QWidget *parent = 0);
    ~largerGraph();

protected:
    void paintEvent(QPaintEvent * event); // обработчик события отрисовки
};

#endif // LARGERGRAPH_H
