#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->createBtn, SIGNAL(clicked()), this, SLOT(newProfile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newProfile()
{
    CreateDialog::newProfile(manager);
    manager->refreshList(ui->comboBox);
    qDebug() << "Manager size:" << manager->profiles.size();
}
