#include "doom.h"
#include "ui_doom.h"

Doom::Doom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Doom)
{
    ui->setupUi(this);
}

Doom::~Doom()
{
    delete ui;
}
