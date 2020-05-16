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
	Geom::Size windowSize;
	Geom::Size worldSize;
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
	void loadParams(std::string filename);
	void run();
	SDL_Event getEvent();
	void setColor(Geom::Color color);
	void drawLine(Geom::Pos a, Geom::Pos b);
	virtual void init() = 0;
	virtual void cleanup() = 0;
	virtual void events() = 0;
	virtual void draw() = 0;

};

#endif
