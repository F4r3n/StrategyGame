#ifndef ENGINE_H
#define ENGINE_H

#include "screen.h"
#include "game.h"
#include "engineConst.h"
#include <SFML/Graphics.hpp>

class Engine {

	public:
		void run();
		void setScreen(Screen *screen);
		void draw(sf::RenderWindow &window);
		void update(float dt);
		void init();

		~Engine();
		Engine();

	private:
		bool running = false;
		float dt = 1.0f/60.0f;
		Screen *_screen;
		Game *game;
};

#endif
