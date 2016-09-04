#include "setupoutput.h"
#include "ui_setupoutput.h"

setupOutput::setupOutput(QWidget *parent, parameters* setup) :
    QWidget(parent),
    ui(new Ui::setupOutput)
{
    ui->setupUi(this);
    this->setup = setup;

    ui->heatAll->setEnabled(false);
    ui->heatFinal->setEnabled(false);
    ui->configPopCheck->setEnabled(false);
    ui->csvAll->setEnabled(false);
    ui->csvFinal->setEnabled(false);
}

setupOutput::~setupOutput()
{
    delete ui;
}

void setupOutput::setParameters(parameters *setup){
    this->setup = setup;
}

void setupOutput::on_heatmapCheck_toggled(bool checked)
{
    if(checked){
        ui->heatAll->setEnabled(true);
        ui->heatFinal->setEnabled(true);

        if(ui->heatAll->isChecked()){
            setup->output[0] = 1;
        }
        else{
            setup->output[0] = 2;
        }
    }
    else{
        ui->heatAll->setEnabled(false);
        ui->heatFinal->setEnabled(false);

        setup->output[0] = 0;
    }
}

void setupOutput::on_heatFinal_toggled(bool checked)
{
    if(checked){
        setup->output[0] = 2;
    }
    else{
        setup->output[0] = 1;
    }
}

void setupOutput::on_csvCheck_toggled(bool checked)
{
    if(checked){
        ui->csvAll->setEnabled(true);
        ui->csvFinal->setEnabled(true);

        if(ui->csvAll->isChecked()){
            setup->output[1] = 1;
        }
        else{
            setup->output[1] = 2;
        }
    }
    else{
        ui->csvAll->setEnabled(false);
        ui->csvFinal->setEnabled(false);

        setup->output[1] = 0;
    }
}

void setupOutput::on_csvFinal_toggled(bool checked)
{
    if(checked){
        setup->output[1] = 2;
    }
    else{
        setup->output[1] = 1;
    }
}

void setupOutput::on_configCheck_toggled(bool checked)
{
    if(checked){
        ui->configPopCheck->setEnabled(true);
        if(ui->configPopCheck->isChecked()){
            setup->output[2] = 2;
        }
        else{
            setup->output[2] = 1;
        }
    }
    else{
        ui->configPopCheck->setEnabled(false);
        setup->output[2] = 0;
    }
}

void setupOutput::on_popCheck_toggled(bool checked)
{
    if(checked){
        setup->output[3] = 1;
    }
    else{
        setup->output[3] = 0;
    }
}

void setupOutput::on_run_pressed()
{
    emit indexChange(5);
}
