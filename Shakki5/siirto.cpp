#include <iostream>
#include "siirto.h"

Siirto::Siirto(Ruutu alkuruutu, Ruutu loppuruutu) {
	_alkuRuutu = alkuruutu;
	_loppuRuutu = loppuruutu;
}

// Poikkeussiirto linnoitusta varten
Siirto::Siirto(bool lyhytLinna, bool pitkaLinna) {
	_lyhytLinna = lyhytLinna;
	_pitkalinna = pitkaLinna;
}

Ruutu Siirto::getAlkuruutu() {
	return _alkuRuutu;
}

Ruutu Siirto::getLoppuruutu() {
	return _loppuRuutu;
}

bool Siirto::onkoLyhytLinna() {
	return _lyhytLinna;
}

bool Siirto::onkoPitkalinna() {
	return _lyhytLinna;
}


/*
public:
	Siirto(Ruutu, Ruutu);
	Siirto(bool lyhytLinna, bool pitkaLinna); // Poikkeussiirto linnoitusta varten
	Ruutu getAlkuruutu();
	Ruutu getLoppuruutu();
	bool onkoLyhytLinna();
	bool onkoPitkälinna();
private:
	Ruutu alkuRuutu;
	Ruutu loppuRuutu;
	int miksiKorotetaan = 0;
	bool lyhytLinna;
	bool pitkalinna;
*/