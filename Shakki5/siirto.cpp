#include <iostream>
#include "siirto.h"

Siirto::Siirto(Ruutu alkuruutu, Ruutu loppuruutu) {
	_alkuRuutu = alkuruutu;
	_loppuRuutu = loppuruutu;
}

Siirto(bool lyhytLinna, bool pitkaLinna) {
	_lyhytLinna = lyhytLinna
	_pitkalinna = pitkaLinna
} // Poikkeussiirto linnoitusta varten

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