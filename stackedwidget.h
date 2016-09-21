#ifndef STACKEDWIDGET_H
#define STACKEDWIDGET_H

#include "startscreen.h"
#include "setupsimulation.h"
#include "selectworkingdirectory.h"
#include "setupmap.h"
#include "setupoutput.h"
#include "loadingscreen.h"
#include "postscreen.h"
#include "modeler.h"
#include <QStackedWidget>

namespace Ui {
class StackedWidget;
}

class StackedWidget : public QStackedWidget
{
    Q_OBJECT

public:
    explicit StackedWidget(QWidget *parent = 0);
    ~StackedWidget();

    processor* getModelPointer();
    parameters* getSetupPointer();

    bool checkSetupParams();

signals:
    void changeToOutput();

public slots:
    void changeIndex(int);

private:
    Ui::StackedWidget *ui;
    processor *model;
    parameters *param;
    loadingScreen *load;
};

#endif // STACKEDWIDGET_H
