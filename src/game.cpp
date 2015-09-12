#include <iostream>
#include "game.h"

Game::Game() {
	level = new Level();
}

Game::~Game() {
	delete level;
}

void Game::changeLevel() {

}

void Game::update(float dt) {
	level->update(dt);
}

void Game::draw(sf::RenderWindow &window){
	level->draw(window);
}

