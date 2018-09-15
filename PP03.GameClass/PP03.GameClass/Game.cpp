#include"Game.h"

bool Game::init(const char*title, int xpos, int ypos, int width,
	int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow("PPO3. GameClass",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640, 480, SDL_WINDOW_SHOWN);
		if (g_pWindow != 0) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else {
		return 1;
	}
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;

		}
	}
}