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

	_siirtovuoro = 0;
	_onkoValkeaKuningasLiikkunut = false;
	_onkoMustaKuningasLiikkunut = false;
	_onkoValkeaDTliikkunut = false;
	_onkoValkeaKTliikkunut = false;
	_onkoMustaDTliikkunut = false;
	_onkoMustaKTliikkunut = false;
}

	void Asema::paivitaAsema(Siirto* siirto) {

		if (siirto->onkoLyhytLinna()) {
			if (_siirtovuoro == 0) {
				_lauta[6][0] = _lauta[4][0];
				_lauta[4][0] = NULL;
				_lauta[5][0] = _lauta[7][0];
				_lauta[7][0] = NULL;
			}

			if (_siirtovuoro == 1) {
				_lauta[6][7] = _lauta[4][7];
				_lauta[4][7] = NULL;
				_lauta[5][7] = _lauta[7][7];
				_lauta[7][7] = NULL;
			}
		}

		else if (siirto->onkoPitkälinna()) {
			if (_siirtovuoro == 0) {
				_lauta[2][0] = _lauta[4][0];
				_lauta[4][0] = NULL;
				_lauta[3][0] = _lauta[0][0];
				_lauta[0][0] = NULL;
			}

			if (_siirtovuoro == 1) {
				_lauta[2][7] = _lauta[4][7];
				_lauta[4][7] = NULL;
				_lauta[3][7] = _lauta[0][7];
				_lauta[0][7] = NULL;
			}
		}

		else {
			Ruutu alkuruutu = siirto->getAlkuruutu();
			int alkuX = alkuruutu.getSarake();
			int alkuY = alkuruutu.getRivi();
			Nappula* sijainti = lauta[alkuX][alkuY];
			int nappula = sijainti->getKoodi();
			Ruutu loppuruutu = siirto->getLoppuruutu();
			int loppuX = loppuruutu.getSarake();
			int loppuY = loppuruutu.getRivi();

			switch (nappula) {
			case VK:
				onkoValkeaKuningasLiikkunut = true;
				break;
			case MK:
				onkoMustaKuningasLiikkunut = true;
				break;
			case VT:
				if (alkuX != 0 & alkuY != 0)
				{
					onkoValkeaDTliikkunut = true;
					break;
				}
				onkoValkeaKTliikkunut = true;
				break;
			case MT:
				if (alkuX != 0 & alkuY != 7)
				{
					onkoMustaDTliikkunut = true;
					break;
				}
				onkoMustaKTliikkunut = true;
				break;
			}
			lauta[loppuX][loppuY] = lauta[alkuX][alkuY];
			lauta[alkuX][alkuY] = NULL;

			if (siirtovuoro == 1) {
				siirtovuoro = 0;
			}
			else {
				siirtovuoro = 1;
			}
		}
	}

int Asema::getSiirtovuoro() {
	return siirtovuoro;
}

void Asema::setSiirtovuoro(int vari) {
	siirtovuoro = vari;
}

bool Asema::getOnkoValkeaKuningasLiikkunut() {
	return onkoValkeaKuningasLiikkunut;
}

bool Asema::getOnkoMustaKuningasLiikkunut() {
	return onkoMustaKuningasLiikkunut;
}

bool Asema::getOnkoValkeaDTliikkunut() {
	return onkoValkeaDTliikkunut;
}

bool Asema::getOnkoValkeaKTliikkunut() {
	return onkoValkeaKTliikkunut;
}

bool Asema::getOnkoMustaDTliikkunut() {
	return onkoMustaDTliikkunut;
}

bool Asema::getOnkoMustaKTliikkunut() {
	return onkoMustaKTliikkunut;
}


