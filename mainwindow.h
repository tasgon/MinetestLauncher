#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "createdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void newProfile();
    void deleteSelected();
    void playSelected();

private:
    Ui::MainWindow *ui;
    ProfileManager *manager = new ProfileManager();
};

#endif // MAINWINDOW_H
