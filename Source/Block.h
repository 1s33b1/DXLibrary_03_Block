#pragma once

class Block
{
public:
	Block();
	void Draw(); // 描画関数
	void Update(Block* pBlocks[]); // 更新関数
	int blockPosX, blockPosY; // ブロックのXY座標
	bool isExist = true; // 壊れていないか
private:
	const int width = 60; // 幅
	const int height = 20; // 高さ
	unsigned int color;
	unsigned int colorR = 0; // 色
	unsigned int colorG = 50; // 色
	unsigned int colorB = 100; // 色
};

