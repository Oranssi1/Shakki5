//
//  ruutu.cpp
//  Chess
//
//  Created by Nico Behnen on 23/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//

#include "ruutu.h"

Ruutu::Ruutu(int rivi, int sarake) {
	_sarake = sarake;
	_rivi = rivi;
}

int Ruutu::getRivi() {
	return _rivi;
}

int Ruutu::getSarake() {
	return _sarake;
}