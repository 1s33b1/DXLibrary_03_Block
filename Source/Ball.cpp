#include "Ball.h"
#include "Block.h"
#include "DxLib.h"

// ボールがぶつかった後ブロックの色が黒になるか検証

// コンストラクタ
Ball::Ball()
{
	ballPosx = 540;
	ballPosy = 380;
	radius = 8;
	ballSpeed = 10;
	vy = vx = 1; // 最初は右側かつ上側に移動させるようにする
	isTouch = true; // 適当に初期化しているだけ。まだ未使用
	color = GetColor(255, 255, 0);
}

// 更新処理
// ブロックのポインタ配列にはインスタンスをnewで生成したときに
void Ball::Update(Block* pBlock[])
{
	// 40個のブロックに対してチェック
	for (int i = 0; i < 40; i++) {
		if (pBlock[i]->isExist == false) continue; // すでにブロックが壊れていたらこれより下の処理に移行する

		// もしボールの右端がブロックの左端より右にある且つ
		// ボールの左端がブロックの右端より左にある且つ
		// ボールの下端がブロックの上端より下にある且つ
		// ボールの上端がブロックの下端より上にある時に以下の処理を行う
		if (ballPosx + radius > pBlock[i]->blockPosX &&
			ballPosx - radius < pBlock[i]->blockPosX + pBlock[i]->width &&
			ballPosy + radius > pBlock[i]->blockPosY &&
			ballPosy - radius < pBlock[i]->blockPosY + pBlock[i]->height)
		{
			pBlock[i]->isExist == false; // 表示を消す
			vx *= -1;
			break; // 二個破壊させないように処理を終了させる
		}
	}

	// それぞれの移動速度に壁にぶつかったとき用のvx,vyを掛ける
	//ballPosx = ballSpeed * vx;
	//ballPosy = ballSpeed * vy;

	// else ifだと1つのキーだけじゃないとダメだったからifに変更
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		ballPosx -= ballSpeed;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		ballPosx += ballSpeed;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		ballPosy -= ballSpeed;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		ballPosy += ballSpeed;
	}
}

// 描画処理
void Ball::Draw()
{
	DrawCircle(ballPosx, ballPosy, radius , color, TRUE);
}