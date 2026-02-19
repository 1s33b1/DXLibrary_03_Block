#pragma once

class Block
{
public:
	Block();
	void Draw(); // 描画関数
	void Update(Block* pBlocks[]); // 更新関数(引数にブロックの情報とかを取得するためにポインタ配列を入れている)
	int blockPosX, blockPosY; // ブロックのXY座標
	const int width = 60; // 幅
	const int height = 20; // 高さ
	bool isExist = true; // true:表示されている
private:
	unsigned int color;
	unsigned int colorR = 0; // 色
	unsigned int colorG = 50; // 色
	unsigned int colorB = 100; // 色
};

