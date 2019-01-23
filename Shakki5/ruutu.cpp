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