#ifndef LESSGRAPH_H
#define LESSGRAPH_H

#include <graphics.h>
#include <QWidget>

class lessGraph : public MyPaint {

   Q_OBJECT // нужно ибо используем сигналы

public:
    explicit lessGraph(QWidget *parent = 0);
    ~lessGraph();

protected:
    void paintEvent(QPaintEvent * event); // обработчик события отрисовки
};

#endif // LESSGRAPH_H
