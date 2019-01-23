//
//  nappula.cpp
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#include "nappula.h"


std::wstring _unicode;
int _vari; // valkea = 0, musta = 1
int _koodi; // VT, VR, MT tms.

Nappula::Nappula() {}

Nappula::Nappula(std::wstring unicode, int vari, int koodi) {
	_vari = vari;
	_koodi = koodi;
	_unicode = unicode;
}

void setKoodi(int koodi) {
	_koodi = koodi;
}

int getKoodi() {
	return _koodi;
}

void setUnicode(std::wstring unicode) {
	_unicode = unicode;
}

std::wstring getUnicode();

void setVari(int vari) {
	_vari = vari;
}

int getVari() {
	return _vari;
}
