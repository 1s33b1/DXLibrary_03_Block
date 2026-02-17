#pragma once
#include "Block.h"
class Ball
{
public:
	Ball();
	void Draw();
	void Update(Block* pBlock[]);
private:
	int x, y; // XY座標
	int radius; // ボールの半径
	int ballSpeed; // ボールのスピード
	bool isTouch; // true:壁もしくはブロックに当たった
	unsigned int color;
};
