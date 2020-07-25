#include "fx.hpp"


Fx::Fx() {
	quit = false;
	fullscreen = false;
	inputGrabbed = false;
	windowTitle = "";
	windowSize = Geom::Pos(1.0, 1.0);
	worldSize = Geom::Pos(1.0, 1.0);
	canvasColor = Geom::Color(0.0, 0.0, 0.0);
	frameTime = 1.0;
};

void Fx::loadParams(const std::string & filename){
	loadParamsFile(filename);
	if(params["fullscreen"])
		fullscreen = params["fullscreen"].as<bool>();
	if(params["inputGrabbed"])
		inputGrabbed = params["inputGrabbed"].as<bool>();
	if(params["windowTitle"])
		windowTitle = params["windowTitle"].as<std::string>();
	if(params["window"] && params["window"]["w"] && params["window"]["h"])
		windowSize = Geom::Pos(params["window"]["w"].as<float>(), params["window"]["h"].as<float>());
	if(params["world"] && params["world"]["w"] && params["world"]["h"])
		worldSize = Geom::Pos(params["world"]["w"].as<float>(), params["world"]["h"].as<float>());
	if(params["canvasColor"] && params["canvasColor"]["r"] && params["canvasColor"]["g"] && params["canvasColor"]["b"])
		canvasColor = Geom::Color(params["canvasColor"]["r"].as<float>(), params["canvasColor"]["g"].as<float>(), params["canvasColor"]["b"].as<float>());
};

void Fx::run(){
	initWindow();
	initTimer();
	init();
	loop();
	cleanupWindow();
	cleanup();
};


void Fx::loadParamsFile(std::string filename){
	try{
		params = YAML::LoadFile(filename);
	}
	catch(std::exception &e){
		std::cout << "Error loading the params file " << filename << std::endl;
		quit = true;
		exit(0);
	}
};

void Fx::initWindow(){
	SDL_Init(SDL_INIT_VIDEO);
	Uint32 flags = getFlags();
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); 
	window = SDL_CreateWindow(windowTitle.c_str(), 0, 0, windowSize.x, windowSize.y, flags);
	glContext = SDL_GL_CreateContext(window);
	SDL_GL_SetSwapInterval(1);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	updateWindowSize();
	SDL_RenderSetScale(renderer, 1.0, 1.0);
	scale = windowSize/worldSize;
};

void Fx::initTimer(){
	SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);
	if(SDL_Init(SDL_INIT_TIMER) < 0){
		std::cout << "Error initializing timer" << std::endl;
		quit = true;
		exit(0);
	}

};

void Fx::loop(){
	Uint64 start, now;
	while (!quit){
		start = SDL_GetPerformanceCounter();
		allEvents();
		canvas();
		draw();
		SDL_RenderPresent(renderer);
		SDL_GL_SwapWindow(window);
		now = SDL_GetPerformanceCounter();
		frameTime = (float)(now-start) / SDL_GetPerformanceFrequency();
	}
};

void Fx::cleanupWindow(){
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
};


Uint32 Fx::getFlags(){
	Uint32 flags = 0;
	if(fullscreen)
		flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
	if(inputGrabbed)
		flags |= SDL_WINDOW_INPUT_GRABBED;
	return flags;
};

void Fx::updateWindowSize(){
	int x;
	int y;
	SDL_GetWindowSize(window, &x, &y);
	windowSize = Geom::Pos(x,y);
};

void Fx::allEvents(){
	SDL_PumpEvents();
	keyboard = SDL_GetKeyboardState(NULL);
	if(keyboard[SDL_SCANCODE_ESCAPE]){
		quit = true;
		return;
	}
	events();
};

void Fx::canvas(){
	setColor(canvasColor);
	SDL_RenderClear(renderer);
};

const Uint8* Fx::getKeyboard() const {
	return keyboard;
};

const float Fx::getFrameTime() const {
	return frameTime;
};

void Fx::setColor(const Geom::Color & color) const{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
};

void Fx::drawLine(const Geom::Pos & a, const Geom::Pos & b) const{
	Geom::Pos aScaled = a*scale;
	Geom::Pos bScaled = b*scale;
	SDL_RenderDrawLine(renderer, aScaled.x, aScaled.y, bScaled.x, bScaled.y);
};

