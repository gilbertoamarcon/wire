#include "object.hpp"


void Object::load(std::string filename){
	shape.load(filename);
};

void Object::move(const Geom::Pos & pos){
	this->pos += pos;
}

std::list<Geom::Line> Object::getShape(){
	std::list<Geom::Line> path = shape.getShape();
	for(auto & line : path){
		line.start += pos;
		line.end += pos;
	}
	return path;
}

