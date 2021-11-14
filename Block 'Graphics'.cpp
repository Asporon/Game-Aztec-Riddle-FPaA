#include "GDirector 'Aztec Riddle'.h"
#include "framework.h"
#include "stdio.h"


//Game field graphics.
void GameFieldGraphics(HDC hdc, struct Level* L) {
	Cursor(hdc, L);
	ProgressBar(hdc, L);

	for (int i = 0; i < L->GM; i++)
		for (int j = 0; j < L->GM; j++) 
			if (L->GF[i][j] == 0) TileEmp(hdc, 80 + j * 140, 80 + i * 140);
			else if (L->GF[i][j] > 0 && L->GF[i][j] < 19) TileHid(hdc, 80 + j * 140, 80 + i * 140);
			else if (L->GF[i][j] == 21) Tile1(hdc, 80 + j * 140, 80 + i * 140);
			else if (L->GF[i][j] == 22) Tile2(hdc, 80 + j * 140, 80 + i * 140);
			else if (L->GF[i][j] == 23) Tile3(hdc, 80 + j * 140, 80 + i * 140);
			else if (L->GF[i][j] == 24) Tile4(hdc, 80 + j * 140, 80 + i * 140);
			else if (L->GF[i][j] == 25) Tile5(hdc, 80 + j * 140, 80 + i * 140);
			else if (L->GF[i][j] == 26) Tile6(hdc, 80 + j * 140, 80 + i * 140);
			else if (L->GF[i][j] == 27) Tile7(hdc, 80 + j * 140, 80 + i * 140);
			else if (L->GF[i][j] == 28) Tile8(hdc, 80 + j * 140, 80 + i * 140);
		
}

//Rendering add.elements.
void Cursor(HDC hdc, struct Level* L) {

	HPEN hPenTileCur = CreatePen(PS_SOLID, 1, RGB(255, 215, 0));
	SelectObject(hdc, hPenTileCur);
	HBRUSH hBrushTileCur = CreateSolidBrush(RGB(255, 215, 0));
	SelectObject(hdc, hBrushTileCur);

	POINT P[10] = {
	L->Cur.j * 140 + 5,		L->Cur.i * 140 + 5,
	L->Cur.j * 140 + 155,	L->Cur.i * 140 + 5,
	L->Cur.j * 140 + 155,	L->Cur.i * 140 + 155,
	L->Cur.j * 140 + 5,		L->Cur.i * 140 + 155,
	L->Cur.j * 140 + 15,	L->Cur.i * 140 + 145,
	L->Cur.j * 140 + 145,	L->Cur.i * 140 + 145,
	L->Cur.j * 140 + 145,	L->Cur.i * 140 + 15,
	L->Cur.j * 140 + 15,	L->Cur.i * 140 + 15,
	L->Cur.j * 140 + 15,	L->Cur.i * 140 + 145,
	L->Cur.j * 140 + 5,		L->Cur.i * 140 + 155,
	};

	Polygon(hdc, P, 10);

	DeleteObject(hPenTileCur);
	DeleteObject(hBrushTileCur);
}
void ProgressBar(HDC hdc, struct Level* L) {	
	HFONT hFont = CreateFont
		(25, 0, 0, 0, 0, 0, 0, 0,
		DEFAULT_CHARSET,
		0, 0, 0, 0,
		L"Bahnschrift"
	);
	SelectObject(hdc, hFont);
	SetTextColor(hdc, RGB(0, 0, 0));

	TCHAR  StrScore[] = _T("Score:");
	TCHAR  StrCtMoves[] = _T("Tiles activated:");
	TCHAR  StrCtPairs[] = _T("Pairs of tiles left:");
	TextOut(hdc, 100, 600, (LPCWSTR)StrScore, _tcslen(StrScore));
	TextOut(hdc, 100, 625, (LPCWSTR)StrCtMoves, _tcslen(StrCtMoves));
	TextOut(hdc, 100, 650, (LPCWSTR)StrCtPairs, _tcslen(StrCtPairs));

	char cScore[6];
	TCHAR  tcScore[6];
	sprintf(cScore, "%d", L->Score);
	OemToChar(cScore, tcScore);
	TextOut(hdc, 400, 600, (LPCWSTR)tcScore, _tcslen(tcScore));

	char cCtMoves[5];
	TCHAR  tcCtMoves[5];
	sprintf(cCtMoves, "%d", L->CtMoves);
	OemToChar(cCtMoves, tcCtMoves);
	TextOut(hdc, 400, 625, (LPCWSTR)tcCtMoves, _tcslen(tcCtMoves));

	char cCtPairs[5];
	TCHAR  tcCtPairs[5];
	sprintf(cCtPairs, "%d", 8 - L->CtPairs);
	OemToChar(cCtPairs, tcCtPairs);
	TextOut(hdc, 400, 650, (LPCWSTR)tcCtPairs, _tcslen(tcCtPairs));

	DeleteObject(hFont);
}

//Rendering tiles.
void TileEmp(HDC hdc, int cx, int cy) {

	HPEN hPenTileEmp = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	SelectObject(hdc, hPenTileEmp);
	HBRUSH hBrushTileEmp = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hBrushTileEmp);

	Rectangle(hdc, cx - 60, cy - 60, cx + 60, cy + 60);

	DeleteObject(hBrushTileEmp);
	DeleteObject(hPenTileEmp);
}
void TileHid(HDC hdc, int cx, int cy) {

	HPEN hPenTileHid = CreatePen(PS_SOLID, 1, RGB(128, 128, 128));
	SelectObject(hdc, hPenTileHid);
	HBRUSH hBrushTileHid = CreateSolidBrush(RGB(128, 128, 128));
	SelectObject(hdc, hBrushTileHid);

	Rectangle(hdc, cx - 60, cy - 60, cx + 60, cy + 60);

	DeleteObject(hBrushTileHid);
	DeleteObject(hPenTileHid);
}
void Tile1(HDC hdc, int cx, int cy) {

	HPEN hPenTile1 = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	SelectObject(hdc, hPenTile1);
	HBRUSH hBrushTile1 = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, hBrushTile1);

	Rectangle(hdc, cx - 60, cy - 60, cx + 60, cy + 60);

	DeleteObject(hBrushTile1);
	DeleteObject(hPenTile1);
}
void Tile2(HDC hdc, int cx, int cy) {

	HPEN hPenTile2 = CreatePen(PS_SOLID, 1, RGB(255, 140, 0));
	SelectObject(hdc, hPenTile2);
	HBRUSH hBrushTile2 = CreateSolidBrush(RGB(255, 140, 0));
	SelectObject(hdc, hBrushTile2);

	Rectangle(hdc, cx - 60, cy - 60, cx + 60, cy + 60);

	DeleteObject(hBrushTile2);
	DeleteObject(hPenTile2);
}
void Tile3(HDC hdc, int cx, int cy) {

	HPEN hPenTile3 = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));
	SelectObject(hdc, hPenTile3);
	HBRUSH hBrushTile3 = CreateSolidBrush(RGB(255, 255, 0));
	SelectObject(hdc, hBrushTile3);

	Rectangle(hdc, cx - 60, cy - 60, cx + 60, cy + 60);

	DeleteObject(hBrushTile3);
	DeleteObject(hPenTile3);
}
void Tile4(HDC hdc, int cx, int cy) {

	HPEN hPenTile4 = CreatePen(PS_SOLID, 1, RGB(0, 0, 128));
	SelectObject(hdc, hPenTile4);
	HBRUSH hBrushTile4 = CreateSolidBrush(RGB(0, 0, 128));
	SelectObject(hdc, hBrushTile4);

	Rectangle(hdc, cx - 60, cy - 60, cx + 60, cy + 60);

	DeleteObject(hBrushTile4);
	DeleteObject(hPenTile4);
}
void Tile5(HDC hdc, int cx, int cy) {

	HPEN hPenTile5 = CreatePen(PS_SOLID, 1, RGB(153, 50, 204));
	SelectObject(hdc, hPenTile5);
	HBRUSH hBrushTile5 = CreateSolidBrush(RGB(153, 50, 204));
	SelectObject(hdc, hBrushTile5);

	Rectangle(hdc, cx - 60, cy - 60, cx + 60, cy + 60);

	DeleteObject(hBrushTile5);
	DeleteObject(hPenTile5);
}
void Tile6(HDC hdc, int cx, int cy) {

	HPEN hPenTile6 = CreatePen(PS_SOLID, 1, RGB(0, 128, 0));
	SelectObject(hdc, hPenTile6);
	HBRUSH hBrushTile6 = CreateSolidBrush(RGB(0, 128, 0));
	SelectObject(hdc, hBrushTile6);

	Rectangle(hdc, cx - 60, cy - 60, cx + 60, cy + 60);

	DeleteObject(hBrushTile6);
	DeleteObject(hPenTile6);
}
void Tile7(HDC hdc, int cx, int cy) {

	HPEN hPenTile7 = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(hdc, hPenTile7);
	HBRUSH hBrushTile7 = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBrushTile7);

	Rectangle(hdc, cx - 60, cy - 60, cx + 60, cy + 60);

	DeleteObject(hBrushTile7);
	DeleteObject(hPenTile7);
}
void Tile8(HDC hdc, int cx, int cy) {

	HPEN hPenTile8 = CreatePen(PS_SOLID, 1, RGB(211, 211, 211));
	SelectObject(hdc, hPenTile8);
	HBRUSH hBrushTile8 = CreateSolidBrush(RGB(211, 211, 211));
	SelectObject(hdc, hBrushTile8);

	Rectangle(hdc, cx - 60, cy - 60, cx + 60, cy + 60);

	DeleteObject(hBrushTile8);
	DeleteObject(hPenTile8);
}