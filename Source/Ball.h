#pragma once
#include "Block.h"
#include "Player.h"
class Ball
{
public:
	Ball();
	void Draw();
	void Update(Block* pBlock[], Player player);
private:
	int ballPosx, ballPosy; // XY座標
	int radius; // ボールの半径
	int ballSpeed; // ボールのスピード
	int vx, vy; // ブロックもしくは壁に当たった時に現在進んでいる方向の逆に進ませる変数
	bool isTouch; // true:壁もしくはブロックに当たった
	unsigned int color;
};
