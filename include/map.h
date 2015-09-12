#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Map {
	public:
		Map();
		Map(const std::string &path);
		Map(int w, int h, int wt, int ht);
		void draw(sf::RenderWindow &window);
		void update(float dt);
		~Map();
	
	private:
		int widthMap, heightMap;
		int widthTile, heightTile;
		std::vector<sf::RectangleShape*> *tiles;	
		
};

#endif
