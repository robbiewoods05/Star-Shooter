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
					if (bullet[i].x > (comets[j].x) &&
						bullet[i].x < (comets[j].x + comets[j].boundX) &&
						bullet[i].y > (comets[j].y) &&
						bullet[i].y < (comets[j].y + 18))
					{
						bullet[i].live = false;
						comets[j].live = false;
					}
				}
			}
		}
	}
}