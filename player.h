#ifndef PLAYER_H
#define PLAYER_H
#define M_PI 3.1415926535
#include <QtCore/qmath.h>

class Player
{
public:
    float player_x = 3.456; // player x position
    float player_y = 2.345; // player y position
    float player_a = 1.523; // player view direction (in radians equal 90 gradus)
    const float fov = M_PI / 3.; // field of view (in radians equal 60 gradus)
    float angle = player_a - fov / 2;
public:
    Player();
    void move(uint);
};

#endif // PLAYER_H
