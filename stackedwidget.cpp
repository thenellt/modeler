#include "stackedwidget.h"
#include "ui_stackedwidget.h"
#include <iostream>

StackedWidget::StackedWidget(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::StackedWidget)
{
    ui->setupUi(this);
    std::cout << "in stacked widget constructor" << std::endl;

    param = new parameters;
    param->setupComplete = false;

    startScreen *start= new startScreen;
    SetupSimulation *setup = new SetupSimulation;
    selectWorkingDirectory *dir = new selectWorkingDirectory(this, param);
    setupMap *map = new setupMap(this, param);
    setupOutput *out = new setupOutput(this, param);
    load = new loadingScreen(this, param);
    postScreen *post = new postScreen(this, param);

    setup->setParameters(param);
    out->setParameters(param);

    addWidget(start);
    addWidget(dir);
    addWidget(setup);
    addWidget(map);
    addWidget(out);
    addWidget(load);
    addWidget(post);

    setCurrentIndex(0);
    connect(start, SIGNAL(indexChange(int)), this, SLOT(changeIndex(int)));
    connect(dir, SIGNAL(indexChange(int)), this, SLOT(changeIndex(int)));
    connect(setup, SIGNAL(indexChange(int)), this, SLOT(changeIndex(int)));
    connect(map, SIGNAL(indexChange(int)), this, SLOT(changeIndex(int)));
    connect(out, SIGNAL(indexChange(int)), this, SLOT(changeIndex(int)));
    connect(load, SIGNAL(indexChange(int)), this, SLOT(changeIndex(int)));
    connect(post, SIGNAL(quit()), this, SLOT(close()));
    connect(this, SIGNAL(changeToOutput()), post, SLOT(changedTo()));
    //connect(post, SIGNAL(quit()), this, SLOT(quit()));

    setWindowTitle(tr("Population Modeler 1.0"));
    show();
}

StackedWidget::~StackedWidget()
{
    delete ui;
}

parameters* StackedWidget::getSetupPointer(){
    return param;
}

processor* StackedWidget::getModelPointer(){
    return model;
}

void StackedWidget::changeIndex(int i){
    if(i != 5){
        setCurrentIndex(i);
    }
    else{
        model = new processor(param);
        if(model == nullptr){
            exit(1);
        }

        connect(model, SIGNAL(progressUpdate(int)), widget(4), SLOT(updateProgBar(int)));
        connect(model, SIGNAL(progressImages(int)), widget(4), SLOT(updateProgImages(int)));

        dynamic_cast<setupMap*>(widget(3))->addVillages(model);
        //setCurrentIndex(5);
        model->runSimulation();
        emit changeToOutput();
        setCurrentIndex(6);
        //load->setSimulation(model);
    }
}

bool StackedWidget::checkSetupParams(){
    if(dynamic_cast<SetupSimulation*>(widget(2))->checkReady()){
        return true;
    }
    else{
        return false;
    }
}


