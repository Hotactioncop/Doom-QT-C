#ifndef GAMEZONE_H
#define GAMEZONE_H

#include <QWidget>
#include <QSize>
#include <QVector>
#include <QString>
#include <QColor>
#include <QPainter>
#include <QtCore/qmath.h>
#include <QDebug>
#include <QPair>
#include <QPoint>
#include <QEvent>
#include <QKeyEvent>
#include "player.h"

class GameZone : public QWidget
{
    Q_OBJECT
    QSize s;
    const size_t win_w = 1024; // image width
    const size_t win_h = 512;  // image height
    QVector<QColor> framebuffer;
    const size_t map_w = 16; // map width
    const size_t map_h = 16; // map height
    const size_t rect_w = win_w / (map_w * 2);
    const size_t rect_h = win_h / map_h;
    Player* play;
    uint idTimer;
    bool gameOn = false;
    size_t rect_x;
    size_t rect_y;
    //QVector<std::pair<std::pair<QPoint, QPoint>,QColor>> game;
    QVector<std::pair<std::pair<size_t,QPoint>, uint>> game;
    QVector<QPoint> my_ray;
    QVector< QColor> color{QColor(47,60,78),QColor(79,112,135),QColor(252,176,65),QColor(222,112,60)};
    QVector<QPixmap> pixes{QPixmap(":/Images/Image/BackGround.png"),QPixmap(":/Images/Image/BackGround1.png"),QPixmap(":/Images/Image/BackGround2.png"),QPixmap(":/Images/Image/BackGround3.png")};
    const char map[257] =
    {
        "0000222222220000"\
        "1         1    0"\
        "1         1    0"\
        "1              0"\
        "0   0000       0"\
        "0   2       2220"\
        "0   2   1      0"\
        "0   2   1      0"\
        "0       1311   0"\
        "0       0      0"\
        "0  11   0      0"\
        "2   2   0  23  0"\
        "0   20300   2  0"\
        "0           2  0"\
        "0           2  0"\
        "0002222222200000"
    }; // our game map

friend class Player;

public:
    explicit GameZone(QWidget *parent = nullptr);
private:

signals:

public slots:
    void StartGame();

    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event);

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // GAMEZONE_H
