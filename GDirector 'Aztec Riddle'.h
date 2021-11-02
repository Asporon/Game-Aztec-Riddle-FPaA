#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"


//Управление.
void MoveUp();
void MoveDown();
void MoveToRight();
void MoveToLeft();
void Сonfirmation();
void Discharge();

//Графика.
void GameFieldGraphics(HDC hdc);
