#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <memory>
#include "case.h"
#include "buildGround.h"
#include "obstacleGround.h"

class Map {
	public:
		Map();
		Map(const std::string &path);
		Map(int w, int h, int wt, int ht);
		void draw(sf::RenderWindow &window);
		void update(float dt);
		Point getSizeMap();
		Point getSizeTile();
		Point getPos(Point pos);
		bool validPoint(Point &pos);
		void setColorTile(Point pos, sf::Color color);
		Point getCenter(Point pos);
		bool isWalkable(Point pos);
		void reset();
		~Map();
	
	private:
		int widthMap, heightMap;
		int widthTile, heightTile;
		std::vector<std::shared_ptr<Case> > *tiles;	
		std::vector<std::shared_ptr<sf::RectangleShape> > *tilesTemp;	
		
};

#endif
