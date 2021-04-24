#include "eng.hpp"



void Eng::init(){
	object.load("data/model/ship.yaml");
};

void Eng::cleanup(){
};

void Eng::events(){
	Geom::Pos move;
	float speed = 50.0;
	float frameTime = getFrameTime();
	float displacement = speed*frameTime;
	const Uint8* keyboard = getKeyboard();
	if(keyboard[SDL_SCANCODE_SPACE]){
		Object missile;
		missile.load("data/model/missile.yaml");
		missile.pos = object.pos;
		missiles.push_back(missile);
	}
	if(keyboard[SDL_SCANCODE_LEFT])
		move += Geom::Pos(-displacement,  0.0);
	if(keyboard[SDL_SCANCODE_RIGHT])
		move += Geom::Pos( displacement,  0.0);
	if(keyboard[SDL_SCANCODE_UP])
		move += Geom::Pos( 0.0, -displacement);
	if(keyboard[SDL_SCANCODE_DOWN])
		move += Geom::Pos( 0.0,  displacement);
	object.displace(move);
	if(object.pos.x > worldSize.x)
		object.pos.x = worldSize.x;
	if(object.pos.x < 0.0)
		object.pos.x = 0.0;
	if(object.pos.y > worldSize.y)
		object.pos.y = worldSize.y;
	if(object.pos.y < 0.0)
		object.pos.y = 0.0;
	for(auto & missile : missiles)
		missile.pos.x++;
};

void Eng::draw(){
	setColor(Geom::Color(100, 100, 100));
	drawShape();
};

void Eng::drawShape(){
	for(const auto & line : object.getShape())
		drawLine(line.start, line.end);
	for(const auto & missile : missiles)
		for(const auto & line : missile.getShape())
			drawLine(line.start, line.end);
};
