#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
//#include <QVector>
#include <iostream>

#include <graph.h>

extern "C" {
#include "../back/s21_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
   void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui;
    Graph my_graph;

private slots:
    void symb_input();
    void func_input();
    void symb_input_sqrt();
    void symb_input_div();
    void clear();

    void print_result();
    void window_graph();
};

#endif // MAINWINDOW_H
