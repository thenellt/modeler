#include "startscreen.h"
#include "ui_startscreen.h"
#include <iostream>

startScreen::startScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startScreen)
{
    ui->setupUi(this);
    std::cout << "inside startscreen constructor" << std::endl;
    //connect(ui->pushButton, SIGNAL(pressed()), parent, parent->SLOT()
}

startScreen::~startScreen()
{
    delete ui;
}

QWidget* startScreen::getNewsimButton(){
    return ui->pushButton;
}

void startScreen::on_pushButton_pressed()
{
    std::cout << "new simulation button was pressed" << std::endl;
    emit indexChange(1);
}
