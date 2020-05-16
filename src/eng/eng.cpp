#include "eng.hpp"



void Eng::init(){
	object.load("data/model/ship.yaml");
};

void Eng::cleanup(){
};

void Eng::events(){
	Geom::Pos move;
	SDL_Event event = getEvent();
	switch( event.type ){
		case SDL_KEYDOWN:
			switch( event.key.keysym.sym ){
				case SDLK_LEFT:
					move = Geom::Pos(-1.0,  0.0);
					break;
				case SDLK_RIGHT:
					move = Geom::Pos( 1.0,  0.0);
					break;
				case SDLK_UP:
					move = Geom::Pos( 0.0, -1.0);
					break;
				case SDLK_DOWN:
					move = Geom::Pos( 0.0,  1.0);
					break;
				default:
					break;
		}
	}
	object.move(move);
};

void Eng::draw(){
	setColor(Geom::Color(100, 100, 100));
	drawShape();
};

void Eng::drawShape(){
	for(const auto & line : object.getShape())
		drawLine(line.start, line.end);
};
