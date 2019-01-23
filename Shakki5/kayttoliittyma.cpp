//
//  kayttoliittyma.cpp
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#include "kayttoliittyma.h"
#include <iostream>


Asema* _asema;
Kayttoliittyma::Kayttoliittyma(Asema* asema) {
	_asema = asema;
}

void piirraLauta() {
	std::wcout << L"hello!";
}

//    for (int i = 0; i < 8; i++) {
//        for (int j = 0; j < 8; j++) {
//            _asema->lauta[i][j] = NULL;
//        }
//    }
//
//    _asema->lauta[0][0] = new Nappula(L"\u2656", 0, VT);
//    _asema->lauta[1][0] = new Nappula(L"\u2658", 0, VR);
//    _asema->lauta[2][0] = new Nappula(L"\u2657", 0, VL);
//    _asema->lauta[3][0] = new Nappula(L"\u2655", 0, VD);
//    _asema->lauta[4][0] = new Nappula(L"\u2654", 0, VK);
//    _asema->lauta[0][1] = new Nappula(L"\u2659", 0, VS);
//    _asema->lauta[5][0] = _asema->lauta[2][0];
//    _asema->lauta[6][0] = _asema->lauta[1][0];
//    _asema->lauta[7][0] = _asema->lauta[0][0];
//
//    _asema->lauta[0][7] = new Nappula(L"\u265C", 1, MT);
//    _asema->lauta[1][7] = new Nappula(L"\u265E", 1, MR);
//    _asema->lauta[2][7] = new Nappula(L"\u265D", 1, ML);
//    _asema->lauta[3][7] = new Nappula(L"\u265A", 1, MK);
//    _asema->lauta[4][7] = new Nappula(L"\u265B", 1, MD);
//    _asema->lauta[0][6] = new Nappula(L"\u265F", 1, MS);
//    _asema->lauta[5][7] = _asema->lauta[2][7];
//    _asema->lauta[6][7] = _asema->lauta[1][7];
//    _asema->lauta[7][7] = _asema->lauta[0][7];
//
//    for (int i = 0; i < 8; i++) {
//        _asema->lauta[i][1] = _asema->lauta[1][1];
//        _asema->lauta[i][6] = _asema->lauta[0][6];
//    }

//    std::wcout << _asema->lauta[0][0]->getVari();



/*
 VK, L"\u2654"
 VD, L"\u2655"
 VT, L"\u2656"
 VL, L"\u2657"
 VR, L"\u2658"
 VS, L"\u2659"
 MK, L"\u265A"
 MD, L"\u265B"
 MT, L"\u265C"
 ML, L"\u265D"
 MR, L"\u265E"
 MS, L"\u265F"
 */
