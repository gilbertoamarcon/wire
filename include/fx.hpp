#ifndef __FX_HPP__
#define __FX_HPP__

#include "geom.hpp"
#include <SDL.h>
#include <iostream>
#include <yaml-cpp/yaml.h>

class Fx {

private:
	bool quit;
	bool fullscreen;
	bool inputGrabbed;
	Geom::Pos windowSize;
	Geom::Pos worldSize;
	Geom::Pos scale;
	Geom::Color canvasColor;
	int frameTime;
	std::string windowTitle;
	SDL_Event event;
	SDL_Window * window;
	SDL_Renderer * renderer;
	YAML::Node params;
	void updateWindowSize();
	void loadParamsFile(std::string filename);
	Uint32 getFlags();
	void initWindow();
	void cleanupWindow();
	void loop();
	void allEvents();
	void canvas();

public:
	Fx();
	void loadParams(const std::string & filename);
	void run();
	const SDL_Event & getEvent() const;
	void setColor(const Geom::Color & color) const;
	void drawLine(const Geom::Pos & a, const Geom::Pos & b) const;
	virtual void init() = 0;
	virtual void cleanup() = 0;
	virtual void events() = 0;
	virtual void draw() = 0;

};

#endif
