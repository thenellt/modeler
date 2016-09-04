#include "loadingscreen.h"
#include "ui_loadingscreen.h"

loadingScreen::loadingScreen(QWidget *parent, parameters *setup) :
    QWidget(parent),
    ui(new Ui::loadingScreen)
{
    ui->setupUi(this);
    this->setup = setup;

    ui->progressBar->setValue(0);
}

loadingScreen::~loadingScreen()
{
    delete ui;
}

void loadingScreen::setSimulation(processor* sim){
    simulation = sim;

    connect(simulation, SIGNAL(progressUpdate(int)), this, SLOT(updateProgBar(int)));
    connect(simulation, SIGNAL(progressImages(int)), this, SLOT(updateProgImages(int)));

    std::cout << "setup signals" << std::endl;
    simulation->runSimulation();
}

void loadingScreen::updateProgBar(int year){
    std::cout << "in update prog bar" << std::endl;
    ui->progressBar->setValue((year/setup->years)*100);
    ui->details->setText("Currently processing population simulation for year " + QString::number(year) + " out of " + QString::number(setup->years) + "...");
}

void loadingScreen::updateProgImages(int i){
    if(setup->years == 1 || setup->output[0] == 2){
        ui->progressBar->setValue(100);
        ui->details->setText("Currently generating image 1 of 1...");
    }
    else{
        ui->progressBar->setValue((i/setup->years)*100);
        ui->details->setText("Currently generating image " + QString::number(i) + " out of " + QString::number(setup->years) + "...");
    }
}
