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

};

class Torni : virtual public Nappula {
public:

	Torni(std::wstring unicode, int vari, int koodi) {
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
		int x = ruutu->getSarake();
		int y = ruutu->getRivi();
	
		//oikea
		for (int dx = 1; dx <= 7; dx++) {
			int new_x = x + dx;
			if (new_x > 7) {
				break;
			}

			Nappula* n = asema->_lauta[new_x][y];

			if (n == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
				std::wcout << new_x << " " << y << std::endl;
				continue;
			}
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
				std::wcout << new_x << " " << y << std::endl;
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
				std::wcout << new_x << " " << y << std::endl;
				continue;
			}
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
				std::wcout << new_x << " " << y << std::endl;
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
				std::wcout << x << " " << new_y << std::endl;
				continue;
			}
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
				std::wcout << x << " " << new_y << std::endl;
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
				std::wcout << x << " " << new_y << std::endl;
				continue;
			}
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
				std::wcout << x << " " << new_y << std::endl;
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

	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	)
	{
		int x = ruutu->getSarake();
		int y = ruutu->getRivi();

		for (int i = 1; i <= 7; i++) {
			int new_x = x + i;
			int new_y = y + i;
			if (new_y > 7 || new_x > 7) {
				break;
			}

			Nappula* n = asema->_lauta[new_x][new_y];

			if (n == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
				std::wcout << "asd1";
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
				std::wcout << "asd2";
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
				std::wcout << "asd3";
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
				std::wcout << "asd4";
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
		int x = ruutu->getSarake();
		int y = ruutu->getRivi();

		for (int i = -2; i <= 2; i++) {
			for (int j = -2; j <= 2; j++) {
				int new_x = x + i;
				int new_y = y + j;
				if (new_y > 7 || new_x < 0) {
					break;
				}
				if (abs(new_x) + abs(new_y) != 3) {
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
		int x = ruutu->getSarake();
		int y = ruutu->getRivi();

		if (x + 1 <= 7 && x - 1 > 0 && y + 1 <= 7 && y - 1 > 0) {
			Nappula* n1 = asema->_lauta[x+1][y];
			Nappula* n2 = asema->_lauta[x-1][y];
			Nappula* n3 = asema->_lauta[x][y+1];
			Nappula* n4 = asema->_lauta[x][y-1];

			if (n1 == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x+1, y)));
			}
			else if (n1->getVari() != vari) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x+1, y)));
			}

			if (n2 == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x-1, y)));
			}
			else if (n2->getVari() != vari) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x-1, y)));
			}

			if (n3 == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, y+1)));
				}
			else if (n3->getVari() != vari) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, y+1)));
			}

			if (n4 == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, y-1)));
			}
			else if (n4->getVari() != vari) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, y-1)));
			}
		}
	}
};

// for (int i = -1; i <= 1; i++) {
// 	for (int j = -1; j <= 1; j++) {
// 		int new_x = x + i;
// 		int new_y = y + j;
// 		if (new_y > 7 || new_x < 0) {
// 			break;
// 		}
// 		if (abs(i) + abs(j) != 1) {
// 			break;
// 		}

// 		Nappula* n = asema->_lauta[new_x][new_y];
			
// 		if (n == nullptr) {
// 			lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
// 			continue;
// 		}
// 		if (n->getVari() != vari) {
// 			lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
// 		}

// 		break;

// 	}
// }

