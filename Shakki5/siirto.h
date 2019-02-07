#include "ruutu.h"
#pragma once

class Siirto {
public:
	Siirto(Ruutu, Ruutu);
	Siirto() {}
	Siirto(bool, bool); // Poikkeussiirto linnoitusta varten
	Ruutu getAlkuruutu();
	Ruutu getLoppuruutu();
	bool onkoLyhytLinna();
	bool onkoPitkaLinna();
private:
	Ruutu _alkuRuutu;
	Ruutu _loppuRuutu;
	int miksiKorotetaan = 0;
	bool _lyhytLinna;
	bool _pitkaLinna;
};
