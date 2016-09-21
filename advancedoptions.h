#ifndef ADVANCEDOPTIONS_H
#define ADVANCEDOPTIONS_H

#include <QDialog>
#include "modeler.h"

namespace Ui {
class advancedOptions;
}

class advancedOptions : public QDialog
{
    Q_OBJECT

public:
    explicit advancedOptions(QWidget *parent = 0, parameters* = 0);
    ~advancedOptions();

signals:
    void dialog_closed();

private slots:
    void on_done_pressed();

private:
    Ui::advancedOptions *ui;
    parameters *setup;
};

#endif // ADVANCEDOPTIONS_H
