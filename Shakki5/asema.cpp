//
//  asema.cpp
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#include "asema.h"

Asema::Asema() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			lauta[i][j] = NULL;
		}
	}

	lauta[0][0] = new Nappula(L"\u2656", 0, VT);
	lauta[1][0] = new Nappula(L"\u2658", 0, VR);
	lauta[2][0] = new Nappula(L"\u2657", 0, VL);
	lauta[3][0] = new Nappula(L"\u2655", 0, VD);
	lauta[4][0] = new Nappula(L"\u2654", 0, VK);
	lauta[0][1] = new Nappula(L"\u2659", 0, VS);

	lauta[0][7] = new Nappula(L"\u265C", 1, MT);
	lauta[1][7] = new Nappula(L"\u265E", 1, MR);
	lauta[2][7] = new Nappula(L"\u265D", 1, ML);
	lauta[3][7] = new Nappula(L"\u265A", 1, MK);
	lauta[4][7] = new Nappula(L"\u265B", 1, MD);
	lauta[0][6] = new Nappula(L"\u265F", 1, MS);

	lauta[5][0] = lauta[2][0];
	lauta[6][0] = lauta[1][0];
	lauta[7][0] = lauta[0][0];

	lauta[5][7] = lauta[2][7];
	lauta[6][7] = lauta[1][7];
	lauta[7][7] = lauta[0][7];

	for (int i = 0; i < 8; i++) {
		lauta[i][1] = lauta[1][1];
		lauta[i][6] = lauta[0][6];
	}
}
