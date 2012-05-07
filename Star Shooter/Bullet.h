#pragma once
#include "Spaceship.h"


class Bullet
{
public:
	int ID, x, y, speed;
	bool live;

	void init(Bullet bullet[], int size);
    void draw(Bullet bullet[], int size);
	void fire(Bullet bullet[], int size, Spaceship &ship);
	void update(Bullet bullet[], int size);
};

