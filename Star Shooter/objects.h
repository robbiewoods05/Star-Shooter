namespace ENUMS
{
	enum IDS { PLAYER, BULLET, ENEMY };
	enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE };
}
const int WIDTH = 800, HEIGHT = 400, FPS = 60, NUM_BULLETS = 5, NUM_COMETS = 10;

bool keys[5] = { false, false, false, false, false };