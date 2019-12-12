#include "player.h"

Player::Player()
{
    player_x = 3.456; // player x position
    player_y = 2.345; // player y position
    player_a = 1.523; // player view direction (in radians equal 90 gradus)
    angle = player_a - fov / 2;
}

void Player::move(uint direction)
{
    switch (direction){
    case 0:
        player_x += 0.5*cos(player_a);
        player_y += 0.5*sin(player_a);
        break;
    case 1:
        player_x -= 0.5*cos(player_a);
        player_y -= 0.5*sin(player_a);
        break;
    case 2:
        player_a -= 0.1;
        break;
    case 3:
        player_a += 0.1;
        break;
    }
    if(player_a>=2*M_PI){
        player_a-=2*M_PI;
    }
    if(player_a<0){
        player_a+=2*M_PI;
    }
}
