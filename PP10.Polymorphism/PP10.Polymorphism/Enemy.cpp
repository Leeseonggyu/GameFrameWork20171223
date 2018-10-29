#include "Enemy.h"
#include "Game.h"

void Enemy::update()
{
	GameObject::Update();
	m_y += 1;
	//m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}