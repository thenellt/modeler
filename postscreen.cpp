#include "postscreen.h"
#include "ui_postscreen.h"

postScreen::postScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::postScreen)
{
    ui->setupUi(this);
}

postScreen::~postScreen()
{
    delete ui;
}

void postScreen::on_exit_pressed()
{
    emit quit();
}
