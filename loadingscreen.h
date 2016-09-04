#ifndef LOADINGSCREEN_H
#define LOADINGSCREEN_H

#include <QWidget>
#include "modeler.h"
#include <iostream>

namespace Ui {
class loadingScreen;
}

class loadingScreen : public QWidget
{
    Q_OBJECT

public:
    explicit loadingScreen(QWidget *parent = 0, parameters* = 0);
    ~loadingScreen();

    void setSimulation(processor*);

public slots:
    void updateProgBar(int);
    void updateProgImages(int);

signals:
    void indexChange(int i);

private:
    Ui::loadingScreen *ui;
    parameters *setup;
    processor *simulation;
};

#endif // LOADINGSCREEN_H
