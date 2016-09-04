#include "selectworkingdirectory.h"
#include "ui_selectworkingdirectory.h"

selectWorkingDirectory::selectWorkingDirectory(QWidget *parent, parameters *setup) :
    QWidget(parent),
    ui(new Ui::selectWorkingDirectory)
{
    ui->setupUi(this);
    this->setup = setup;
    name = false;
    dir = false;
    ui->continue_2->setEnabled(true);
}

selectWorkingDirectory::~selectWorkingDirectory()
{
    delete ui;
}

void selectWorkingDirectory::on_pushButton_pressed()
{
    directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(directory.length() == 0){
        ui->label->setText("Folder couldn't be used, please try again:");
    }
    else{
        std::cout << "path is: " << directory.toStdString() << std::endl;
        setup->workingPath = directory.toStdString();
        dir = true;
    }
    on_continue_2_pressed();
}

void selectWorkingDirectory::checkReady(){
    if(name && dir){
        ui->continue_2->setEnabled(true);
    }
}

void selectWorkingDirectory::on_continue_2_pressed()
{
    if(name && dir){
        emit indexChange(2);
    }
}

void selectWorkingDirectory::on_name_returnPressed()
{
    std::cout << "name: " << ui->name->text().toStdString() << std::endl;
    if(ui->name->text().length() > 0){
        setup->name = ui->name->text().toStdString();
        name = true;
    }
    if(name && dir){
        emit indexChange(2);
    }
}

void selectWorkingDirectory::on_name_editingFinished()
{
    if(ui->name->text().length() > 0){
        setup->name = ui->name->text().toStdString();
        name = true;
    }
    checkReady();
}

void selectWorkingDirectory::on_name_textEdited(const QString &arg1)
{
    if(arg1.length() > 0){
        setup->name = arg1.toStdString();
        name = true;
    }
    checkReady();
}
