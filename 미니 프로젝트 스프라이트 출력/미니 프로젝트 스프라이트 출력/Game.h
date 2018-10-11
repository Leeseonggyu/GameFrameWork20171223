#pragma once
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>


class Game
{
public:
	Game() {};
	~Game() {};
	SDL_Window* g_pWindow = 0;
	SDL_Renderer* g_pRenderer = 0;
	SDL_Texture*m_pTexture;
	SDL_Texture*m_pTexture2;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
	SDL_Rect m_sourceRectangle2;
	SDL_Rect m_destinationRectangle2;
	bool init(const char*title, int xpos, int ypos, int width,
		int height, bool fullscreen);

	void render();
	void update();
	void update2();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	int x = 0, y = 0;
private:
	SDL_Window * m_pWindow;
	SDL_Renderer*m_pRenderer;
	
	bool m_bRunning = true;
};