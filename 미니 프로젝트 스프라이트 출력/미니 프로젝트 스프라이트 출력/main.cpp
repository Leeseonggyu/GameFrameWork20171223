#include"Game.h"

Game*g_game = 0;

int main(int argc, char*argv[])
{
	g_game = new Game();
	g_game->init("animate", 300, 300, 853, 480, true);
	int up = 0;

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		if (up >= 6)
		{
			g_game->update2();
			up = 0;
		}
		g_game->render();
		up++;
	}
	g_game->clean();
	return 0;
}