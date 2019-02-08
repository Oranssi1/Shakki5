//
//  kayttoliittyma.cpp
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#include "kayttoliittyma.h"
#include <iostream>
#include <string>

using namespace std;

Asema* _asema;
Kayttoliittyma::Kayttoliittyma(Asema* asema) {
	_asema = asema;

}

void Kayttoliittyma::piirraLauta() {
	_setmode(_fileno(stdout), _O_U16TEXT);

	for (int y = 8; y > 0; y--) {
		if (y % 2 == 0) {
			for (int x = 0; x < 8; x++) {
				if (x % 2 == 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_GREEN);
					std::wcout << " ";
				}

				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_BLUE);
					std::wcout << " ";
				}

				if (_asema->_lauta[x][y-1] == nullptr) {
					std::wcout << L"  ";
				}
				else {
					std::wcout << _asema->_lauta[x][y-1]->getUnicode();
					std::wcout << L" ";
				}
			}
		}

		else {
			for (int x = 0; x < 8; x++) {
				if (x % 2 == 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_BLUE);
					std::wcout << " ";
				}

				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_GREEN);
					std::wcout << " ";
				}

				if (_asema->_lauta[x][y-1] == nullptr) {
					std::wcout << L"  ";
				}
				else {
					std::wcout << _asema->_lauta[x][y-1]->getUnicode();
					std::wcout << L" ";
				}
			}
		}
		std::wcout << std::endl;
	}
}

Siirto* Kayttoliittyma::annaVastustajanSiirto() {
	std::wstring syote;
	bool virhe = 0;
	do {
		virhe = 0;
		std::wcout << "Anna vastustajan siirto: ";
		std::wcin >> syote;

		if (syote == L"O-O") {
			Siirto* temp = new Siirto(1, 0);
			return temp;
		}

		else if (syote == L"O-O-O") {
			Siirto* temp = new Siirto(0, 1);
			return temp;
		}

		int pituus = 0;
		while (syote[pituus] != '\0') {
			pituus++;
		}

		if (pituus == 6) {
			for (int i = 0; i < 5; i++) {
				syote[i] = syote[i + 1];
			}
		}

		if (pituus < 5) {
			virhe = 1;
		}
		else {
			syote[0] = syote[0] - 'a';
			syote[1] = syote[1] - '0';
			syote[3] = syote[3] - 'a';
			syote[4] = syote[4] - '0';
		}

		if (syote[0] > 7 || syote[1] > 7 || syote[3] > 7 || syote[4] > 7 || syote[0] < 0 || syote[1] < 0 || syote[3] < 0 || syote[4] < 0)
		{
			virhe = 1;
			std::wcout << "Virheellinen syöte" << std::endl;
		}

	} while (virhe);

	Ruutu alkuruutu = Ruutu((int)syote[1] - 1, (int)syote[0]);
	Ruutu loppuruutu = Ruutu((int)syote[4] - 1, (int)syote[3]);
	Siirto* siirto = new Siirto(alkuruutu, loppuruutu);
	return siirto;
}