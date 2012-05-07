#include "Comet.h"
#include "objects.h"
#include "allegro5\allegro5.h"
#include "allegro5\allegro_primitives.h"

using namespace ENUMS;

void Comet::init(Comet comets[], int size)
{
	for (int i = 0; i < size; i++)
	{
		comets[i].ID = ENEMY;
		comets[i].live = false;
		comets[i].speed = 5; 
		comets[i].boundX = 18; 
		comets[i].boundY = 18;
	}
}
void Comet::draw(Comet comets[], int size) 
{
	for (int i = 0; i < size; i++)
	{
		if (comets[i].live)
		{
			al_draw_filled_circle(comets[i].x, comets[i].y, 20, al_map_rgb(255, 0, 0));
		}
	}
}
void Comet::start(Comet comets[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!comets[i].live)
		{
			if (rand() % 500 == 0)
			{
				comets[i].live = true;
				comets[i].x = WIDTH; 
				comets[i].y = 30 + rand() % (HEIGHT - 60);
				break;
			}
		}
	}
}
void Comet::update(Comet comets[], int size)
{
	for (int i = 0; i < size; i++) 
	{
		comets[i].x -= comets[i].speed;
		if(comets[i].x < 0)
			comets[i].live = false;
	}
}