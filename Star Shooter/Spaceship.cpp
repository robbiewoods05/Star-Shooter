#include "Spaceship.h"
#include "objects.h"
#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro5.h"


using namespace ENUMS;

void Spaceship::init(Spaceship &ship)
{
	ship.ID = PLAYER;
	ship.x = 20;
    ship.y = HEIGHT / 2;
    ship.lives = 3;
    ship.speed = 7;
    ship.boundX = 6;
    ship.boundY = 7;
    ship.score = 0;
}


void Spaceship::draw(Spaceship &ship)
{
	al_draw_filled_rectangle(ship.x, ship.y - 9, ship.x + 10, ship.y - 7, al_map_rgb(255, 0, 0));
    al_draw_filled_rectangle(ship.x, ship.y + 9, ship.x + 10, ship.y + 7, al_map_rgb(255, 0, 0));

    al_draw_filled_triangle(ship.x - 12, ship.y - 17, ship.x + 12, ship.y, ship.x - 12, ship.y + 17, al_map_rgb(0, 255, 0));
    al_draw_filled_rectangle(ship.x - 12, ship.y - 2, ship.x + 15, ship.y + 2, al_map_rgb(0, 0, 255));
}


void Spaceship::moveUp(Spaceship &ship)
{
	ship.y -= ship.speed;
    if (ship.y < 0)
	ship.y = 0;
}

void Spaceship::moveDown(Spaceship &ship)
{
	ship.y += ship.speed;
    if (ship.y > HEIGHT)
	ship.y = 400;
}

void Spaceship::moveLeft(Spaceship &ship)
{
	ship.x -= ship.speed;
    if (ship.x < 0)
	ship.x = 0;
}

void Spaceship::moveRight(Spaceship &ship)
{
	ship.x += ship.speed;
    if (ship.x > 300)
	ship.x = 300;
}
