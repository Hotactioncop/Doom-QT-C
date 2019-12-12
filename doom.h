#ifndef DOOM_H
#define DOOM_H

#include <QMainWindow>

namespace Ui {
class Doom;
}

class Doom : public QMainWindow
{
    Q_OBJECT

public:
    explicit Doom(QWidget *parent = nullptr);
    ~Doom();

private:
    Ui::Doom *ui;
};

#endif // DOOM_H
