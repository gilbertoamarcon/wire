#ifndef __FX_HPP__
#define __FX_HPP__

#include <SDL.h>
#include <iostream>
#include <yaml-cpp/yaml.h>

struct Pos {
	float x;
	float y;
	Pos(): x(0.0), y(0.0) {};
	Pos(float x, float y): x(x), y(y) {};
};

struct Size {
	float w;
	float h;
	Size(): w(0.0), h(0.0) {};
	Size(float w, float h): w(w), h(h) {};
};

struct Color {
	float r;
	float g;
	float b;
	Color(): r(0.0), g(0.0), b(0.0) {};
	Color(float r, float g, float b): r(r), g(g), b(b) {};
};

class Fx {

private:
	bool quit;
	bool fullscreen;
	bool inputGrabbed;
	Size windowSize;
	Size worldSize;
	Color canvasColor;
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
	void setColor(Color color);
	void drawLine(Pos a, Pos b);
	virtual void init() = 0;
	virtual void cleanup() = 0;
	virtual void events() = 0;
	virtual void draw() = 0;

};

#endif
