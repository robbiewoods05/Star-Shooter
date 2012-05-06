#pragma once
class Comet
{
public:
	int ID, x, y, speed, boundX, boundY;
	bool live;

	void initComet(Comet comets[], int size);
	void drawComet(Comet comets[], int size); 
	void startComet(Comet comets[], int size); 
	void updateComet(Comet comets[], int size);
};

