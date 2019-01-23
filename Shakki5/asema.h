//
//  asema.h
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#pragma once
#include "nappula.h"

//Lisätty ": public Nappula" Heinin koodista
class Asema : public Nappula {

public:
	//Konstruktori luo alkuaseman laudalle
	Asema();
	Nappula* lauta[8][8];

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
};

