#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include "geom.hpp"
#include "shape.hpp"

class Object {

private:
	Shape shape;
	Geom::Pos pos;

public:
	Object() {};
	void load(std::string filename);
	void move(const Geom::Pos & pos);
	std::list<Geom::Line> getShape();

};

#endif
