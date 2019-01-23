//
//  kayttoliittyma.h
//  Chess
//
//  Created by Nico Behnen on 18/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#ifndef kayttoliittyma_h
#define kayttoliittyma_h
#include "asema.h"

class Kayttoliittyma {

public:
	Asema* asema;
	Kayttoliittyma(Asema* asema);
	void piirraLauta();
};

#endif /* kayttoliittyma_h */
