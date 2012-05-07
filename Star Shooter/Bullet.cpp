#include "Bullet.h"
#include "objects.h"
#include "allegro5\allegro5.h"
#include "allegro5\allegro_primitives.h"



void Bullet::init(Bullet bullet[], int size)
{
	for (int i = 0; i < size; i++)
	{
		bullet[i].ID = ENUMS::BULLET; 
		bullet[i].speed = 10;
		bullet[i].live = false;
		
	}
}
    
void Bullet::draw(Bullet bullet[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if(bullet[i].live)
			al_draw_filled_circle(bullet[i].x, bullet[i].y, 2, al_map_rgb(255, 255, 255));
	}
}

void Bullet::fire(Bullet bullet[], int size, Spaceship &ship)
{
	for (int i = 0; i < size; i++)
	{
		if(!bullet[i].live)
		{
			bullet[i].x = ship.x + 17;
			bullet[i].y = ship.y;
			bullet[i].live = true;
			break;
		}
	}
}

void Bullet::update(Bullet bullet[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if(bullet[i].live)
		{
			bullet[i].x += bullet[i].speed; 
			if(bullet[i].x > WIDTH)
				bullet[i].live = false;
		}
	}
}
