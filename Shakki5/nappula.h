//
//  nappula.h
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#pragma once
#include <string>
#include <iostream>
#include <list>
#include "asema.h"
#include <stdlib.h>

enum {
	VT, VR, VL, VD, VK, VS,
	MT, MR, ML, MD, MK, MS
};

class Nappula {

protected:
	std::wstring _unicode;
	int _vari;
	int _koodi;

public:
	Nappula(std::wstring, int, int);
	Nappula() {};

	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	) = 0;

	void setKoodi(int);
	int getKoodi();
	void setUnicode(std::wstring);
	std::wstring getUnicode();
	void setVari(int);
	int getVari();
	void lisaaSotilaanKorotukset(Siirto*, std::list<Siirto>& lista, Asema*);

};

class Torni : virtual public Nappula {
public:

	Torni(std::wstring unicode, int vari, int koodi) {
		_vari = vari;
		_koodi = koodi;
		_unicode = unicode;
	}

	Torni() {}

	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	)
	{
		int x = ruutu->getRivi();
		int y = ruutu->getSarake();
	
		//oikea
		for (int dx = 1; dx <= 7; dx++) {
			int new_x = x + dx;
			if (new_x > 7) {
				break;
			}

			Nappula* n = asema->_lauta[new_x][y];

			if (n == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
				continue;
			}
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
			}

			break;
		}

		//vasen
		for (int dx = 1; dx <= 7; dx++) {
			int new_x = x - dx;
			if (new_x < 0) {
				break;
			}

			Nappula* n = asema->_lauta[new_x][y];

			if (n == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
				continue;
			}
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
			}

			break;
		}

		//ylös
		for (int dy = 1; dy <= 7; dy++) {
			int new_y = y + dy;
			if (new_y > 7) {
				break;
			}

			Nappula* n = asema->_lauta[x][new_y];

			if (n == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
				continue;
			}
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
			}

			break;
		}

		//alas
		for (int dy = 1; dy <= 7; dy++) {
			int new_y = y - dy;
			if (new_y < 0) {
				break;
			}

			Nappula* n = asema->_lauta[x][new_y];

			if (n == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
				continue;
			}
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
			}

			break;
		}
	}
};

class Lahetti : virtual public Nappula {
public:

	Lahetti(std::wstring unicode, int vari, int koodi) {
		_vari = vari;
		_koodi = koodi;
		_unicode = unicode;
	}

	Lahetti() {}

	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	)
	{
		int x = ruutu->getRivi();
		int y = ruutu->getSarake();

		for (int i = 1; i <= 7; i++) {
			int new_x = x + i;
			int new_y = y + i;
			if (new_y > 7 || new_x > 7) {
				break;
			}

			Nappula* n = asema->_lauta[new_x][new_y];

			if (n == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
				continue;
			}
			if (n->getVari() != vari) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
			}

			break;
		}

		for (int i = 1; i <= 7; i++) {
			int new_x = x + i;
			int new_y = y - i;
			if (new_y < 0 || new_x > 7) {
				break;
			}

			Nappula* n = asema->_lauta[new_x][new_y];

			if (n == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
				continue;
			}
			if (n->getVari() != vari) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
			}

			break;
		}

		for (int i = 1; i <= 7; i++) {
			int new_x = x - i;
			int new_y = y - i;
			if (new_y < 0 || new_x < 0) {
				break;
			}

			Nappula* n = asema->_lauta[new_x][new_y];

			if (n == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
				continue;
			}
			if (n->getVari() != vari) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
			}

			break;
		}

		for (int i = 1; i <= 7; i++) {
			int new_x = x - i;
			int new_y = y + i;
			if (new_y > 7 || new_x < 0) {
				break;
			}

			Nappula* n = asema->_lauta[new_x][new_y];

			if (n == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
				continue;
			}
			if (n->getVari() != vari) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
			}

			break;
		}
	}
};

class Ratsu : public Nappula {
public: 
	Ratsu(std::wstring unicode, int vari, int koodi) {
		_vari = vari;
		_koodi = koodi;
		_unicode = unicode;
	}

	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	)
	{
		int x = ruutu->getRivi();
		int y = ruutu->getSarake();

		for (int i = -2; i <= 2; i++) {
			for (int j = -2; j <= 2; j++) {
				int new_x = x + i;
				int new_y = y + j;
				if (new_y <= 7 && new_x >= 0 && new_x <= 7 && new_y >= 0) {
					if (abs(i) + abs(j) == 3) {
						Nappula* n = asema->_lauta[new_x][new_y];

						if (n == nullptr) {
							lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
							continue;
						}
						if (n->getVari() != vari) {
							lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
						}
					}
				}
			}
		}
	}
};

class Kuningas : public Nappula {
public:
	Kuningas(std::wstring unicode, int vari, int koodi) {
		_vari = vari;
		_koodi = koodi;
		_unicode = unicode;
	}

	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	)
	{
		std::list<Siirto> vihollislista;

		int vuorojuttu = 1;
		if (asema->getSiirtovuoro() == 1) {
			vuorojuttu = 0;
		}
		

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				Nappula* nappula = asema->_lauta[i][j];
				if (nappula != nullptr) {
					if (asema->_lauta[i][j]->getVari() == vuorojuttu) {
						asema->_lauta[i][j]->annaSiirrot(lista, &Ruutu(i, j), asema, vuorojuttu);
					}
				}
			}
		}

		if (asema->getSiirtovuoro() == 1) {
			if (!asema->getOnkoMustaKuningasLiikkunut() && !asema->getOnkoMustaKTliikkunut() && !asema->onkoRuutuUhattu(asema->etsiKuningas(1), vihollislista) && !asema->onkoRuutuUhattu(Ruutu(2, 7), vihollislista)) { //musta lyhytlinna
				lista.push_back(Siirto(1, 0));
			}
			if (!asema->getOnkoMustaKuningasLiikkunut() && !asema->getOnkoMustaDTliikkunut() && !asema->onkoRuutuUhattu(asema->etsiKuningas(1), vihollislista) && !asema->onkoRuutuUhattu(Ruutu(4, 7), vihollislista)) { //musta pitkälinna
				lista.push_back(Siirto(0, 1));
			}
		}

		else if (asema->getSiirtovuoro() == 0) {
			if (!asema->getOnkoValkeaKuningasLiikkunut() && !asema->getOnkoValkeaKTliikkunut() && !asema->onkoRuutuUhattu(asema->etsiKuningas(0), vihollislista) && !asema->onkoRuutuUhattu(Ruutu(5, 0), vihollislista)) { //valkea lyhytlinna
				lista.push_back(Siirto(1, 0));
			}
			if (!asema->getOnkoValkeaKuningasLiikkunut() && !asema->getOnkoValkeaDTliikkunut() && !asema->onkoRuutuUhattu(asema->etsiKuningas(0), vihollislista) && !asema->onkoRuutuUhattu(Ruutu(3, 0), vihollislista)) { //valkea pitkälinna
				lista.push_back(Siirto(0, 1));
			}
		}

		int x = ruutu->getRivi();
		int y = ruutu->getSarake();

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int new_x = x + i;
				int new_y = y + j;
				if (new_y <= 7 && new_x >= 0 && new_x <= 7 && new_y >= 0) {
					if (abs(i) + abs(j) != 0) {

						Nappula* n = asema->_lauta[new_x][new_y];

						if (n == nullptr) {
							lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
							continue;
						}
						if (n->getVari() != vari) {
							lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
						}
					}
				}
			}
		}
	}
};

class Sotilas : public Nappula {
public:
	Sotilas(std::wstring unicode, int vari, int koodi) {
		_vari = vari;
		_koodi = koodi;
		_unicode = unicode;
	}

	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	)
	{
		int x = ruutu->getRivi();
		int y = ruutu->getSarake();
		int dy = 1; // askel muutos
		int new_y;

		Nappula* n = asema->_lauta[x][y]; 

		if (_vari == 1) { // jos musta, niin askel muutos negatiivinen
			dy = -dy;
		}

		new_y = y + dy; // askel muutos lisätty y arvoon

		if (new_y < 8 && new_y > -1) { // jos y on kentällä (0-7)
			n = asema->_lauta[x][new_y]; // ruutu mihin nappula tulee liikkumaan

			// Normaali liikkuminen

			if (n == nullptr) {  // onko ruutu tyhjä
				if (new_y == 0 || new_y == 7) { // onko ruutu jompi kumpi päätyruuduista
					lisaaSotilaanKorotukset(&Siirto(Ruutu(x, y), Ruutu(x, new_y)), lista, asema);
				}
				else {
					lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y), 0)); // normaali askel
				}

				// Syönti (valkoisista katsottuna vasen puoli)

				if (x - 1 > -1) { // meneekö A laidasta ristiin syönti yli
					n = asema->_lauta[x-1][new_y]; // ruutu johon nappula tulee liikkumaan
					if (n != nullptr) { // jos ei tyhjä ruutu
						if (n->getVari() != vari) {
							lista.push_back(Siirto(Ruutu(x, y), Ruutu(x-1, new_y)));
						}
					}
				}

				// Syönti (valkoisista katsottuna oikea puoli)
			
				if (x+1 < 8) {
					n = asema->_lauta[x+1][new_y];
					if (n != nullptr) {
						if (n->getVari() != vari) {
							lista.push_back(Siirto(Ruutu(x, y), Ruutu(x+1, new_y)));
						}
					}
				}
			}

			// Kaksoisaskel

			if (y == 1 && dy == 1 || y == 6 && dy == -1 && new_y + dy < 8 && new_y + dy > -1) {
				n = asema->_lauta[x][new_y + dy];
				if (n == nullptr) {
					lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y + dy), 0));
				}
			}

			// Ohestalyönnit

			if (this->getVari() == 0 && y == 4) {
				n = asema->_lauta[y][x - 1];
				if (n != nullptr) {
					if (n->getKoodi() == MS && asema->getKaksoisaskelSarakkeella() == x-1) {
						lista.push_back(Siirto(Ruutu(x, y), Ruutu(x - 1, y + 1)));
					}
				}
				n = asema->_lauta[y][x + 1];
				if (n != nullptr) {
					if (n->getKoodi() == MS && asema->getKaksoisaskelSarakkeella() == x + 1) {
						lista.push_back(Siirto(Ruutu(x, y), Ruutu(x + 1, y + 1)));
					}
				}
			}
			if (this->getVari() == 1 && y == 3) {
				n = asema->_lauta[y][x - 1];
				if (n != nullptr) {
					if (n->getKoodi() == VS && asema->getKaksoisaskelSarakkeella() == x - 1) {
						lista.push_back(Siirto(Ruutu(x, y), Ruutu(x - 1, y - 1)));
					}
				}
				n = asema->_lauta[y][x + 1];
				if (n != nullptr) {
					if (n->getKoodi() == VS && asema->getKaksoisaskelSarakkeella() == x + 1) {
						lista.push_back(Siirto(Ruutu(x, y), Ruutu(x + 1, y - 1)));
					}
				}
			}
		}
	}
};

class Daami : public Torni, public Lahetti {
public:
	Daami(std::wstring unicode, int vari, int koodi) {
		_vari = vari;
		_koodi = koodi;
		_unicode = unicode;
	}

	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	) 
	{
		Torni::annaSiirrot(lista, ruutu, asema, vari);
		Lahetti::annaSiirrot(lista, ruutu, asema, vari);
	}
};


