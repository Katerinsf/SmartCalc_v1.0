#include "graph.h"
#include "ui_graph.h"

Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
    setFixedSize(geometry().width(),geometry().height());
    ui->lineEdit_x_min->setText("");
    ui->lineEdit_x_max->setText("");
    ui->lineEdit_y_min->setText("");
    ui->lineEdit_y_max->setText("");

   connect(ui->pushButton_plot, SIGNAL(clicked()), this, SLOT(plot_new_graph()));
}

Graph::~Graph()
{
    delete ui;
}

void Graph::plot_graph() {
    double x_min, x_max, y_min, y_max, h = 1e-3;
    Data x_i = {0.0, EMPTY};
    double y_i;

    QByteArray array = str_expression.toLatin1();
    char *str = array.data();

    if (ui->lineEdit_x_min->text().isEmpty() || ui->lineEdit_x_max->text().isEmpty() || 
      ui->lineEdit_x_min->text().toDouble() >= ui->lineEdit_x_max->text().toDouble() || 
      ui->lineEdit_x_min->text().toDouble() < MIN || ui->lineEdit_x_max->text().toDouble() > MAX) {
        x_min = -5.0;
        x_max = 5.0;      
    } else {
        x_min = ui->lineEdit_x_min->text().toDouble();
        x_max = ui->lineEdit_x_max->text().toDouble();
    }

    if (ui->lineEdit_y_min->text().isEmpty() || ui->lineEdit_y_max->text().isEmpty() || 
      ui->lineEdit_y_min->text().toDouble() >= ui->lineEdit_y_max->text().toDouble() || 
      ui->lineEdit_y_min->text().toDouble() < MIN || ui->lineEdit_y_max->text().toDouble() > MAX) {
        y_min = x_min;
        y_max = x_max;  
    } else {
        y_min = ui->lineEdit_y_min->text().toDouble();
        y_max = ui->lineEdit_y_max->text().toDouble();
    }

    x.clear();
    y.clear();
    ui->widget->clearGraphs();

    ui->widget->xAxis->setRange(x_min, x_max);
    ui->widget->yAxis->setRange(y_min, y_max);
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget->setInteraction(QCP::iRangeZoom, true);

    for (double i = x_min; i <= x_max; i+= h) {
        x.push_back(i);
        x_i.type = VAR;
        x_i.num = i;
        calc(str, x_i, &y_i);
        y.push_back(y_i);
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}


void Graph::plot_new_graph() {
    plot_graph();
}

