#include "DxLib.h"
#include "Block.h"

// コンストラクタ
Block::Block() 
{
	color = GetColor(colorR, colorG, colorB); // 最初は紫っぽい色にする
}

void Block::Update(Block* pBlocks[])
{
	if (colorR >= 255) {
		colorR = 0;
	}
	if (colorG >= 255) {
		colorG = 0;
	}
	if (colorB >= 255) {
		colorB = 0;
	}
	color = GetColor(colorR, colorG, colorB);
	colorR += 10;
	colorG += 10;
	colorB += 10;
}

void Block::Draw()
{
	DrawBox(blockPosX, blockPosY, blockPosX + width, blockPosY + height, color, TRUE);
}