#pragma once
class Spaceship {
  public:

	
	int ID, x, y, lives, speed, boundX, boundY, score;

	void init(Spaceship &ship);
	void draw(Spaceship &ship);
	void moveUp(Spaceship &ship);
	void moveDown(Spaceship &ship);
	void moveLeft(Spaceship &ship);
	void moveRight(Spaceship &ship);
};

