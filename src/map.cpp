#include "map.h"

int Map::widthTile = 0;
int Map::heightTile = 0;


Map::Map() {}

Map::Map(int w, int h, int wt, int ht): widthMap(w), heightMap(h) {
	tiles = new std::vector<std::shared_ptr<Case> >();
	widthTile = wt;
	heightTile = ht;
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
		rect->setFillColor(sf::Color(0,0,0,0));
		tilesTemp->push_back(rect);
		}
	}
}

Point Map::getPos(Point pos) {
		return Point(pos.x/widthTile, pos.y/heightTile);
}


Point Map::getCenterCase(Point square) {
	return Point(square.x*widthTile + widthTile/2, square.y*heightTile + heightTile/2);
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

bool Map::isWalkable(Point pos) {
	if(validPoint(pos)) {
		return tiles->at(pos.y*widthMap + pos.x)->isWalkable();
	}
	return false;
}

Map::Map(const std::string &path) {
	char c;
	std::ifstream fin(path, std::ifstream::in);
	fin >> widthMap >> heightMap >> widthTile >> heightTile;
	tiles = new std::vector<std::shared_ptr<Case> >();
	int i = 0;
	int j = 0;
	while (fin >> c) {
		int p = c -'0';
		Case *ca;
		switch(p){
			case 1:
			ca = new Case(new BuildGround(Point(i*widthTile, j*heightTile), Point(widthTile, heightTile)));
			break;
			case 2:
			ca = new Case(new ObstacleGround(Point(i*widthTile, j*heightTile), Point(widthTile, heightTile)));
			break;
		}

		std::shared_ptr<Case> rect (ca);
		i++;
		if(i%widthMap == 0) {
			j++;
			i = 0;
		}
		tiles->push_back(rect);
	}
	fin.close();

	tilesTemp = new std::vector<std::shared_ptr<sf::RectangleShape> >();
	for(i=0;i<heightMap;i++) {
		for(j=0;j<widthMap;j++) {

		std::shared_ptr<sf::RectangleShape> rect (new sf::RectangleShape(sf::Vector2f(widthTile,heightTile)));
		rect->setPosition(j*widthTile, i*heightTile);
		rect->setFillColor(sf::Color(0,0,0,0));
		tilesTemp->push_back(rect);
		}
	}
}

void Map::setColorTile(Point pos, sf::Color color) {
	std::shared_ptr<sf::RectangleShape> rect = tilesTemp->at(pos.y*widthMap + pos.x);
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

