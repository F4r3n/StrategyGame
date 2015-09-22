#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "point.h"

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
		~Map();
	
	private:
		int widthMap, heightMap;
		int widthTile, heightTile;
		std::vector<sf::RectangleShape*> *tiles;	
		
};

#endif
