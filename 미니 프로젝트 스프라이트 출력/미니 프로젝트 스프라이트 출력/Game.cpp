#include"Game.h"

bool Game::init(const char*title, int xpos, int ypos, int width,
	int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;

		//SDL_Surface*pTempSurface = SDL_LoadBMP("assets/rider.bmp");
		//SDL_Surface*pTempSurface = IMG_Load("assets/animate.png");
		SDL_Surface*pTempSurface = IMG_Load("assets/animate-alpha.png");
		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

		SDL_FreeSurface(pTempSurface);
		SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

		m_sourceRectangle.w = 128;
		m_sourceRectangle.h = 82;

		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;

		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	}
	else {
		return false;
	}
	return true;
}

void Game::render()
{

	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture,
		&m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderPresent(m_pRenderer);
}
void Game::update()
{
	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
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
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:   // 왼쪽키
				x--;
				break;
			case SDLK_RIGHT:  // 오른쪽키
				x++;
				break;
			case SDLK_UP:   // 위쪽키
				y--;
				break;
			case SDLK_DOWN:   // 아래쪽키
				y++;
				break;
			}
		default:
			break;

		}
	}
}