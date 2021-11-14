#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"


//Declaring structures.									
struct Point {
	int i, j;
};

struct Level {
	int GM;										//Game mode {4;6}.
	int GF[6][6];								//Game field.
	struct Point Cur;							//Cursor.
	struct Point P1;							//First activated tile.
	struct Point P2;							//Second activated tile.
	int Act;									//Pair status flag {0; 1; 2 - activated tiles in a pair}.

	int Score;									//Current account.
	int CtMoves;								//Number of activated tiles.
	int CtPairs;								//Number of pairs removed.
};

//Game field.
void GenerateField(struct Level* L);

//Control.
void MoveUp(struct Level* L);
void MoveDown(struct Level* L);
void MoveToRight(struct Level* L);
void MoveToLeft(struct Level* L);

void Ñonfirmation(struct Level* L);
	void Discharge(struct Level* L);

//Game field graphics.
void GameFieldGraphics(HDC hdc, struct Level* L);
	
	void Cursor(HDC hdc, struct Level* L);
	void ProgressBar(HDC hdc, struct Level* L);

	void TileEmp(HDC hdc, int cx, int cy);
	void TileHid(HDC hdc, int cx, int cy);
	void Tile1(HDC hdc, int cx, int cy);
	void Tile2(HDC hdc, int cx, int cy);
	void Tile3(HDC hdc, int cx, int cy);
	void Tile4(HDC hdc, int cx, int cy);
	void Tile5(HDC hdc, int cx, int cy);
	void Tile6(HDC hdc, int cx, int cy);
	void Tile7(HDC hdc, int cx, int cy);
	void Tile8(HDC hdc, int cx, int cy);