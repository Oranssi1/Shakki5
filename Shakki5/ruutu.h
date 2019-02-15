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
	int getRivi() const;
	int getSarake() const;
	friend bool operator== (Ruutu & ruutu1, Ruutu & ruutu2);
	
	bool vertaa(const Ruutu& ruutu) {
		if (_sarake == ruutu.getSarake() && _rivi == ruutu.getRivi()) {
			return true;
		}
		return false;
	}

	bool operator== (const Ruutu& ruutu)
	{
		return vertaa(ruutu);
	}

private:
	int _sarake;
	int _rivi;
};



