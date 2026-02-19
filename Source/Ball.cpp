#include "Ball.h"
#include "Block.h"
#include "../GameParameter.h"
#include "DxLib.h"

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
void Ball::Update(Block* pBlock[], Player* pPlayer)
{
	// 40個のブロックに対してチェック
	for (int i = 0; i < 40; i++) {
		if (pBlock[i]->isExist == false) continue; // すでにブロックが壊れていたらこれより下の処理に移行する

		// もし
		// ボールの右端がブロックの左端より右にある且つ
		// ボールの左端がブロックの右端より左にある且つ
		// ボールの下端がブロックの上端より下にある且つ
		// ボールの上端がブロックの下端より上にある時に以下の処理を行う
		if (ballPosx + radius > pBlock[i]->blockPosX &&
			ballPosx - radius < pBlock[i]->blockPosX + pBlock[i]->width &&
			ballPosy + radius > pBlock[i]->blockPosY &&
			ballPosy - radius < pBlock[i]->blockPosY + pBlock[i]->height)
		{
			pBlock[i]->isExist = false; // 表示を消す
			vy *= -1;
			break; // 二個破壊させないように処理を終了させる
		}
	}

	// プレイヤーに当たった時の処理を考えている
	if (ballPosx + radius > pPlayer->playerPosx1 &&
		ballPosx - radius < pPlayer->playerPosx2 &&
		ballPosy + radius > pPlayer->playerPosy1)
	{
		vy *= -1;
		ballPosy = pPlayer->playerPosy1 - radius; // 反射をさせるときにボールの位置をプレイヤーの上にする
	}

	// それぞれの移動速度に壁にぶつかったとき用のvx,vyを掛ける
	ballPosx += ballSpeed * vx;
	ballPosy += ballSpeed * vy;

	// 壁(SetGraphModeで宣言した描画範囲)に当たった時の処理
	// 左右のどちらかに当たった時
	if (ballPosx >= ScreenSettings::screenWidth - radius) {
		vx = -1;
	}
	else if (ballPosx <= 0 + radius) {
		vx = 1;
	}

	// 上下のどちらかに当たった時
	if (ballPosy >= ScreenSettings::screenHeight - radius) {
		vy = -1;
	}
	else if (ballPosy <= 0 + radius) {
		vy = 1;
	}
}

// 描画処理
void Ball::Draw()
{
	DrawCircle(ballPosx, ballPosy, radius , color, TRUE);
}