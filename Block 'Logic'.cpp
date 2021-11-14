#include "GDirector 'Aztec Riddle'.h"
#include "framework.h"
#include "ctime"
#include "signal.h"



//Game field.
void GenerateField(struct Level* L) {
	srand(time(NULL));
	
	int lim, fl;								//lim - number of pairs; fl - confirmation of random tile.
	int Ad[19];									//Array of tile counters.

	if (L->GM == 4) lim = 8;
	else if (L->GM == 6) lim = 18;

	for (int i = 0; i <= lim; i++)
		Ad[i] = 0;

	for (int i = 0; i < L->GM; i++) 
		for (int j = 0; j < L->GM; j++) {
			fl = 0;
			while (fl != 1) {
				L->GF[i][j] = 1 + rand() % lim;
				if (Ad[L->GF[i][j]] < 2) {
					Ad[L->GF[i][j]]++;
					fl = 1;
				}
			}
		}
}

//Control.
void MoveUp(struct Level* L) {
	if (L->Cur.i != 0) L->Cur.i--;
}
void MoveDown(struct Level* L) {
	if (L->Cur.i != (L->GM - 1)) L->Cur.i++;
}
void MoveToRight(struct Level* L) {
	if (L->Cur.j != (L->GM - 1)) L->Cur.j++;
}
void MoveToLeft(struct Level* L) {
	if (L->Cur.j != 0) L->Cur.j--;
}

void Ñonfirmation(struct Level* L) {
	if (L->Act == 0 && L->GF[L->Cur.i][L->Cur.j] > 0 && L->GF[L->Cur.i][L->Cur.j] < 19) {
		L->P1.i = L->Cur.i;
		L->P1.j = L->Cur.j;
		L->GF[L->P1.i][L->P1.j] += 20;
		L->Act = 1;

		L->CtMoves++;
	}
	if (L->Act == 1 && L->GF[L->Cur.i][L->Cur.j] > 0 && L->GF[L->Cur.i][L->Cur.j] < 19 && (L->P1.i != L->Cur.i || L->P1.j != L->Cur.j)) {
		L->P2.i = L->Cur.i;
		L->P2.j = L->Cur.j;
		L->GF[L->P2.i][L->P2.j] += 20;
		L->Act = 2;

		L->CtMoves++;
	}
}
void Discharge(struct Level* L) {
	if (L->Act == 2) {
		if (L->GF[L->P1.i][L->P1.j] == L->GF[L->P2.i][L->P2.j]) {
			L->CtPairs++;
			if (L->GF[L->P1.i][L->P1.j] < 30) L->Score += 800;
			else if (L->GF[L->P1.i][L->P1.j] > 29) L->Score += 600;

			L->GF[L->P1.i][L->P1.j] = 0;
			L->GF[L->P2.i][L->P2.j] = 0;
			L->Act = 0;
		}
		if ((L->GF[L->P1.i][L->P1.j] == L->GF[L->P2.i][L->P2.j] - 9) || (L->GF[L->P1.i][L->P1.j] - 9 == L->GF[L->P2.i][L->P2.j])) {
			L->CtPairs++;
			L->Score += 400;
			
			L->GF[L->P1.i][L->P1.j] = 0;
			L->GF[L->P2.i][L->P2.j] = 0;
			L->Act = 0;
		}
		if (L->GF[L->P1.i][L->P1.j] != L->GF[L->P2.i][L->P2.j]) {
			L->GF[L->P1.i][L->P1.j] -= 20;
			L->GF[L->P2.i][L->P2.j] -= 20;
			L->Act = 0;
		}
	}
}