//
//  main.cpp
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#include "kayttoliittyma.h"
#include <iostream>
#include <Windows.h>
#include "Nappula.h"
#include "Asema.h"

int main() {

	Asema* asema = new Asema();
	asema->setSiirtovuoro(0);
	Kayttoliittyma* kayttoliittyma = new Kayttoliittyma(asema);
	while (true) {
		kayttoliittyma->piirraLauta();
		asema->paivitaAsema(kayttoliittyma->annaVastustajanSiirto());
	}

	return 0;
}
