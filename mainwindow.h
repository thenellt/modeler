#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stackedwidget.h"
#include "startscreen.h"
#include "setupsimulation.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    //void newButton();
    //void loadButton();

private slots:
    //void on_pushButton_pressed();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stack;
};

#endif // MAINWINDOW_H
