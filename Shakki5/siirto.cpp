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
}

Siirto::Siirto(Ruutu alkuruutu, Ruutu loppuruutu, bool lyonti) {
	_alkuRuutu = alkuruutu;
	_loppuRuutu = loppuruutu;
	_lyonti = lyonti;
	_lyhytLinna = false;
	_pitkaLinna = false;
}

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
	return lyonti;
}
