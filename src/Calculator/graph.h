#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QVector>

#include <iostream>

#define MIN -1e6
#define MAX 1e6

extern "C" {
#include "../back/s21_calc.h"
}


namespace Ui {
class Graph;
}

class Graph : public QDialog
{
    Q_OBJECT

public:
    void plot_graph();
    explicit Graph(QWidget *parent = nullptr);
//    char *str_expression;
    QString str_expression = QString("1");
    ~Graph();

private:
    Ui::Graph *ui;
    QVector<double> x, y;

private slots:
    void plot_new_graph();
};

#endif // GRAPH_H
