#include "DxLib.h"
#include "Block.h"

// コンストラクタ
Block::Block() {

}

void Block::Update() 
{
	//if(CheckHitKey())
}

void Block::Draw(int blockX1, int blockY1, int blockX2, int blockY2)
{
	DrawBox(0, 0, 100, 100, GetColor(255, 0, 0), TRUE);
}