#include "eng.hpp"



void Eng::init(){
	shape.load("data/model/ship.yaml");
};

void Eng::cleanup(){
};

void Eng::events(){
	SDL_Event event = getEvent();
	// switch(event.type){
	// 	case SDL_QUIT:
	// 		quit = true;
	// 		break;
	// 	// TODO input handling code goes here
	// }
};

void Eng::draw(){
	setColor(Geom::Color(100, 100, 100));
	drawShape();
};

void Eng::drawShape(){
	for(const auto & line : shape.getShape())
		drawLine(line.start, line.end);
};
