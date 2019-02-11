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
#include <list>

int main() {

	Asema* asema = new Asema();
	asema->setSiirtovuoro(0);
	Kayttoliittyma* kayttoliittyma = new Kayttoliittyma(asema);
	std::list<Siirto> lista;
//	while (true) {
		kayttoliittyma->piirraLauta();
		asema->_lauta[3][3]->annaSiirrot(lista, &Ruutu(3,3), asema, 1);
//		asema->paivitaAsema(kayttoliittyma->annaVastustajanSiirto());
//	}
		std::wcout << lista.size();
		for (int i = 0; i < 15; i++) {
			Ruutu ruutu;
			Siirto siirto;
			ruutu = lista.begin(i)->getLoppuRuutu;
			std::wcout << "testi";
		}

	return 0;
}
