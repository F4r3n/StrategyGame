#include "uiborder.h"

UIBorder::UIBorder(){
	borders = new GUI[numberBorder];
	sf::Color black(0,0,0,150);
	Box b0(0,EngineConst::WIDTH, 0,offset);
	GUI g0(b0,black);
	
	Box b1(EngineConst::WIDTH-offset,offset, 0,EngineConst::HEIGHT);
	
	GUI g1(b1,black);
	Box b2(0,EngineConst::WIDTH, EngineConst::HEIGHT-offset, offset);
	GUI g2(b2,black);
	Box b3(0,offset,0,EngineConst::HEIGHT);
	GUI g3(b3,black);

	borders[0] = g0;
	borders[1] = g1;
	borders[2] = g2;
	borders[3] = g3;
}

void UIBorder::draw(sf::RenderWindow &window) {
	for(int i=0; i < numberBorder; i++) {
		borders[i].draw(window);		
	}
}

void UIBorder::update(float dt) {

}

UIBorder::~UIBorder() {

}
