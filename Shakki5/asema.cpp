//
//  asema.cpp
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#include "asema.h"

// Heinin koodi
// Nappula* Asema::vk = new Nappula(L"\u2654", 0, VK)
// Nappula* Asema::vd = new Nappula(L"\u2655", 0, VD)
// Nappula* Asema::vt = new Nappula(L"\u2656", 0, VT)
// Nappula* Asema::vl = new Nappula(L"\u2657", 0, VL)
// Nappula* Asema::vr = new Nappula(L"\u2658", 0, VR)
// Nappula* Asema::vs = new Nappula(L"\u2659", 0, VS)

// Nappula* Asema::mk = new Nappula(L"\u265A", 1, MK)
// Nappula* Asema::md = new Nappula(L"\u265B", 1, MD)
// Nappula* Asema::mt = new Nappula(L"\u265C", 1, MT)
// Nappula* Asema::ml = new Nappula(L"\u265D", 1, ML)
// Nappula* Asema::mr = new Nappula(L"\u265E", 1, MR)
// Nappula* Asema::ms = new Nappula(L"\u265F", 1, MS)

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
		lauta[i][1] = lauta[0][1];
		lauta[i][6] = lauta[0][6];
	}
}
/*
	void Asema::paivitaAsema(Siirto* siirto) {

	}
	int getSiirtovuoro();
	void setSiirtovuoro(int vari);
	bool getOnkoValkeaKuningasLiikkunut();
	bool getOnkoMustaKuningasLiikkunut();
	bool getOnkoValkeaDTliikkunut();
	bool getOnkoValkeaKTliikkunut();
	bool getOnkoMustaDTliikkunut();
	bool getOnkoMustaKTliikkunut();
*/
	// Heinin koodi
	// lauta[0][0] = vt;
	// lauta[1][0] = vr;
	// lauta[2][0] = vl;
	// lauta[3][0] = vd;
	// lauta[4][0] = vk;
	// lauta[5][0] = vl;
	// lauta[6][0] = vr;
	// lauta[7][0] = vt;

	// lauta[0][1] = vs;
	// lauta[1][1] = vs;
	// lauta[2][1] = vs;
	// lauta[2][1] = vs;
	// lauta[3][1] = vs;
	// lauta[4][1] = vs;
	// lauta[5][1] = vs;
	// lauta[6][1] = vs;
	// lauta[7][1] = vs;

	// lauta[0][7] = mt;
	// lauta[1][7] = mr;
	// lauta[2][7] = ml;
	// lauta[3][7] = md;
	// lauta[4][7] = mk;
	// lauta[5][7] = ml;
	// lauta[6][7] = mr;
	// lauta[7][7] = mt;

	// lauta[0][6] = ms;
	// lauta[1][6] = ms;
	// lauta[2][6] = ms;
	// lauta[2][6] = ms;
	// lauta[3][6] = ms;
	// lauta[4][6] = ms;
	// lauta[5][6] = ms;
	// lauta[6][6] = ms;
	// lauta[7][6] = ms;

