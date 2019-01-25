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
	// Heinin koodi--------------------------------------------------------------------------------------------------------|
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

				if (_asema->lauta[x][y-1] == nullptr) {
					std::wcout << L"  ";
				}
				else {
					std::wcout << _asema->lauta[x][y-1]->getUnicode();
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

				if (_asema->lauta[x][y-1] == nullptr) {
					std::wcout << L"  ";
				}
				else {
					std::wcout << _asema->lauta[x][y-1]->getUnicode();
					std::wcout << L" ";
				}
			}
		}
		std::wcout << std::endl;
	}
	// Heinin koodi--------------------------------------------------------------------------------------------------------|
}

//vaihda siirroksi
Siirto Kayttoliittyma::annaVastustajanSiirto() {
	std::wstring syote;
	std::wcout << "Anna vastustajan siirto: ";

	std::wcin >> syote;

	if (syote == L"O-O") {
		return Siirto(1, 0);
	}
	else if (syote == L"O-O-O") {
		return Siirto(0, 1);
	} 

	int pituus = 0;
	while (syote[pituus] != '\0') {
		pituus++;
	}
	if (pituus == 5) {
		syote[0] = syote[0] - 'a';
		syote[1] = syote[1] - '0';
		syote[3] = syote[3] - 'a';
		syote[4] = syote[4] - '0';
		Ruutu alkuruutu = Ruutu((int)syote[1] - 1, (int)syote[0]);
		Ruutu loppuruutu = Ruutu((int)syote[4] - 1, (int)syote[3]);
		std::wcout << (int)syote[0] << (int)syote[1] - 1 << "-";
		std::wcout << (int)syote[3] << (int)syote[4] - 1 << std::endl;
		return Siirto(alkuruutu, loppuruutu);
	}

	syote[1] = syote[1] - 'a';
	syote[2] = syote[2] - '0';
	syote[4] = syote[4] - 'a';
	syote[5] = syote[5] - '0';
	Ruutu alkuruutu = Ruutu((int)syote[2] - 1, (int)syote[1]);
	Ruutu loppuruutu = Ruutu((int)syote[5] - 1, (int)syote[4]);
	std::wcout << (int)syote[1] << (int)syote[2] - 1 << "-";
	std::wcout << (int)syote[4] << (int)syote[5] - 1 << std::endl;
	return Siirto(alkuruutu, loppuruutu);
}




