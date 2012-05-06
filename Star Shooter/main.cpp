#include <allegro5.h>
#include <allegro_native_dialog.h>
#include <allegro_primitives.h>
#include "objects.h"
#include "Spaceship.h"
#include "Bullet.h"
#include "Comet.h"

using namespace ENUMS;

// *** GLOBALS ***
bool keys[5] = { false, false, false, false, false };


// *** PROTOTYPES ***

void collideBullet(Bullet bullet[], int bSize, Comet comets[], int cSize);


int main(void)
{
	// Primitive Variables
    bool done = false, redraw = true;

	// Object Variables
    Spaceship ship;
	Bullet bullets[NUM_BULLETS];
	Comet comets[NUM_COMETS];

	// Allegro Variables
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;

	// Init Allegro
    if (!al_init()) {
		al_show_native_message_box(NULL, "Error", "Error", "Failed to initialise allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
    }

    display = al_create_display(WIDTH, HEIGHT);

    if (!display) {
		al_show_native_message_box(NULL, "Error", "Error", "Failed to create display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
    }

    al_install_keyboard();
    al_init_primitives_addon();

    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);

	srand(time(NULL));
	ship.initShip(ship);
	bullets[NUM_BULLETS].initBullet(bullets, NUM_BULLETS);
	comets[NUM_COMETS].initComet(comets, NUM_COMETS);
	collideBullet(bullets, NUM_BULLETS, comets, NUM_COMETS);

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));

    al_start_timer(timer);
    while (!done) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

	if (ev.type == ALLEGRO_EVENT_TIMER) {
	    redraw = true;
	    if (keys[UP])
		ship.moveShipUp(ship);
	    if (keys[DOWN])
		ship.moveShipDown(ship);
	    if (keys[LEFT])
		ship.moveShipLeft(ship);
	    if (keys[RIGHT])
		ship.moveShipRight(ship);

		bullets[NUM_BULLETS].updateBullet(bullets, NUM_BULLETS);
		comets[NUM_COMETS].startComet(comets, NUM_COMETS);
		comets[NUM_COMETS].updateComet(comets, NUM_COMETS);

	} else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
	    done = true;
	} else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
	    switch (ev.keyboard.keycode) {
	    case ALLEGRO_KEY_ESCAPE:
		done = true;
		break;

	    case ALLEGRO_KEY_UP:
		keys[UP] = true;
		break;

	    case ALLEGRO_KEY_DOWN:
		keys[DOWN] = true;
		break;

	    case ALLEGRO_KEY_LEFT:
		keys[LEFT] = true;
		break;

	    case ALLEGRO_KEY_RIGHT:
		keys[RIGHT] = true;
		break;

	    case ALLEGRO_KEY_SPACE:
		keys[SPACE] = true;
		bullets[NUM_BULLETS].fireBullet(bullets, NUM_BULLETS, ship); 
		break;
	    }
	} else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
	    switch (ev.keyboard.keycode) {
	    case ALLEGRO_KEY_ESCAPE:
		done = true;
		break;

	    case ALLEGRO_KEY_UP:
		keys[UP] = false;
		break;

	    case ALLEGRO_KEY_DOWN:
		keys[DOWN] = false;
		break;

	    case ALLEGRO_KEY_LEFT:
		keys[LEFT] = false;
		break;

	    case ALLEGRO_KEY_RIGHT:
		keys[RIGHT] = false;
		break;

	    case ALLEGRO_KEY_SPACE:
		keys[SPACE] = false;
		break;
	    }
	}

	if (redraw && al_is_event_queue_empty(event_queue)) {
	    redraw = false;

		ship.drawShip(ship);
		bullets[NUM_BULLETS].drawBullet(bullets, NUM_BULLETS);
		comets[NUM_COMETS].drawComet(comets, NUM_COMETS);

	    al_flip_display();
	    al_clear_to_color(al_map_rgb(0, 0, 0));
	}
    }

    al_destroy_display(display);

    return 0;
}


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