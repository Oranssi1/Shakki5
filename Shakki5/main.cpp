//
//  main.cpp
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright ｩ 2019 B & J Corp. All rights reserved.
//

#include "kayttoliittyma.h"
#include <iostream>
#include <Windows.h>
#include "Nappula.h"
#include "Asema.h"
#include <list>

int main() {

	Asema asema;
	Kayttoliittyma ui(&asema);

	while (1)
	{
		ui.piirraLauta();
		std::list<Siirto> siirtolista;
		asema.annaLaillisetSiirrot(siirtolista);
		std::wcout << siirtolista.size() << " siirtoa:\n";

		MinMaxPaluu ai_valinta = asema.Minimax(2);
		std::wcout << "Minimax-arvo: " << ai_valinta._evaluointiArvo << "\n";
		Siirto ai_siirto = ai_valinta._parasSiirto;
		Ruutu alkuruutu = ai_siirto.getAlkuruutu();
		Ruutu loppuruutu = ai_siirto.getLoppuruutu();
		std::wcout << "(" << alkuruutu.getSarake() << ", " << alkuruutu.getRivi() << ") - ";
		std::wcout << "(" << loppuruutu.getSarake() << ", " << loppuruutu.getRivi() << ")\n";

		Siirto* s = ui.annaVastustajanSiirto();
		while (std::find(siirtolista.begin(), siirtolista.end(), s) == siirtolista.end())
		{
			s = ui.annaVastustajanSiirto();
		}
		asema.paivitaAsema(s);
	}

	return 0;



	//Asema* asema = new Asema();
	//asema->setSiirtovuoro(0);
	//Kayttoliittyma* kayttoliittyma = new Kayttoliittyma(asema);
	//std::list<Siirto> lista;
	//while (true) {
	//	kayttoliittyma->piirraLauta();
	//	lista.clear();
	//	asema->annaLaillisetSiirrot(lista);

	//	for (auto s : lista)
	//	{
	//		Ruutu ruutu;
	//		ruutu = s.getLoppuruutu();
	//		std::wcout << ruutu.getRivi() << "/" << ruutu.getSarake() << std::endl;

	//	}
	//	std::wcout << lista.size() << " laillista siirtoa\n";
	//	asema->paivitaAsema(kayttoliittyma->annaVastustajanSiirto());

	//}



	//return 0;




	//		asema->etsiKuningas(0);
//		asema->etsiKuningas(1);
//		std::wcout << "Halleluujaa: " << asema->onkoRuutuUhattu(Ruutu(3, 3), lista) << " halleluujaa" << std::endl;
//		asema->onkoRuutuUhattu(Ruutu(3,3), lista);
		//		asema->_lauta[3][3]->annaSiirrot(lista, &Ruutu(3,3), asema, 0);
//		asema->_lauta[3][3]->annaSiirrot(lista, &Ruutu(3, 3), asema, 0);
}
