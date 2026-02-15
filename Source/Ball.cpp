#include "Ball.h"
#include "Block.h"
#include "DxLib.h"

// コンストラクタ
Ball::Ball()
{
	x = 540;
	y = 380;	
	radius = 8;
	ballSpeed = 10;
	color = GetColor(255, 255, 0);
}

// 更新処理
void Ball::Update(Block& pBlock)
{
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		x -= ballSpeed;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		x += ballSpeed;
	}
}

// 描画処理
void Ball::Draw()
{
	DrawCircle(x, y, radius , color, TRUE);
}