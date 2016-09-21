#ifndef SETUPOUTPUT_H
#define SETUPOUTPUT_H

#include <QWidget>
#include "modeler.h"

namespace Ui {
class setupOutput;
}

class setupOutput : public QWidget
{
    Q_OBJECT

public:
    explicit setupOutput(QWidget *parent = 0, parameters* = 0);
    ~setupOutput();

    void setParameters(parameters*);

signals:
    void indexChange(int i);

private slots:
    void on_heatmapCheck_toggled(bool checked);

    void on_heatFinal_toggled(bool checked);

    void on_csvCheck_toggled(bool checked);

    void on_csvFinal_toggled(bool checked);

    void on_configCheck_toggled(bool checked);

    void on_popCheck_toggled(bool checked);

    void on_run_pressed();

    void on_heatScale_toggled(bool checked);

    void on_heatScaleValue_valueChanged(int arg1);

private:
    Ui::setupOutput *ui;
    parameters *setup;
};

#endif // SETUPOUTPUT_H
