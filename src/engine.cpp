#include "engine.h"
#include "input.h"

Engine::Engine() {

}

void Engine::run() {

	sf::RenderWindow window(sf::VideoMode(EngineConst::WIDTH, EngineConst::HEIGHT), "SFML works!");
	sf::Clock clock;
	init();
	Input input;
	float time = clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;
	//	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		float nTime = clock.getElapsedTime().asSeconds();
		float frameTime = nTime - time;
		time = nTime;

		//sf::Time frameTime = clock.restart();
		sf::Event event;
		accumulator += frameTime;
		//std::cout << accumulator << " " << dt << std::endl;
		
		while( accumulator > dt) {
			update(dt);	
			accumulator -=dt;
			while (window.pollEvent(event))
			{

				input.update(event);
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}
		}

		window.clear();
		draw(window);


		window.display();
	}
}

void Engine::setScreen(Screen *screen) {	
	_screen = screen;
}

void Engine::init() {
	game = new Game();
	setScreen(game);
}

void Engine::draw(sf::RenderWindow &window) {
	_screen->draw(window);

}
void Engine::update(float dt) {
	_screen->update(dt);
}

Engine::~Engine() {
	delete game;
}
