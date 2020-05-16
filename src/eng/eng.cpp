#include "eng.hpp"



void Eng::init(){
	object.load("data/model/ship.yaml");
};

void Eng::cleanup(){
};

void Eng::events(){
	Geom::Pos move;
	const Uint8* keyboard = getKeyboard();
	if(keyboard[SDL_SCANCODE_LEFT])
		move += Geom::Pos(-1.0,  0.0);
	if(keyboard[SDL_SCANCODE_RIGHT])
		move += Geom::Pos( 1.0,  0.0);
	if(keyboard[SDL_SCANCODE_UP])
		move += Geom::Pos( 0.0, -1.0);
	if(keyboard[SDL_SCANCODE_DOWN])
		move += Geom::Pos( 0.0,  1.0);
	object.displace(move);
};

void Eng::draw(){
	setColor(Geom::Color(100, 100, 100));
	drawShape();
};

void Eng::drawShape(){
	for(const auto & line : object.getShape())
		drawLine(line.start, line.end);
};
