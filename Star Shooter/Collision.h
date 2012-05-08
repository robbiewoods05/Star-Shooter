#include "Bullet.h"
#include "Comet.h"

void collideBullet(Bullet bullet[], int bSize, Comet comets[], int cSize)
{
	for (int i = 0; i < bSize; i++)
	{
		if (bullet[i].live)
		{
			for (int j = 0; j < cSize; j++)
			{
				if (comets[j].live)
				{
					if (bullet[i].x > (comets[j].x - comets[j].boundX) &&
						bullet[i].x < (comets[j].x + comets[j].boundX) &&
						bullet[i].y > (comets[j].y - comets[j].boundY) &&
						bullet[i].y < (comets[j].y + comets[j].boundY))
					{
						bullet[i].live = false;
						comets[j].live = false;
					}
				}
			}
		}
	}
}

void collideComet(Comet comets[], int cSize, Spaceship &ship)
{
	for (int i = 0; i < cSize; i++)
	{
		if (comets[i].live)
		{
			if (comets[i].x - comets[i].boundX < ship.x + ship.boundX &&
				comets[i].x + comets[i].boundX > ship.x - ship.boundX &&
				comets[i].y - comets[i].boundY < ship.y + ship.boundY &&
				comets[i].y + comets[i].boundY > ship.y - ship.boundY)
			{
				ship.lives--;
				comets[i].live = false;
			}
			else if(comets[i].x < 0)
			{
				comets[i].live = false;
				ship.lives--;
			}
		}
	}
}