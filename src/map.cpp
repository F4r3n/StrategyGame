#include "map.h"


Map::Map() {}

Map::Map(int w, int h, int wt, int ht): widthMap(w), heightMap(h), widthTile(wt), heightTile(ht) {
	tiles = new std::vector<std::shared_ptr<Case> >();
	int size = w*h;
	for(int i=0;i<w;i++) {
		for(int j=0;j<h;j++) {

		std::shared_ptr<Case> rect (new Case(new BuildGround(Point(i*wt, j*ht), Point(wt, ht))));
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
	int p;
	std::ifstream fin(path, std::ifstream::in);
	fin >> widthMap >> heightMap >> widthTile >> heightTile;
	
	tiles = new std::vector<std::shared_ptr<Case> >();
	int i = 0;
	int j = 0;
	while (fin >> p) {
		std::shared_ptr<Case> rect (new Case(new BuildGround(Point(i*widthTile, j*heightTile), Point(widthTile, heightTile))));
		i++;
		if(i%widthMap == 0) j++;
		tiles->push_back(rect);
		std::cout << p;
	}
	fin.close();

}

void Map::setColorTile(Point pos, sf::Color color) {
	std::shared_ptr<sf::RectangleShape> rect = tilesTemp->at(pos.x*widthMap + pos.y);
	rect->setFillColor(color);
}

bool Map::validPoint(Point &pos) {
	if(pos.x < 0 || pos.x >= widthMap || pos.y < 0 || pos.y >= heightMap) return false;
	return true;
}

void Map::draw(sf::RenderWindow &window) {
	for(auto tile : *tiles) {
		tile->draw(window);
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

