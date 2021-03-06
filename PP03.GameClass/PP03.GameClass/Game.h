#pragma once
#include<SDL.h>
#include<iostream>

class Game
{
public:
	Game() {};
	~Game() {};
	SDL_Window* g_pWindow = 0;
	SDL_Renderer* g_pRenderer = 0;
	bool init(const char*title, int xpos, int ypos, int width,
		int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
private:
	SDL_Window * m_pWindow;
	SDL_Renderer*m_pRenderer;
	bool m_bRunning = true;
};