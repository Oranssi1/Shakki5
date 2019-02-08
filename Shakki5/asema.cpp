//
//  asema.cpp
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#include "asema.h"
#include <iostream>

Asema::Asema() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			_lauta[i][j] = NULL;
		}
	}

	_lauta[0][0] = new Nappula(L"\u2656", 0, VT);
	_lauta[1][0] = new Nappula(L"\u2658", 0, VR);
	_lauta[2][0] = new Nappula(L"\u2657", 0, VL);
	_lauta[3][0] = new Nappula(L"\u2655", 0, VD);
	_lauta[4][0] = new Nappula(L"\u2654", 0, VK);
	_lauta[0][1] = new Nappula(L"\u2659", 0, VS);

	_lauta[0][7] = new Nappula(L"\u265C", 1, MT);
	_lauta[1][7] = new Nappula(L"\u265E", 1, MR);
	_lauta[2][7] = new Nappula(L"\u265D", 1, ML);
	_lauta[3][7] = new Nappula(L"\u265A", 1, MK);
	_lauta[4][7] = new Nappula(L"\u265B", 1, MD);
	_lauta[0][6] = new Nappula(L"\u265F", 1, MS);

	_lauta[5][0] = _lauta[2][0];
	_lauta[6][0] = _lauta[1][0];
	_lauta[7][0] = _lauta[0][0];

	_lauta[5][7] = _lauta[2][7];
	_lauta[6][7] = _lauta[1][7];
	_lauta[7][7] = _lauta[0][7];

	for (int i = 0; i < 8; i++) {
		_lauta[i][1] = _lauta[0][1];
		_lauta[i][6] = _lauta[0][6];
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

		else if (siirto->onkoPitkaLinna()) {
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
			Nappula* sijainti = _lauta[alkuX][alkuY];
			int nappula = sijainti->getKoodi();
			Ruutu loppuruutu = siirto->getLoppuruutu();
			int loppuX = loppuruutu.getSarake();
			int loppuY = loppuruutu.getRivi();

			switch (nappula) {
			case VK:
				_onkoValkeaKuningasLiikkunut = true;
				break;
			case MK:
				_onkoMustaKuningasLiikkunut = true;
				break;
			case VT:
				if (alkuX != 0 & alkuY != 0)
				{
					_onkoValkeaDTliikkunut = true;
					break;
				}
				_onkoValkeaKTliikkunut = true;
				break;
			case MT:
				if (alkuX != 0 & alkuY != 7)
				{
					_onkoMustaDTliikkunut = true;
					break;
				}
				_onkoMustaKTliikkunut = true;
				break;
			}
			_lauta[loppuX][loppuY] = _lauta[alkuX][alkuY];
			_lauta[alkuX][alkuY] = NULL;

			if (_siirtovuoro == 1) {
				_siirtovuoro = 0;
			}
			else {
				_siirtovuoro = 1;
			}
		}
	}

int Asema::getSiirtovuoro() {
	return _siirtovuoro;
}

void Asema::setSiirtovuoro(int vari) {
	_siirtovuoro = vari;
}

bool Asema::getOnkoValkeaKuningasLiikkunut() {
	return _onkoValkeaKuningasLiikkunut;
}

bool Asema::getOnkoMustaKuningasLiikkunut() {
	return _onkoMustaKuningasLiikkunut;
}

bool Asema::getOnkoValkeaDTliikkunut() {
	return _onkoValkeaDTliikkunut;
}

bool Asema::getOnkoValkeaKTliikkunut() {
	return _onkoValkeaKTliikkunut;
}

bool Asema::getOnkoMustaDTliikkunut() {
	return _onkoMustaDTliikkunut;
}

bool Asema::getOnkoMustaKTliikkunut() {
	return _onkoMustaKTliikkunut;
}


