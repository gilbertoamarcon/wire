#include "fx.hpp"


Fx::Fx() {
	quit = false;
	fullscreen = false;
	inputGrabbed = false;
	windowTitle = "";
	windowSize = Size(1.0, 1.0);
	worldSize = Size(1.0, 1.0);
	canvasColor = Color(0.0, 0.0, 0.0);
	frameTime = 10;
};

void Fx::loadParams(std::string filename){
	loadParamsFile(filename);
	if(params["fullscreen"])
		fullscreen = params["fullscreen"].as<bool>();
	if(params["inputGrabbed"])
		inputGrabbed = params["inputGrabbed"].as<bool>();
	if(params["windowTitle"])
		windowTitle = params["windowTitle"].as<std::string>();
	if(params["window"] && params["window"]["w"] && params["window"]["h"])
		windowSize = Size(params["window"]["w"].as<float>(), params["window"]["h"].as<float>());
	if(params["world"] && params["world"]["w"] && params["world"]["h"])
		worldSize = Size(params["world"]["w"].as<float>(), params["world"]["h"].as<float>());
	if(params["canvasColor"] && params["canvasColor"]["r"] && params["canvasColor"]["g"] && params["canvasColor"]["b"])
		canvasColor = Color(params["canvasColor"]["r"].as<float>(), params["canvasColor"]["g"].as<float>(), params["canvasColor"]["b"].as<float>());
	if(params["frameTime"])
		frameTime = params["frameTime"].as<int>();
};

void Fx::run(){
	initWindow();
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
	window = SDL_CreateWindow(windowTitle.c_str(), 0, 0, windowSize.w, windowSize.h, flags);
	renderer = SDL_CreateRenderer(window, -1, 0);
	if(fullscreen)
		updateWindowSize();
	SDL_RenderSetScale(renderer, windowSize.w/worldSize.w, windowSize.h/worldSize.h);
};

void Fx::loop(){
	while (!quit){
		SDL_Delay(frameTime);
		allEvents();
		canvas();
		draw();
		SDL_RenderPresent(renderer);
	}
};

void Fx::cleanupWindow(){
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
	windowSize = Size(x,y);
};

void Fx::allEvents(){
	SDL_PollEvent(&event);
	if(event.type == SDL_QUIT){
		quit = true;
		return;
	}
	events();
};

void Fx::canvas(){
	setColor(canvasColor);
	SDL_RenderClear(renderer);
};

SDL_Event Fx::getEvent(){
	return event;
};

void Fx::setColor(Color color){
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
};

void Fx::drawLine(Pos a, Pos b){
	SDL_RenderDrawLine(renderer, a.x, a.y, b.x, b.y);
};

