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

Siirto annaVastustajanSiirto() {
	std::wstring siirto;
	std::wcout << "Anna vastustajan siirto: ";
	std::wcin >> siirto;
	std::wcout << siirto;
	Siirto* aapapp = new Siirto();
	return* aapapp;
}

