#include "engine.h"


Engine::Engine() {
	
}

void Engine::run() {

	sf::RenderWindow window(sf::VideoMode(EngineConst::WIDTH, EngineConst::HEIGHT), "SFML works!");
	sf::Clock clock;
	init();

	while (window.isOpen())
	{

		sf::Time frameTime = clock.restart();
		sf::Event event;

		float dt = frameTime.asSeconds()/10.f;
		update(dt);	
		while (window.pollEvent(event))
		{

			//	std::cout << "dt " << dt <<std::endl; 

			if (event.type == sf::Event::Closed) {
				window.close();
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
	setScreen(new Game());
}

void Engine::draw(sf::RenderWindow &window) {
	_screen->draw(window);

}
void Engine::update(float dt) {
	_screen->update(dt);
}

Engine::~Engine() {
	delete _screen;
}
