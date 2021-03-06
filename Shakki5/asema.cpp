﻿//
//  asema.cpp
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright ｩ 2019 B & J Corp. All rights reserved.
//

#include "asema.h"
#include <iostream>
#include "nappula.h"

Nappula* Asema::vt = new Torni(L"\u2656", 0, VT);
Nappula* Asema::vr = new Ratsu(L"\u2658", 0, VR);
Nappula* Asema::vl = new Lahetti(L"\u2657", 0, VL);
Nappula* Asema::vd = new Daami(L"\u2655", 0, VD);
Nappula* Asema::vk = new Kuningas(L"\u2654", 0, VK);
Nappula* Asema::vs = new Sotilas(L"\u2659", 0, VS);

Nappula* Asema::mt = new Torni(L"\u265C", 1, MT);
Nappula* Asema::mr = new Ratsu(L"\u265E", 1, MR);
Nappula* Asema::ml = new Lahetti(L"\u265D", 1, ML);
Nappula* Asema::mk = new Kuningas(L"\u265A", 1, MK);
Nappula* Asema::md = new Daami(L"\u265B", 1, MD);
Nappula* Asema::ms = new Sotilas(L"\u265F", 1, MS);

Asema::Asema() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			_lauta[i][j] = NULL;
		}
	}

	_lauta[6][4] = new Torni(L"\u2656", 0, VT);
//	_lauta[4][4] = new Lahetti(L"\u2657", 0, VL);
//	_lauta[3][3] = new Ratsu(L"\u2658", 0, VR);
	_lauta[6][2] = new Kuningas(L"\u2654", 0, VK);
//	_lauta[3][4] = new Kuningas(L"\u265A", 1, MK);
//	_lauta[1][3] = new Sotilas(L"\u2659", 0, VS);
//	_lauta[5][5] = new Sotilas(L"\u2659", 0, VS);
//	_lauta[2][6] = new Sotilas(L"\u265F", 1, MS);
//	_lauta[3][6] = new Sotilas(L"\u265F", 1, MS);
//	_lauta[3][3] = new Sotilas(L"\u265F", 1, MS);
//	_lauta[0][1] = new Sotilas(L"\u265F", 1, MS);
//	_lauta[1][1] = new Sotilas(L"\u265F", 1, MS);
//	_lauta[4][3] = new Daami(L"\u2655", 0, VD);
	_lauta[6][6] = new Torni(L"\u265C", 1, MT);



	//_lauta[0][0] = vt;
	//_lauta[1][0] = vr;
	//_lauta[2][0] = vl;
	//_lauta[3][0] = vd;
	//_lauta[4][0] = vk;
	//_lauta[0][1] = vs;

	//_lauta[0][7] = mt;
	//_lauta[1][7] = mr;
	//_lauta[2][7] = ml;
	//_lauta[4][7] = mk;
	//_lauta[3][7] = md;
	//_lauta[0][6] = ms;

	//_lauta[5][0] = _lauta[2][0];
	//_lauta[6][0] = _lauta[1][0];
	//_lauta[7][0] = _lauta[0][0];

	//_lauta[5][7] = _lauta[2][7];
	//_lauta[6][7] = _lauta[1][7];
	//_lauta[7][7] = _lauta[0][7];

	//for (int i = 0; i < 8; i++) {
	//	_lauta[i][1] = _lauta[0][1];
	//	_lauta[i][6] = _lauta[0][6];
	//}

	_siirtovuoro = 0;
	_onkoValkeaKuningasLiikkunut = false;
	_onkoMustaKuningasLiikkunut = false;
	_onkoValkeaDTliikkunut = false;
	_onkoValkeaKTliikkunut = false;
	_onkoMustaDTliikkunut = false;
	_onkoMustaKTliikkunut = false;
	_kaksoisaskelSarakkeella = -1;
}

	void Asema::paivitaAsema(Siirto* siirto) {

		if (_kaksoisaskelSarakkeella != -1) {
			_kaksoisaskelSarakkeella = -1;
		}
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
			Nappula* sijainti = _lauta[alkuY][alkuX];
			int nappula = sijainti->getKoodi();
			Ruutu loppuruutu = siirto->getLoppuruutu();
			int loppuX = loppuruutu.getSarake();
			int loppuY = loppuruutu.getRivi();
			//if (siirto->getKaksoisaskel()) {
			//	_kaksoisaskelSarakkeella = alkuY;
			//	std::wcout << "kaksois\n";
			//}


			//if (siirto->getOhestalyonti()) {
			//	if (_siirtovuoro == 0) {
			//		_lauta[loppuX][alkuY] = nullptr;
			//		std::wcout << "ohesta\n";
			//	}
			//	else {
			//		_lauta[loppuX][alkuY] = nullptr;
			//	}
			//}

			if ((sijainti->getKoodi() == VS || sijainti->getKoodi() == MS) && abs(alkuX - loppuX) == 2) {
				_kaksoisaskelSarakkeella = alkuY;
			}

			if ((sijainti->getKoodi() == VS || sijainti->getKoodi() == MS) && (alkuY != loppuY) && (_lauta[loppuY][loppuX] == NULL)) {
				_lauta[loppuY][alkuX] = NULL;
			}

			if (siirto->_miksiKorotetaan != NULL) {
				_lauta[loppuY][loppuX] = siirto->_miksiKorotetaan;
				_lauta[alkuY][alkuX] = NULL;
			}

			switch (nappula) {
			case VK:
				_onkoValkeaKuningasLiikkunut = true;
				break;
			case MK:
				_onkoMustaKuningasLiikkunut = true;
				break;
			case VT:
				if (alkuX != 0 && alkuY != 0)
				{
					_onkoValkeaDTliikkunut = true;
					break;
				}
				_onkoValkeaKTliikkunut = true;
				break;
			case MT:
				if (alkuX != 0 && alkuY != 7)
				{
					_onkoMustaDTliikkunut = true;
					break;
				}
				_onkoMustaKTliikkunut = true;
				break;
			}
			_lauta[loppuY][loppuX] = _lauta[alkuY][alkuX];
			_lauta[alkuY][alkuX] = NULL;

			if (_siirtovuoro == 1) {
				_siirtovuoro = 0;
			}
			else {
				_siirtovuoro = 1;
			}
		}
		std::wcout << "kaksoisaskelSarakkeella: " << _kaksoisaskelSarakkeella << std::endl;
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

void Asema::setKaksoisaskelSarakkeella(int kaksoisaskel) {
	_kaksoisaskelSarakkeella = kaksoisaskel;
}

int Asema::getKaksoisaskelSarakkeella() {
	return _kaksoisaskelSarakkeella;
}

bool Asema::onkoRuutuUhattu(Ruutu ruutu, std::list<Siirto>& siirrot) {
	for (auto s : siirrot) {
		if (s.getLoppuruutu() == ruutu && s.getLyonti()) {
			return true;
		}
	}
}

Ruutu Asema::etsiKuningas(int vari) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0;j < 8; j++) {
			if (_lauta[i][j] != nullptr) {
				if ((_lauta[i][j]->getKoodi() == VK || _lauta[i][j]->getKoodi() == MK) && _lauta[i][j]->getVari() == vari) {
					return Ruutu(i, j);
				}
			}
		}
	}
}

void Asema::generoiRaakaSiirrot(std::list<Siirto>& lista) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Nappula* nappula = this->_lauta[i][j];
			if (nappula != nullptr) {
				if (_lauta[i][j]->getVari() == _siirtovuoro) {
					_lauta[i][j]->annaSiirrot(lista, &Ruutu(i, j), this, _siirtovuoro);
				}
			}
		}
	}
}

void Asema::annaLaillisetSiirrot(std::list<Siirto>& lista) {
	std::list<Siirto> lopulliset;

	generoiRaakaSiirrot(lista);
	Ruutu ruutu = etsiKuningas(this->getSiirtovuoro());
	for (auto s : lista) {
		Asema uusi;
		std::list<Siirto> lista2;
		uusi = *this;
		uusi.paivitaAsema(&s);

		uusi.generoiRaakaSiirrot(lista2);
		if (!onkoRuutuUhattu(ruutu, lista2)) {
			lopulliset.push_back(s);
		}
	}
	lista = lopulliset;
}

MinMaxPaluu Asema::Minimax(int syvyys)
{
	MinMaxPaluu paluuarvo;

	std::list<Siirto> siirrot;
	annaLaillisetSiirrot(siirrot);

	if (siirrot.size() == 0)
	{
		paluuarvo._evaluointiArvo = lopputulos();
		return paluuarvo;
	}

	if (syvyys == 0)
	{
		paluuarvo._evaluointiArvo = evaluoi();
		return paluuarvo;
	}

	paluuarvo._evaluointiArvo = (_siirtovuoro == 0 ? -1000000 : 1000000);
	for (auto s : siirrot)
	{

		Asema uusi_asema = *this;
		uusi_asema.paivitaAsema(&s);

		MinMaxPaluu arvo = uusi_asema.Minimax(syvyys - 1);

		if
			(
			(_siirtovuoro == 0 && arvo._evaluointiArvo > paluuarvo._evaluointiArvo) ||
				(_siirtovuoro == 1 && arvo._evaluointiArvo < paluuarvo._evaluointiArvo)
				)
		{
			paluuarvo._evaluointiArvo = arvo._evaluointiArvo;
			paluuarvo._parasSiirto = s;
		}
	}
	return paluuarvo;
}

double Asema::lopputulos()
{
	Nappula* kunkku = _siirtovuoro == 0 ? vk : mk;
	int kx, ky;
	for (int x = 0; x < 8; ++x)
	{
		for (int y = 0; y < 8; ++y)
		{
			if (_lauta[x][y] == kunkku)
			{
				kx = x;
				ky = y;
			}
		}
	}

	//if (onkoRuutuUhattu(Ruutu(kx, ky), lista))
	//	return 0; // tasapeli (patti)
	//else
		return _siirtovuoro == 0 ? -1000000 : 1000000;
}

double Asema::evaluoi()
{
	const double materiaaliKerroin = 1.0;
	double materiaali = laskeNappuloidenArvo(0) - laskeNappuloidenArvo(1);
	return materiaaliKerroin * materiaali;
}

double Asema::laskeNappuloidenArvo(int vari)
{
	double valkeaArvo = 0;
	double mustaArvo = 0;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if (this->_lauta[x][y] != NULL) {
				int nappulanNimi = this->_lauta[x][y]->getKoodi();
				if (nappulanNimi == VD)
					valkeaArvo += 9;
				if (nappulanNimi == VT)
					valkeaArvo += 5;
				if (nappulanNimi == VL)
					valkeaArvo += 3.25;
				if (nappulanNimi == VR)
					valkeaArvo += 3;
				if (nappulanNimi == VS)
					valkeaArvo += 1;
				if (nappulanNimi == MD)
					mustaArvo += 9;
				if (nappulanNimi == MT)
					mustaArvo += 5;
				if (nappulanNimi == ML)
					mustaArvo += 3.25;
				if (nappulanNimi == MR)
					mustaArvo += 3;
				if (nappulanNimi == MS)
					mustaArvo += 1;
			}
		}
	}
	if (vari == 0)
		return valkeaArvo;
	else
		return mustaArvo;
}