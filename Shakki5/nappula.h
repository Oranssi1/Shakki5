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

enum {
	VT, VR, VL, VD, VK, VS,
	MT, MR, ML, MD, MK, MS
};

class Nappula {

private:
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
	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	)
	{
		int x = ruutu->getSarake();
		int y = ruutu->getRivi();
	
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
	}
};