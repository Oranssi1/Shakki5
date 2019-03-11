//
//  siirto.cpp
//  Chess
//
//  Created by Nico Behnen on 23/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//
#include <iostream>
#include "siirto.h"

Siirto::Siirto(Ruutu alkuruutu, Ruutu loppuruutu) {
	_alkuRuutu = alkuruutu;
	_loppuRuutu = loppuruutu;
	_lyhytLinna = false;
	_pitkaLinna = false;
	_lyonti = true;
	//_kaksoisaskel = false;
	//_ohestalyonti = false;
}

Siirto::Siirto(Ruutu alkuruutu, Ruutu loppuruutu, bool lyonti) {
	_alkuRuutu = alkuruutu;
	_loppuRuutu = loppuruutu;
	_lyonti = lyonti;
	_lyhytLinna = false;
	_pitkaLinna = false;
	//_kaksoisaskel = false;
	//_ohestalyonti = false;
}

//Siirto::Siirto(Ruutu alkuruutu, Ruutu loppuruutu, bool kaksoisaskel, bool ohestalyonti) {
//	_alkuRuutu = alkuruutu;
//	_loppuRuutu = loppuruutu;
//	_lyhytLinna = false;
//	_pitkaLinna = false;
//	_kaksoisaskel = kaksoisaskel;
//	_ohestalyonti = ohestalyonti;
//	if (kaksoisaskel) {
//		_lyonti = false;
//	}
//	else {
//		_lyonti = true;
//	}
//}

// Poikkeussiirto linnoitusta varten
Siirto::Siirto(bool lyhytLinna, bool pitkaLinna) {
	_lyhytLinna = lyhytLinna;
	_pitkaLinna = pitkaLinna;
}

Ruutu Siirto::getAlkuruutu() {
	return _alkuRuutu;
}

Ruutu Siirto::getLoppuruutu() {
	return _loppuRuutu;
}

bool Siirto::onkoLyhytLinna() {
	return _lyhytLinna;
}

bool Siirto::onkoPitkaLinna() {
	return _pitkaLinna;
}

bool Siirto::getLyonti() {
	return _lyonti;
}

//bool Siirto::getKaksoisaskel() {
//	return _kaksoisaskel;
//}
//
//bool Siirto::getOhestalyonti() {
//	return _ohestalyonti;
//}
