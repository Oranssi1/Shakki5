//
//  kayttoliittyma.h
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#include "asema.h"
// Heinin koodi------|
#include <Windows.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <utility>
#include <string>
#include "siirto.h"
//-------------------|

class Kayttoliittyma {

public:
	Asema* asema;
	Kayttoliittyma(Asema* asema);
	void piirraLauta();
	Siirto* annaVastustajanSiirto();
};

