#ifndef OPTIMALGRAPH_H
#define OPTIMALGRAPH_H

#include <graphics.h>
#include <QWidget>

class optimalGraph : public MyPaint {

   Q_OBJECT // нужно ибо используем сигналы

public:
    explicit optimalGraph(QWidget *parent = 0);
    ~optimalGraph();

protected:
    void paintEvent(QPaintEvent * event); // обработчик события отрисовки
};

#endif // OPTIMALGRAPH_H
