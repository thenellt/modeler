#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>

namespace Ui {
class startScreen;
}

class startScreen : public QWidget
{
    Q_OBJECT

public:
    explicit startScreen(QWidget *parent = 0);
    QWidget* getNewsimButton();
    ~startScreen();

private slots:
    void on_pushButton_pressed();

signals:
    void indexChange(int i);

private:
    Ui::startScreen *ui;
};

#endif // STARTSCREEN_H
