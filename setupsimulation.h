#ifndef SETUPSIMULATION_H
#define SETUPSIMULATION_H

#include <QWidget>
#include <QString>
#include <iostream>
#include "qdebug.h"
#include "advancedoptions.h"
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
    int checkParameters();

signals:
    void indexChange(int i);

public slots:
    void advDialogClosed();
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

    void on_advancedOptions_pressed();

    void on_durationValue_returnPressed();

    void on_carryValue_returnPressed();

    void on_rangeValue_returnPressed();

    void on_huntValue_returnPressed();

    void on_killValue_returnPressed();

    void on_heightValue_returnPressed();

    void on_widthValue_returnPressed();

    void on_latValue_returnPressed();

    void on_longValue_returnPressed();

private:
    Ui::SetupSimulation *ui;
    parameters *setup;
    bool ready;
    bool dialogOpen;
    bool *checked;
    QDialog *advanced;
};

#endif // SETUPSIMULATION_H
