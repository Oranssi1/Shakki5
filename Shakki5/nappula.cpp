//
//  nappula.cpp
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright � 2019 B & J Corp. All rights reserved.
//

#include "nappula.h"
#include <iostream>

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

void Sotilas::lisaaSotilaanKorotukset(Siirto* siirto, std::list<Siirto>& lista, Asema* asema) {
	if (siirto->getLoppuruutu().getRivi() == 7) {
		// valkea korottaa
		Siirto daamiksi = *siirto;
		daamiksi._miksikorotetaan = asema->vd;
		lista.push_back(daamiksi);

		Siirto torniksi = *siirto;
		torniksi._miksikorotetaan = asema->vt;
		lista.push_back(torniksi);

		Siirto lahetiksi = *siirto;
		lahetiksi._miksikorotetaan = asema->vl;
		lista.push_back(lahetiksi);

		Siirto ratsuksi = *siirto;
		ratsuksi._miksikorotetaan = asema->vr;
		lista.push_back(ratsuksi);
	}
	else if (siirto->getLoppuruutu().getRivi() == 0) {
		// musta korottaa
		Siirto daamiksi = *siirto;
		daamiksi._miksikorotetaan = asema->md;
		lista.push_back(daamiksi);

		Siirto torniksi = *siirto;
		torniksi._miksikorotetaan = asema->mt;
		lista.push_back(torniksi);

		Siirto lahetiksi = *siirto;
		lahetiksi._miksikorotetaan = asema->ml;
		lista.push_back(lahetiksi);

		Siirto ratsuksi = *siirto;
		ratsuksi._miksikorotetaan = asema->mr;
		lista.push_back(ratsuksi);
	}
}
