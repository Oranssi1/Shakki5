//
//  nappula.cpp
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#include "nappula.h"
#include <iostream> // Heinin koodi

Nappula::Nappula(std::wstring unicode, int vari, int koodi) {
	_vari = vari;
	_koodi = koodi;
	_unicode = unicode;
}

void Nappula::setKoodi(int koodi) {
	_koodi = koodi;
}

int Nappula::getKoodi() {
	return _koodi;
}

void Nappula::setUnicode(std::wstring unicode) {
	_unicode = unicode;
}

std::wstring Nappula::getUnicode() {
	return _unicode;
}

void Nappula::setVari(int vari) {
	_vari = vari;
}

int Nappula::getVari() {
	return _vari;
}
