#ifndef SETUPMAP_H
#define SETUPMAP_H

#include <QWidget>
#include "modeler.h"

namespace Ui {
class setupMap;
}

class setupMap : public QWidget
{
    Q_OBJECT

public:
    explicit setupMap(QWidget *parent = 0, parameters* = 0, processor* = 0);
    ~setupMap();

    void addVillages(processor*);
signals:
    void indexChange(int i);

public slots:
    void itemSelected(int, int);

private slots:

    void on_back_pressed();

    void on_relative_toggled(bool checked);

    void on_geographic_toggled(bool checked);

    void on_clear_pressed();

    void on_add_pressed();

    void on_delete_2_pressed();

    void on_continue_2_pressed();

    void on_nameValue_returnPressed();

    void on_popValue_returnPressed();

    void on_xlongValue_returnPressed();

    void on_ylatValue_returnPressed();

private:
    Ui::setupMap *ui;
    bool ready;
    bool editMode;
    int row;
    parameters *setup;
    processor *model;
};

#endif // SETUPMAP_H
