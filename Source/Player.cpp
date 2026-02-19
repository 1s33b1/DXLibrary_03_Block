#include "Player.h"
#include "DxLib.h"

Player::Player()
{
	playerPosx1 = 270;	playerPosy1 = 450;
	playerPosx2 = 350;  playerPosy2 = 470;
	color = GetColor(255, 255, 255);
	moveSpeed = 7;
}

void Player::Update()
{
	if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A)) {
		playerPosx1 -= moveSpeed;
		playerPosx2 -= moveSpeed;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D)) {
		playerPosx1 += moveSpeed;
		playerPosx2 += moveSpeed;
	}
}

void Player::Draw()
{
	DrawBox(playerPosx1, playerPosy1, playerPosx2, playerPosy2, color, TRUE);
}