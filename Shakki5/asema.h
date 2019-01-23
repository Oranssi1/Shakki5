//
//  asema.h
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#ifndef asema_h
#define asema_h
#include "nappula.h"

class Asema {

public:
	//Konstruktori luo alkuaseman laudalle
	Asema();
	Nappula* lauta[8][8];
};

#endif /* asema_h */
