#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include <SFML/Graphics.hpp>
#include <memory>
#include "case.h"
#include "buildGround.h"
#include "obstacleGround.h"

enum Type {INTEGER, FLOAT};

class Map {
	public:
		Map();
		Map(const std::string &path);
		Map(unsigned int w, unsigned int h, unsigned int wt, unsigned int ht);
		void draw(sf::RenderWindow &window);
		void update(float dt);
		Point getSizeMap();
		Point getSizeTile();
		static Point getPos(Point pos, Type t = INTEGER);
		bool validPoint(Point &pos);
		bool validPoint(const Box &box);
		void setColorTile(Point pos, sf::Color color);
        void setVector(Point pos, Point vector);
        Point getVector(Point pos);
		static Point getCenterCase(Point pos);
		bool isWalkable(Point pos);
		bool isWalkable(const Box &box);
		void setUnitOn(Point pos, bool value);
		bool isUnitOn(Point pos);
		void reset();
        void setText(Point pos, const std::string &s);
        void setWeight(Point pos, int w);
        int getWeight(Point pos);
		~Map();
	
	private:
		unsigned int widthMap, heightMap;
		unsigned int widthMapPixel, heightMapPixel;
		static unsigned int widthTile;
		static unsigned int heightTile;
		std::vector<std::shared_ptr<Case> > *tiles;	
		std::vector<std::shared_ptr<sf::RectangleShape> > *tilesTemp;
        sf::Font *font;
		
};

#endif
