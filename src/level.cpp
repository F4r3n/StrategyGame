#include "level.h"
#include "engineConst.h"

Level::Level() {
	//map = new Map(100,100,10,10);
	map = new Map("./assets/map");
	interface = new Interface();
	player = new Player();

	centerX = 0;
	centerY = 0;

	view.reset(sf::FloatRect(centerX, centerY, EngineConst::WIDTH, EngineConst::HEIGHT));
}

Level::~Level(){
	delete map;
	delete interface;
	delete player;
}

void Level::draw(sf::RenderWindow &window){

	window.setView(view);
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	posMouseWindow.x = pixelPos.x;
	posMouseWindow.y = pixelPos.y;
	// conversion en coordonnées "monde"
	sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
	pos.x = worldPos.x;
	pos.y = worldPos.y;
	map->draw(window);
	player->draw(window);
	window.setView(window.getDefaultView());
	interface->draw(window);

}

void Level::update(float dt) {
	map->update(dt);
	player->update(dt,map, interface, pos, posMouseWindow);
	interface->update(dt, view);
}
