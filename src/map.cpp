#include "map.h"


Map::Map() {}

Map::Map(int w, int h, int wt, int ht): widthMap(w), heightMap(h), widthTile(wt), heightTile(ht) {
	tiles = new std::vector<sf::RectangleShape*>();
	int size = w*h;
	for(int i=0;i<w;i++) {
		for(int j=0;j<h;j++) {

		sf::RectangleShape *rect = new sf::RectangleShape(sf::Vector2f(wt,ht));
		rect->setPosition(i*wt, j*ht);
		rect->setFillColor(sf::Color(100,200,50));
		tiles->push_back(rect);
		}
	}

}

Point Map::getPos(Point pos) {
	return Point(pos.x/widthTile, pos.y/heightTile);
}

Point Map::getSizeMap() {
	return Point(widthMap, heightMap);
}

Point Map::getSizeTile() {
	return Point(widthTile, heightTile);
}

Map::Map(const std::string &path) {

	tiles = new std::vector<sf::RectangleShape*>();

}

void Map::draw(sf::RenderWindow &window) {
	for(auto tile : *tiles) {
		window.draw(*tile);
	}
}

void Map::update(float dt) {
}

Map::~Map() {
	tiles->clear();
	tiles->pop_back();
	delete tiles;
}

