#include "uiborder.h"

UIBorder::UIBorder(){
	sf::Color black(0,0,0,150);

	sf::Color black2(50,50,50,150);
	

	borders.push_back(new GUI(new Box(0,EngineConst::WIDTH, 0,offset),
							black, black2));
	borders.push_back(new GUI(new Box(EngineConst::WIDTH-offset,offset, 0,EngineConst::HEIGHT),
							black, black2));
	borders.push_back(new GUI(new Box(0,EngineConst::WIDTH, EngineConst::HEIGHT-offset, offset),
							black, black2));
	borders.push_back(new GUI(new Box(0,offset,0,EngineConst::HEIGHT),
							black, black2));
}

void UIBorder::draw(sf::RenderWindow &window) {
	mousePos = sf::Mouse::getPosition(window);
	
	for(int i=0; i < numberBorder; i++) {
		borders[i]->draw(window);		
	}
}

void UIBorder::update(float dt) {
	for(int i=0;i < numberBorder; i++)
		if(borders[0]->cursorIn(mousePos.x, mousePos.y))
			std::cout << "touch" << std::endl;
}


void UIBorder::update(float dt, sf::View &view) {
	centerView = view.getCenter();
	
	if(borders[0]->cursorIn(mousePos.x, mousePos.y)) {
		if(-EngineConst::HEIGHT/2+ centerView.y >0)
			view.move(0,-speed*dt);
	}


	if(borders[1]->cursorIn(mousePos.x, mousePos.y)) {

		view.move(speed*dt,0);
	}


	if(borders[2]->cursorIn(mousePos.x, mousePos.y)) {
		view.move(0,speed*dt);
	}


	if(borders[3]->cursorIn(mousePos.x, mousePos.y)) {

		if(-EngineConst::WIDTH/2 + centerView.x >0)
		view.move(-speed*dt,0);
	}
}

UIBorder::~UIBorder() {
	for(auto *border : borders)
		delete border;
	
}
