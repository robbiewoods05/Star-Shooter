#pragma once
#include "Spaceship.h"


class Bullet
{
public:
	int ID, x, y, speed;
	bool live;

	void initBullet(Bullet bullet[], int size);
    void drawBullet(Bullet bullet[], int size);
	void fireBullet(Bullet bullet[], int size, Spaceship &ship);
	void updateBullet(Bullet bullet[], int size);
};

