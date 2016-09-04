#ifndef SETUPSIMULATION_H
#define SETUPSIMULATION_H

#include <QWidget>
#include <QString>
#include <iostream>
#include "modeler.h"

namespace Ui {
class SetupSimulation;
}

class SetupSimulation : public QWidget
{
    Q_OBJECT

public:
    explicit SetupSimulation(QWidget *parent = 0);
    ~SetupSimulation();

    bool checkReady();

    void setParameters(parameters*);
    void checkParameters();

signals:
    void indexChange(int i);

public slots:

    //void testButton();

private slots:
    void on_huntHelp_pressed();

    void on_durationHelp_pressed();

    void on_carryHelp_pressed();

    void on_rangeHelp_pressed();

    void on_killHelp_pressed();

    void on_submit_pressed();

    void on_durationValue_editingFinished();

    void on_carryValue_editingFinished();

    void on_rangeValue_editingFinished();

    void on_huntValue_editingFinished();

    void on_killValue_editingFinished();

    void on_dimensionsHelp_pressed();

    void on_geoHelp_pressed();

    void on_heightValue_editingFinished();

    void on_widthValue_editingFinished();

    void on_latValue_editingFinished();

    void on_longValue_editingFinished();

private:
    Ui::SetupSimulation *ui;
    parameters *setup;
    bool ready;
    bool *checked;
};

#endif // SETUPSIMULATION_H
