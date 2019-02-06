//
//  asema.h
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#pragma once
#include "nappula.h"
#include "siirto.h"

//Lisätty ": public Nappula" Heinin koodista
class Asema : public Nappula {

public:
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
	
private:
	int _siirtovuoro;
	bool _onkoValkeaKuningasLiikkunut;
	bool _onkoMustaKuningasLiikkunut;
	bool _onkoValkeaDTliikkunut;
	bool _onkoValkeaKTliikkunut;
	bool _onkoMustaDTliikkunut;
	bool _onkoMustaKTliikkunut;
};

	// Heinin koodi
	// static Nappula* vk;
	// static Nappula* vd;
	// static Nappula* vt;
	// static Nappula* vl;
	// static Nappula* vr;
	// static Nappula* vs;

	// static Nappula* mk;
	// static Nappula* md;
	// static Nappula* mt;
	// static Nappula* ml;
	// static Nappula* mr;
	// static Nappula* ms;


