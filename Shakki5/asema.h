//
//  asema.h
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#pragma once
//#include "nappula.h"
#include "siirto.h"
#include <list>

class Nappula;


class Asema {

public:
	static Nappula *vk, *vd, *vt, *vl, *vr, *vs;
	static Nappula *mk, *md, *mt, *ml, *mr, *ms;
	Asema();
	Nappula* _lauta[8][8];
	
	void paivitaAsema(Siirto* siirto);
	int getSiirtovuoro();
	void setSiirtovuoro(int vari);
	bool getOnkoValkeaKuningasLiikkunut();
	bool getOnkoMustaKuningasLiikkunut();
	bool getOnkoValkeaDTliikkunut();
	bool getOnkoValkeaKTliikkunut();
	bool getOnkoMustaDTliikkunut();
	bool getOnkoMustaKTliikkunut();
	void setKaksoisaskelSarakkeella(int kaksoisaskel);
	int getKaksoisaskelSarakkeella();
	void generoiRaakaSiirrot(std::list<Siirto>&);
	void annaLaillisetSiirrot(std::list<Siirto>&);
	bool onkoRuutuUhattu(Ruutu ruutu, std::list<Siirto>& siirrot);
	Ruutu etsiKuningas(int);

	
private:
	int _siirtovuoro;
	bool _onkoValkeaKuningasLiikkunut;
	bool _onkoMustaKuningasLiikkunut;
	bool _onkoValkeaDTliikkunut;
	bool _onkoValkeaKTliikkunut;
	bool _onkoMustaDTliikkunut;
	bool _onkoMustaKTliikkunut;
	int _kaksoisaskelSarakkeella;
};


