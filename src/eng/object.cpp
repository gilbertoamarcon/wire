#include "object.hpp"


void Object::load(std::string filename){
	shape.load(filename);
};

void Object::displace(const Geom::Pos & displacement){
	this->pos += displacement;
}

std::list<Geom::Line> Object::getShape(){
	std::list<Geom::Line> path = shape.getShape();
	for(auto & line : path){
		line.start += pos;
		line.end += pos;
	}
	return path;
}

