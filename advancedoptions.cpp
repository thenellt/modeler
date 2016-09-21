#include "advancedoptions.h"
#include "ui_advancedoptions.h"

advancedOptions::advancedOptions(QWidget *parent, parameters *setup) :
    QDialog(parent),
    ui(new Ui::advancedOptions)
{
    ui->setupUi(this);
    this->setup = setup;
}

advancedOptions::~advancedOptions()
{
    delete ui;
}

void advancedOptions::on_done_pressed()
{
    emit dialog_closed();
    close();
}
