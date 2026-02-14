#pragma once

class Block
{
public:
	Block();
	~Block();
	void Update();
	void Draw(int blockX1, int blockY1, int blockX2, int blockY2);
private:
	int blockPosX, blockPosY;
};

