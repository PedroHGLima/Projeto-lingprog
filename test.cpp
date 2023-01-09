#include "mundo.h"
#include <vector>
#include <algorithm>

Pais get_maior(Arvore<Pais> *arv) {
	Pais r = *(arv->get_valor());
	int maior = arv->get_valor()->get_populacao();
	if (arv->get_esq() != nullptr) {
		Pais p = get_maior(arv->get_esq());
		if (p.get_populacao() > maior) {
			maior = p.get_populacao();
			r = p;
		}
	}
	if (arv->get_dir() != nullptr) {
		Pais p = get_maior(arv->get_dir());
		if (p.get_populacao() > maior) {
			maior = p.get_populacao();
			r = p;
		}
	}
	return r;
}

std::vector<Pais> get_top(Arvore<Pais> *arv, std::vector<Pais> *v, int var) {
	if (arv != nullptr) {
		get_top(arv->get_esq(), v, var);
		if (arv->get_valor()->get_dado(var) > (*v).back().get_dado(var)) {
			(*v).back() = *(arv->get_valor());
			std::sort((*v).begin(), (*v).end(), [var](Pais a, Pais b) {
				return a.get_dado(var) > b.get_dado(var);
			});
		}
		get_top(arv->get_dir(), v, var);
	}
	return (*v);
}

std::vector<Pais> get_top(Arvore<Pais> *arv, int var) {
	std::vector<Pais> v(10);
	return get_top(arv, &v, var);
}


int main () {
	Mundo m;
	Arvore<Pais> paises = m.get_paises();

	//paises.imprimir();
	//std::cout << *(paises.get_valor()) << std::endl;
	//std::cout << get_maior(&paises) << std::endl;
	int var = 0;
	std::vector<Pais> top = get_top(&paises, var);
	for (size_t i=0; i<top.size(); i++) {
		std::cout << top[i] << std::endl;
	}

	return 0;
}

//g++ $(python3-config --cflags) test.cpp -o tst $(python3-config --ldflags --embed)
// Comando para compilar, lembre-se de adicionar os cpp adicionais, caso necessario
