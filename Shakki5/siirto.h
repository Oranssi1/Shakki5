#include "ruutu.h"

class Siirto {
public:
	Siirto(Ruutu, Ruutu);
	Siirto() {}
	Siirto(bool, bool); // Poikkeussiirto linnoitusta varten
	Ruutu getAlkuruutu();
	Ruutu getLoppuruutu();
	bool onkoLyhytLinna();
	bool onkoPitk�linna();
private:
	Ruutu _alkuRuutu;
	Ruutu _loppuRuutu;
	int miksiKorotetaan = 0;
	bool _lyhytLinna;
	bool _pitkalinna;
};
