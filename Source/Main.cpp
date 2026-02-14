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

	Block* pBlocks[50];

	for (int i = 0; i < 50; i++) {
		pBlocks[i] = new Block(); // ループで各配列ごとにブロックのインスタンス生成
		pBlocks[i]->Draw();
	}
	
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen(); // 画面をまっさらに
		
		ScreenFlip();    // 画面を更新して、少し休む	
	}

	///------------------------------------------------------
	// 終了処理
	for (int i = 0; i < 50; i++)
	{
		delete pBlocks[i];
	}
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}

