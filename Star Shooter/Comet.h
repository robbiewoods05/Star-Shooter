#pragma once
class Comet
{
public:
	int ID, x, y, speed, boundX, boundY;
	bool live;

	void init(Comet comets[], int size);
	void draw(Comet comets[], int size); 
	void start(Comet comets[], int size); 
	void update(Comet comets[], int size);
};

//Comet