#pragma once

class Block
{
public:
	Block();
	//~Block();
	void Update();
	void Draw(int x1, int y1, int x2, int y2);
	int blockPosX, blockPosY;
	int width, height;

private:
};

