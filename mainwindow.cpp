#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->createBtn, SIGNAL(clicked()), this, SLOT(newProfile()));
    connect(ui->deleteBtn, SIGNAL(clicked()), this, SLOT(deleteSelected()));
    connect(ui->playBtn, SIGNAL(clicked()), this, SLOT(playSelected()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newProfile()
{
    CreateDialog::newProfile(manager);
    manager->refreshList(ui->comboBox);
}

void MainWindow::deleteSelected()
{
    manager->deleteByName(ui->comboBox->currentText());
    manager->refreshList(ui->comboBox);
}

void MainWindow::playSelected()
{
    manager->getByName(ui->comboBox->currentText()).play(ui->tabWidget);
}
