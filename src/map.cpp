#include "map.h"


Map::Map() {}

Map::Map(int w, int h, int wt, int ht): widthMap(w), heightMap(h), widthTile(wt), heightTile(ht) {
	tiles = new std::vector<std::shared_ptr<sf::RectangleShape> >();
	int size = w*h;
	for(int i=0;i<w;i++) {
		for(int j=0;j<h;j++) {

		std::shared_ptr<sf::RectangleShape> rect (new sf::RectangleShape(sf::Vector2f(wt,ht)));
		rect->setPosition(i*wt, j*ht);
		rect->setFillColor(sf::Color(100,200,50));
		tiles->push_back(rect);
		}
	}

	tilesTemp = new std::vector<std::shared_ptr<sf::RectangleShape> >();
	for(int i=0;i<w;i++) {
		for(int j=0;j<h;j++) {

		std::shared_ptr<sf::RectangleShape> rect (new sf::RectangleShape(sf::Vector2f(wt,ht)));
		rect->setPosition(i*wt, j*ht);
		rect->setFillColor(sf::Color(100,200,50));
		tilesTemp->push_back(rect);
		}
	}
}

Point Map::getPos(Point pos) {
	return Point(pos.x/widthTile, pos.y/heightTile);
}

Point Map::getSizeMap() {
	return Point(widthMap, heightMap);
}

void Map::reset() {
	for(auto tile : *tilesTemp)
		tile->setFillColor(sf::Color(0,0,0,0));
}

Point Map::getSizeTile() {
	return Point(widthTile, heightTile);
}

Map::Map(const std::string &path) {


}

void Map::setColorTile(Point pos) {
	std::shared_ptr<sf::RectangleShape> rect = tilesTemp->at(pos.x*widthMap + pos.y);
	rect->setFillColor(sf::Color::Red);
}

bool Map::validPoint(Point &pos) {
	if(pos.x < 0 || pos.x >= widthMap || pos.y < 0 || pos.y >= heightMap) return false;
	return true;
}

void Map::draw(sf::RenderWindow &window) {
	for(auto tile : *tiles) {
		window.draw(*tile);
	}
	for(auto tile : *tilesTemp) {
		window.draw(*tile);
	}
}

void Map::update(float dt) {
}

Map::~Map() {
	delete tiles;
	delete tilesTemp;
}

