#ifndef ORIGINGRAPH_H
#define ORIGINGRAPH_H
#include <graphics.h>
#include <QWidget>

class originGraph : public MyPaint {

   Q_OBJECT // нужно ибо используем сигналы

public:
    explicit originGraph(QWidget *parent = 0);
    ~originGraph();

protected:
    void paintEvent(QPaintEvent * event); // обработчик события отрисовки
};

#endif // ORIGINGRAPH_H
