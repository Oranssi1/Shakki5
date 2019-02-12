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
		asema->annaLaillisetSiirrot(lista);
//		asema->_lauta[3][3]->annaSiirrot(lista, &Ruutu(3,3), asema, 0);
//		asema->_lauta[3][3]->annaSiirrot(lista, &Ruutu(3, 3), asema, 0);

//		asema->paivitaAsema(kayttoliittyma->annaVastustajanSiirto());
//	}

		for (auto s : lista)
		{
			Ruutu ruutu;
			ruutu = s.getLoppuruutu();
			std::wcout << ruutu.getRivi() << "/" << ruutu.getSarake() << std::endl;

		}

	return 0;
}
