#pragma once
class Spaceship {
  public:

	
	int ID, x, y, lives, speed, boundX, boundY, score;

	void initShip(Spaceship &ship);
	void drawShip(Spaceship &ship);
	void moveShipUp(Spaceship &ship);
	void moveShipDown(Spaceship &ship);
	void moveShipLeft(Spaceship &ship);
	void moveShipRight(Spaceship &ship);
};

