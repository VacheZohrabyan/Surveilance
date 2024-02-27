#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    msgBox = new QMessageBox(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty()) {
        msgBox->setText("Its Empty");
        ui->lineEdit->clear();
    }
    else {
        msgBox->setText("Its not empty");
        ui->lineEdit->clear();
    }
    msgBox->exec();

    }


