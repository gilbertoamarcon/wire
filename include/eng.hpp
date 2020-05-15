#ifndef __ENG_HPP__
#define __ENG_HPP__

#include "fx.hpp"

class Eng : public Fx {

public:
	void init();
	void cleanup();
	void events();
	void draw();

};

#endif
