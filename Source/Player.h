#pragma once
#include "Ball.h"
class Player
{
public:
	Player();
	void Update();
	void Draw();
	void refrectionBall();
	int playerPosx1, playerPosy1;
	int playerPosx2, playerPosy2;
private:
	int moveSpeed;
	int color;
};
