#ifndef __ENG_HPP__
#define __ENG_HPP__

#include "geom.hpp"
#include "fx.hpp"
#include "shape.hpp"

class Eng : public Fx {

private:
	Shape shape;
	void drawShape();

public:
	void init();
	void cleanup();
	void events();
	void draw();

};

#endif
