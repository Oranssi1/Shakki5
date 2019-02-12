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

class Nappula;


class Asema {

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
	void annaLaillisetSiirrot(std::list<Siirto>&);
	
private:
	int _siirtovuoro;
	bool _onkoValkeaKuningasLiikkunut;
	bool _onkoMustaKuningasLiikkunut;
	bool _onkoValkeaDTliikkunut;
	bool _onkoValkeaKTliikkunut;
	bool _onkoMustaDTliikkunut;
	bool _onkoMustaKTliikkunut;
};


