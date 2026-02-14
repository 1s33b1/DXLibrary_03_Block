#include "DxLib.h"
#include "../GameParameter.h"
#include "Block.h"

/// <summary>
/// ブロック崩し
/// </summary>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;
	SetGraphMode(ScreenSettings::screenWidth, ScreenSettings::screenHeight, 30); // 画面のサイズを決定
	SetDrawScreen(DX_SCREEN_BACK);
	SetMouseDispFlag(TRUE); // マウスカーソルを表示


	const int COLUMN = 8; // 横に並べる数
	const int ROW = 5; // 縦に並べる数
	const int B_WIDTH = 60; // ブロックの横幅
	const int B_HEIGHT = 20; // ブロックの高さ
	const int GAP = 5; // 隙間
	const int OFFSET_X = 60; // 左端の余白
	const int OFFSET_Y = 50; // 上端の余白
	Block* pBlocks[COLUMN * ROW];

	for (int y = 0; y < ROW; y++) {
		for (int x = 0; x < COLUMN; x++) {
			int index = y * COLUMN + x;
			pBlocks[index] = new Block();

			pBlocks[index]->blockPosX = OFFSET_X + x * (B_WIDTH + GAP);
			pBlocks[index]->blockPosY = OFFSET_Y + y * (B_HEIGHT + GAP);
			pBlocks[index]->Draw(x, y, x + B_WIDTH, y + B_HEIGHT);
		}
	}
		
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen(); // 画面をまっさらに
		
		ScreenFlip();    // 画面を更新して、少し休む	
	}


	///------------------------------------------------------
	// 終了処理
	for (int i = 0; i < COLUMN * ROW; i++)
	{
		delete pBlocks[i];
	}
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}

