#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(geometry().width(),geometry().height());
    // ui->label->setFocusPolicy(Qt::ClickFocus);
    // ui->label_x->setFocusPolicy(Qt::ClickFocus);
    // ui->label->setFocus();

    ui->lineEdit->setFocusPolicy(Qt::ClickFocus);
    ui->lineEdit_x->setFocusPolicy(Qt::ClickFocus);
    ui->label->setFocusPolicy(Qt::ClickFocus);
    ui->lineEdit->setText("");
    ui->lineEdit_x->setText("");
    ui->label->setText("");

    ui->lineEdit->setFocus();

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(symb_input()));

    connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(symb_input_div()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_lpar, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_rpar, SIGNAL(clicked()), this, SLOT(symb_input()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(symb_input()));

    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(func_input()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(func_input()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(func_input()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(func_input()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(func_input()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(func_input()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(func_input()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(func_input()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(symb_input_sqrt()));

    connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(clear()));

    connect(ui->pushButton_eq, SIGNAL(clicked()), this, SLOT(print_result()));
    connect(ui->pushButton_graph, SIGNAL(clicked()), this, SLOT(window_graph()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::symb_input() {
    QPushButton *button = (QPushButton *)sender();
    if (ui->lineEdit->hasFocus()) ui->lineEdit->insert(button->text());
    else if (ui->lineEdit_x->hasFocus()) ui->lineEdit_x->insert(button->text());
}

void MainWindow::func_input() {
    QPushButton *button = (QPushButton *)sender();
    if (ui->lineEdit->hasFocus()) ui->lineEdit->insert(button->text() + "(");
}

void MainWindow::symb_input_sqrt() {
    if (ui->lineEdit->hasFocus()) ui->lineEdit->insert("sqrt(");
}

void MainWindow::symb_input_div() {
    if (ui->lineEdit->hasFocus()) ui->lineEdit->insert("/");
    else if (ui->lineEdit_x->hasFocus()) ui->lineEdit_x->insert("/");
}

void MainWindow::clear() {
    if (ui->lineEdit->hasFocus()) ui->lineEdit->setText("");
    else if (ui->lineEdit_x->hasFocus()) ui->lineEdit_x->setText("");
    else if (ui->label->hasFocus()) ui->label->setText("");
}

void MainWindow::print_result() {
    double result;
    Data x = {0.0, EMPTY};
    QString qstr_x = ui->lineEdit_x->text();
    if (!qstr_x.isEmpty()) {
        x.type = VAR;
        x.num = qstr_x.toDouble();
    }

    QByteArray array = ui->lineEdit->text().toLatin1();
    char *str = array.data();
    int code_error = calc(str, x, &result);

    if (code_error == OK) {
        ui->label->setText(QString::number(result, 'f', 7));
    } else if (code_error == ERROR_SYNTAX) {
        ui->label->setText("Неверное выражение");
    } else if (code_error == ERROR_MEM) {
        ui->label->setText("Проблемы с памятью");
    } else if (code_error == ERROR_X) {
        ui->label->setText("Введите значение переменной");
    } else if (code_error == ERROR_EMPTY) {
        ui->label->setText("Введите выражение");
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
   if (event->key() == Qt::Key_Return) {
       print_result();
   } else {
       event->ignore();
   }
}

void MainWindow::window_graph() {
    double result;
    Data x = {0.0, EMPTY};
    QByteArray array = ui->lineEdit->text().toLatin1();
    char *str = array.data();
    int code_error = calc(str, x, &result);

    if (code_error == ERROR_SYNTAX) {
        ui->label->setText("Неверное выражение");
    } else if (code_error == ERROR_MEM) {
        ui->label->setText("Проблемы с памятью");
    } else if (code_error == ERROR_EMPTY) {
        ui->label->setText("Введите выражение");
    } else {
        // Building a graph
        my_graph.str_expression = ui->lineEdit->text();
        my_graph.plot_graph();
        my_graph.show();
    }
}
