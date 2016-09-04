#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    //connect(ui->newProjectButton, SIGNAL(pressed()), this, SLOT(newButton()));
    //ui->explanationText->setText("Hit the square button to the left of each parameter "
    //                             "for additional infomration about the parameter.");
    //connect(ui->loadProjectButton, SIGNAL(pressed()), this, SLOT(loadButton()));
    stack = new StackedWidget;
    startScreen *test = new startScreen;
    SetupSimulation *test1 = new SetupSimulation;
    stack->setFixedWidth(800);
    stack->setFixedHeight(600);
    stack->addWidget(test);
    stack->addWidget(test1);
    stack->setCurrentIndex(0);
    stack->connect(test->getNewsimButton(), SIGNAL(pressed()), SLOT(setCurrentIndex(1)));

    //QVBoxLayout *layout = new QVBoxLayout;
    //layout->addWidget(stack);
    stack->show();
    //setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::newButton(){
    std::cout << "newButton called" << std::endl;
    stack = new StackedWidget;
    stack->addWidget(new startScreen);

}

void MainWindow::loadButton(){
    std::cout << "load button hit" << std::endl;
}
*/
