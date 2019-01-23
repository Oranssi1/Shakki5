//
//  main.cpp
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
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
	Kayttoliittyma* kayttoliittyma = new Kayttoliittyma(asema);
	kayttoliittyma->piirraLauta();
	// Heinin koodi---------------------------------------------|
	return 0;
}
