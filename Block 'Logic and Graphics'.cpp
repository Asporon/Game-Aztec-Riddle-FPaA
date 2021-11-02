#include "GDirector 'Aztec Riddle'.h"
#include "framework.h"
#include "stdio.h"


//Инициализация переменных.
#define N 4
#define M 4

int CurI = 0, CurJ = 0;											
int GF[N][M] = {
	{1, 1, 2, 2},
	{3, 3, 4, 4},
	{5, 5, 6, 6},
	{7, 7, 8, 8}
};
											
int T1I, T1J;																										 
int T2I, T2J;													
int Act = 0;													

int CountM = 0, CountP = 0;										

int i, j;														

//Управление.
void MoveUp() {
	if (CurI != 0) CurI--;
	CountM++;
}
void MoveDown() {
	if (CurI != 3) CurI++;
	CountM++;
}
void MoveToRight() {
	if (CurJ != 3) CurJ++;
	CountM++;
}
void MoveToLeft() {
	if (CurJ != 0) CurJ--;
	CountM++;
}
void Сonfirmation() {
	if (Act == 0 && GF[CurI][CurJ] > 0 && GF[CurI][CurJ] < 9) {
		T1I = CurI;
		T1J = CurJ;
		GF[T1I][T1J] += 10;
		Act = 1;
	}
	if (Act == 1 && GF[CurI][CurJ] > 0 && GF[CurI][CurJ] < 9 && (T1I != CurI || T1J != CurJ)) {
		T2I = CurI;
		T2J = CurJ;
		GF[T2I][T2J] += 10;
		Act = 2;
	}	 
}
void Discharge() {
	if (GF[T1I][T1J] == GF[T2I][T2J] && Act == 2) {
		GF[T1I][T1J] = 0;
		GF[T2I][T2J] = 0;
		Act = 0;
	}
	else  if (GF[T1I][T1J] != GF[T2I][T2J] && Act == 2) {
		GF[T1I][T1J] -= 10;
		GF[T2I][T2J] -= 10;
		Act = 0;
	}
}

//Графика.
void GameFieldGraphics(HDC hdc) {

	//Курсор.
	HPEN hPenTileCur = CreatePen(PS_SOLID, 1, RGB(255, 215, 0));
	SelectObject(hdc, hPenTileCur);
	HBRUSH hBrushTileCur = CreateSolidBrush(RGB(255, 215, 0));
	SelectObject(hdc, hBrushTileCur);

	POINT P[10] = {
	CurJ * 140 + 5,		CurI * 140 + 5,
	CurJ * 140 + 155,	CurI * 140 + 5,
	CurJ * 140 + 155,	CurI * 140 + 155,
	CurJ * 140 + 5,		CurI * 140 + 155,
	CurJ * 140 + 15,	CurI * 140 + 145,
	CurJ * 140 + 145,	CurI * 140 + 145,
	CurJ * 140 + 145,	CurI * 140 + 15,
	CurJ * 140 + 15,	CurI * 140 + 15,
	CurJ * 140 + 15,	CurI * 140 + 145,
	CurJ * 140 + 5,		CurI * 140 + 155,
	};

	Polygon(hdc, P, 10);

	DeleteObject(hPenTileCur);
	DeleteObject(hBrushTileCur);
	
	//Игровое поле.
	int Tile = 140;

	HBRUSH hBrushTileAb = CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH hBrushTileHi = CreateSolidBrush(RGB(128, 128, 128));

	HBRUSH hBrushTile1 = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hBrushTile2 = CreateSolidBrush(RGB(255, 255, 0));
	HBRUSH hBrushTile3 = CreateSolidBrush(RGB(0, 128, 0));
	HBRUSH hBrushTile4 = CreateSolidBrush(RGB(255, 140, 0));
	HBRUSH hBrushTile5 = CreateSolidBrush(RGB(0, 0, 128));
	HBRUSH hBrushTile6 = CreateSolidBrush(RGB(148, 0, 211));
	HBRUSH hBrushTile7 = CreateSolidBrush(RGB(192, 192, 192));
	HBRUSH hBrushTile8 = CreateSolidBrush(RGB(20, 20, 20));

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++) {
			RECT rect = { j * Tile + 20, i * Tile + 20, (j + 1) * Tile, (i + 1) * Tile };
			if (GF[i][j] == 0) {
				FillRect(hdc, &rect, hBrushTileAb);
			}
			else if (GF[i][j] > 0 && GF[i][j] < 9) {
				FillRect(hdc, &rect, hBrushTileHi);
			}
			else if (GF[i][j] == 11) {
				FillRect(hdc, &rect, hBrushTile1);
			}
			else if (GF[i][j] == 12) {
				FillRect(hdc, &rect, hBrushTile2);
			}
			else if (GF[i][j] == 13) {
				FillRect(hdc, &rect, hBrushTile3);
			}
			else if (GF[i][j] == 14) {
				FillRect(hdc, &rect, hBrushTile4);
			}
			else if (GF[i][j] == 15) {
				FillRect(hdc, &rect, hBrushTile5);
			}
			else if (GF[i][j] == 16) {
				FillRect(hdc, &rect, hBrushTile6);
			}
			else if (GF[i][j] == 17) {
				FillRect(hdc, &rect, hBrushTile7);
			}
			else if (GF[i][j] == 18) {
				FillRect(hdc, &rect, hBrushTile8);
			}
			else {
			}
		}

	DeleteObject(hBrushTileAb);
	DeleteObject(hBrushTileHi);

	DeleteObject(hBrushTile1);
	DeleteObject(hBrushTile2);
	DeleteObject(hBrushTile3);
	DeleteObject(hBrushTile4);
	DeleteObject(hBrushTile5);
	DeleteObject(hBrushTile6);
	DeleteObject(hBrushTile7);
	DeleteObject(hBrushTile8);
}