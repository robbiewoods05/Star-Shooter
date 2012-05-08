#include <allegro5.h>
#include <allegro_native_dialog.h>
#include <allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include "objects.h"
#include "Spaceship.h"
#include "Bullet.h"
#include "Comet.h"
#include "Collision.h"

bool keys[5] = { false, false, false, false, false };

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
	ship.init(ship);
	bullets[NUM_BULLETS].init(bullets, NUM_BULLETS);
	comets[NUM_COMETS].init(comets, NUM_COMETS);
	

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));

    al_start_timer(timer);

    while (!done) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		
	if (ev.type == ALLEGRO_EVENT_TIMER) {
	    redraw = true;
	    if (keys[ENUMS::UP])
		ship.moveUp(ship);
	    if (keys[ENUMS::DOWN])
		ship.moveDown(ship);
	    if (keys[ENUMS::LEFT])
		ship.moveLeft(ship);
	    if (keys[ENUMS::RIGHT])
		ship.moveRight(ship);

		bullets[NUM_BULLETS].update(bullets, NUM_BULLETS);
		comets[NUM_COMETS].start(comets, NUM_COMETS);
		comets[NUM_COMETS].update(comets, NUM_COMETS);
		collideBullet(bullets, NUM_BULLETS, comets, NUM_COMETS);
		collideComet(comets, NUM_COMETS, ship);

	} else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
	    done = true;
	} else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
	    switch (ev.keyboard.keycode) {
	    case ALLEGRO_KEY_ESCAPE:
		done = true;
		break;

	    case ALLEGRO_KEY_UP:
		keys[ENUMS::UP] = true;
		break;

	    case ALLEGRO_KEY_DOWN:
		keys[ENUMS::DOWN] = true;
		break;

	    case ALLEGRO_KEY_LEFT:
		keys[ENUMS::LEFT] = true;
		break;

	    case ALLEGRO_KEY_RIGHT:
		keys[ENUMS::RIGHT] = true;
		break;

	    case ALLEGRO_KEY_SPACE:
		keys[ENUMS::SPACE] = true;
		bullets[NUM_BULLETS].fire(bullets, NUM_BULLETS, ship); 
		break;
	    }
	} else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
	    switch (ev.keyboard.keycode) {
	    case ALLEGRO_KEY_ESCAPE:
		done = true;
		break;

	    case ALLEGRO_KEY_UP:
		keys[ENUMS::UP] = false;
		break;

	    case ALLEGRO_KEY_DOWN:
		keys[ENUMS::DOWN] = false;
		break;

	    case ALLEGRO_KEY_LEFT:
		keys[ENUMS::LEFT] = false;
		break;

	    case ALLEGRO_KEY_RIGHT:
		keys[ENUMS::RIGHT] = false;
		break;

	    case ALLEGRO_KEY_SPACE:
		keys[ENUMS::SPACE] = false;
		break;
	    }
	}

	if (redraw && al_is_event_queue_empty(event_queue)) {
	    redraw = false;

		ship.draw(ship);
		bullets[NUM_BULLETS].draw(bullets, NUM_BULLETS);
		comets[NUM_COMETS].draw(comets, NUM_COMETS);

	    al_flip_display();
	    al_clear_to_color(al_map_rgb(0, 0, 0));
	}
    }

    al_destroy_display(display);

    return 0;
}


