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

	Torni() {}

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
		int x = ruutu->getSarake();
		int y = ruutu->getRivi();

		for (int i = -2; i <= 2; i++) {
			for (int j = -2; j <= 2; j++) {
				int new_x = x + i;
				int new_y = y + j;
				if (new_y > 7 || new_x < 0 || new_x > 7 || new_y < 0) {
					break;
				}
				if (abs(i) + abs(j) == 3) {
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

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int new_x = x + i;
				int new_y = y + j;
				if (new_y > 7 || new_x < 0 || new_x > 7 || new_y < 0) {
					break;
				}

				if (abs(i) + abs(j) != 0) {

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
		int x = ruutu->getSarake();
		int y = ruutu->getRivi();
		int dy = 1;
		int new_y;

		Nappula* n = asema->_lauta[x][y];

		if (_vari == 1) {
			dy = -dy;
		}
		new_y = y + dy;
		n = asema->_lauta[x][new_y];

		if (n == nullptr) {
			lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
			n = asema->_lauta[x-1][new_y];
			if (n != nullptr) {
				if (n->getVari() != vari) {
					lista.push_back(Siirto(Ruutu(x, y), Ruutu(x-1, new_y)));
				}
			}
			n = asema->_lauta[x+1][new_y];
			if (n != nullptr) {
				if (n->getVari() != vari) {
					lista.push_back(Siirto(Ruutu(x, y), Ruutu(x+1, new_y)));
				}
			}
		}

		if (y == 1 && dy == 1 || y == 6 && dy == -1) {
			n = asema->_lauta[x][new_y + dy];
			if (n == nullptr) {
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y + dy)));
				n = asema->_lauta[x-1][new_y + dy];
				if (n != nullptr) {
					if (n->getVari() != vari) {
						lista.push_back(Siirto(Ruutu(x, y), Ruutu(x-1, new_y + dy)));
					}
				}
				n = asema->_lauta[x+1][new_y + dy];
				if (n != nullptr) {
					if (n->getVari() != vari) {
						lista.push_back(Siirto(Ruutu(x, y), Ruutu(x+1, new_y + dy)));
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


