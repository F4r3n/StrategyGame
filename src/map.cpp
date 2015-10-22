#include "map.h"

unsigned int Map::widthTile = 0;
unsigned int Map::heightTile = 0;


Map::Map() {}

Map::Map(unsigned int w, unsigned int h, unsigned int wt, unsigned int ht): widthMap(w), heightMap(h) {
    widthMapPixel = widthMap * widthTile;
    heightMapPixel = heightMap * heightTile;
    tiles = new std::vector<std::shared_ptr<Case> >();
    widthTile = wt;
    heightTile = ht;
    font = new sf::Font();
    font->loadFromFile("../assets/arial.ttf");
    for(int i=0;i<w;i++) {
        for(int j=0;j<h;j++) {

            std::shared_ptr<Case> rect (new Case(new BuildGround(Point(i*wt, j*ht), Point(wt, ht),font)));
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

Point Map::getPos(Point pos, Type t) {
    if( t == Type::FLOAT) {
        int x = floor(static_cast<float>(pos.x)/static_cast<float>(widthTile));
        int y = floor(static_cast<float>(pos.y)/static_cast<float>(heightTile));
        return Point(x,y);
    }

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
bool Map::isWalkable(const Box &box) {
    Point pos = getPos(Point(box.x, box.y));
    if(validPoint(box)) {
        return tiles->at(pos.y*widthMap + pos.x)->isWalkable();
    }
    return false;
}

bool Map::isWalkable(Point pos) {
    if(validPoint(pos)) {
        return tiles->at(pos.y*widthMap + pos.x)->isWalkable();
    }
    return false;
}

void Map::setWeight(Point pos,int w) {

    if(validPoint(pos)) {
        tiles->at(pos.y*widthMap + pos.x)->setWeight(w);
    }
}

int Map::getWeight(Point pos) {

    if(validPoint(pos)) {
        return tiles->at(pos.y*widthMap + pos.x)->getWeight();
    }
}
void Map::setUnitOn(Point pos, bool value) {

    if(validPoint(pos)) {
        tiles->at(pos.y*widthMap + pos.x)->setUnitOn(value);
    }
}

bool Map::isUnitOn(Point pos) {

    if(validPoint(pos)) {
        return tiles->at(pos.y*widthMap + pos.x)->isUnitOn();
    }
    return false;
}
void Map::setText(Point pos, const std::string &s) {

    if(validPoint(pos)) {
        tiles->at(pos.y*widthMap + pos.x)->setString(s);
    }
}

void Map::setVector(Point pos, Point vector) {
    if(validPoint(pos)) {
        tiles->at(pos.y*widthMap + pos.x)->setVector(vector);
    }
}
Point Map::getVector(Point pos) {

    if(validPoint(pos)) {
        return tiles->at(pos.y*widthMap + pos.x)->getVector();
    }
}
Map::Map(const std::string &path) {
    char c;
    font = new sf::Font();
    font->loadFromFile("../assets/arial.ttf");
    std::ifstream fin(path, std::ifstream::in);
    fin >> widthMap >> heightMap >> widthTile >> heightTile;
    widthMapPixel = widthMap * widthTile;
    heightMapPixel = heightMap * heightTile;
    tiles = new std::vector<std::shared_ptr<Case> >();
    unsigned int i = 0;
    unsigned int j = 0;
    while (fin >> c) {
        int p = c -'0';
        Case *ca;
        switch(p){
            case 1:
                ca = new Case(new BuildGround(Point(i*widthTile, j*heightTile), Point(widthTile, heightTile), font));
                break;
            case 2:
                ca = new Case(new ObstacleGround(Point(i*widthTile, j*heightTile), Point(widthTile, heightTile),font));
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

bool Map::validPoint(const Box &box) {
    if(box.x <= 0 || box.x + box.w >= widthMapPixel || box.y <= 0 || box.y + box.h >= heightMapPixel ) return false; 
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


void Map::update(float dt) {}

Map::~Map() {
    delete tiles;
    delete tilesTemp;
}

