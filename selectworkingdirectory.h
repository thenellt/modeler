#ifndef SELECTWORKINGDIRECTORY_H
#define SELECTWORKINGDIRECTORY_H

#include <QWidget>
#include <QString>
#include <QFileDialog>
#include <iostream>
#include "modeler.h"

namespace Ui {
class selectWorkingDirectory;
}

class selectWorkingDirectory : public QWidget
{
    Q_OBJECT

public:
    explicit selectWorkingDirectory(QWidget *parent = 0, parameters* = 0);
    ~selectWorkingDirectory();

    void checkReady();

signals:
    void indexChange(int i);

private slots:
    void on_pushButton_pressed();

    void on_continue_2_pressed();

    void on_name_returnPressed();

    void on_name_editingFinished();

    void on_name_textEdited(const QString &arg1);

private:
    Ui::selectWorkingDirectory *ui;
    QString directory;
    parameters *setup;
    bool name;
    bool dir;
};

#endif // SELECTWORKINGDIRECTORY_H
