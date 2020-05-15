#include "eng.hpp"



void Eng::init(){
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
	setColor(Color(100, 100, 100));
	drawLine(Pos(80, 45), Pos(159, 89));
};
