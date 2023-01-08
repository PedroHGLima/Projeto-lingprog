#include "mundo.h"

int main () {
	Mundo m;
	Arvore<Pais> paises = m.get_paises();

	paises.imprimir();

	return 0;
}

//g++ $(python3-config --cflags) test.cpp -o tst $(python3-config --ldflags --embed)
