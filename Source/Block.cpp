#include "DxLib.h"
#include "Block.h"

// コンストラクタ
Block::Block() {

}

void Block::Update() 
{
}

void Block::Draw(int x1, int y1, int x2, int y2)
{
	DrawBox(x1, y1, x2, y2, GetColor(255, 0, 0), TRUE);
}