//
//  ruutu.h
//  Chess
//
//  Created by Nico Behnen on 23/01/2019.
//  Copyright © 2019 B & J Corp. All rights reserved.
//
#pragma once

class Ruutu{
public:
	Ruutu(int, int);
	Ruutu() {};
	int getRivi();
	int getSarake();
private:
	int _sarake;
	int _rivi;
};
