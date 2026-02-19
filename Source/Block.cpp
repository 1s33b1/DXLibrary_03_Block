#include "DxLib.h"
#include "Block.h"

// コンストラクタ
Block::Block() 
{
	color = GetColor(colorR, colorG, colorB);
}

void Block::Update(Block* pBlocks[])
{
	if (colorR >= 255 && !isExist) {
		colorR = 0;
	}
	if (colorG >= 255 && !isExist) {
		colorG = 0;
	}
	if (colorB >= 255 && !isExist) {
		colorB = 0;
	}
	color = GetColor(colorR, colorG, colorB);
	colorR += 10;
	colorG += 10;
	colorB += 10;

	// ボールが当たったときのその後の処理
	if (isExist == true) {
		// 今のところは黒色にして見えないようにしようとしてる
		colorR = 0;
		colorG = 0;
		colorB = 0;
	}
}

void Block::Draw()
{
	DrawBox(blockPosX, blockPosY, blockPosX + width, blockPosY + height, color, TRUE);
}