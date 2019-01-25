//
//  main.cpp
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright � 2019 B & J Corp. All rights reserved.
//

#include "kayttoliittyma.h"
// Heinin koodi-------------|
#include <iostream>
#include <Windows.h>
#include "Nappula.h"
#include "Asema.h"
// Heinin koodi-------------|

int main() {
	// Heinin koodi---------------------------------------------|
	Asema* asema = new Asema();
	asema->setSiirtovuoro(0);
	Kayttoliittyma* kayttoliittyma = new Kayttoliittyma(asema);
//	kayttoliittyma->annaVastustajanSiirto();
	kayttoliittyma->piirraLauta();
	// Heinin koodi---------------------------------------------|
	asema->paivitaAsema(kayttoliittyma->annaVastustajanSiirto());
	kayttoliittyma->piirraLauta();

	return 0;
}
