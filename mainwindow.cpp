#include "mainwindow.h"
#include "graphics.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <origingraph.h>
#include <lessgraph.h>
#include <largergraph.h>
#include <optimalgraph.h>
#include <table.h>
#include <QTableWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    originGraph *o_origin = new originGraph;       // исходная периодическая функция
    lessGraph *o_less = new lessGraph;              // частота дискретизации ниже оптимальной
    largerGraph *o_larger = new largerGraph;     // частота дискретизации выше оптимальной
    optimalGraph *o_optimal = new optimalGraph;    // частота дискретизации выше оптимальной

    // задаём верхнюю частоту
    double max = 11.0 / (M_PI * 2);
    o_less->setTopF(max);
    o_larger->setTopF(max);
    o_optimal->setTopF(max);

// прицепляем к макету графики
    ui->originGridLayout->addWidget(o_origin);
    ui->lessGridLayout->addWidget(o_less);
    ui->largerGridLayout->addWidget(o_larger);
    ui->optimalGridLayout->addWidget(o_optimal);

    Table *tab = new Table;
    tab->setTopF(max);

    QTableWidget *tableWidget = new QTableWidget(tab->rows, tab->columns, this);

    for(int row=0; row < tab->rows; row++){
        for(int column=0; column < tab->columns; column++) {
            QTableWidgetItem *newItem = new QTableWidgetItem(QString("%1").arg(tab->table[row][column], 1, 'f', 3));
            tableWidget->setItem(row, column, newItem);
        }
    }

    ui->gridLayout->addWidget(tableWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
