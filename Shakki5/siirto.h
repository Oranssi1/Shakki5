//
//  siirto.h
//  Chess
//
//  Created by Nico Behnen on 23/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//
#include "ruutu.h"
#pragma once

class Nappula;

class Siirto {
public:
	Siirto(Ruutu, Ruutu);
	Siirto(Ruutu, Ruutu, bool);
//	Siirto(Ruutu, Ruutu, bool, bool);

	Siirto() {}
	Siirto(bool, bool); // Poikkeussiirto linnoitusta varten
	Ruutu getAlkuruutu();
	Ruutu getLoppuruutu();
	bool getLyonti();
	bool onkoLyhytLinna();
	bool onkoPitkaLinna();
	Nappula* _miksiKorotetaan = 0;
	//bool getKaksoisaskel();
	//bool getOhestalyonti();

private:
	Ruutu _alkuRuutu;
	Ruutu _loppuRuutu;
	bool _lyonti;
	bool _lyhytLinna;
	bool _pitkaLinna;
	//bool _kaksoisaskel;
	//bool _ohestalyonti;
};
