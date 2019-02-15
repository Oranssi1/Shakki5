//
//  siirto.h
//  Chess
//
//  Created by Nico Behnen on 23/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//
#include "ruutu.h"
#pragma once

class Siirto {
public:
	Siirto(Ruutu, Ruutu);
	Siirto(Ruutu, Ruutu, bool);
	Siirto() {}
	Siirto(bool, bool); // Poikkeussiirto linnoitusta varten
	Ruutu getAlkuruutu();
	Ruutu getLoppuruutu();
	bool getLyonti();
	bool onkoLyhytLinna();
	bool onkoPitkaLinna();
private:
	Ruutu _alkuRuutu;
	Ruutu _loppuRuutu;
	bool _lyonti;
	int miksiKorotetaan = 0;
	bool _lyhytLinna;
	bool _pitkaLinna;
};
