#ifndef POSTSCREEN_H
#define POSTSCREEN_H

#include <QWidget>

namespace Ui {
class postScreen;
}

class postScreen : public QWidget
{
    Q_OBJECT

public:
    explicit postScreen(QWidget *parent = 0);
    ~postScreen();

signals:
    void quit();

private slots:
    void on_exit_pressed();

private:
    Ui::postScreen *ui;
};

#endif // POSTSCREEN_H
