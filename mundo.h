#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "arvore.h"
#include "pais.h"

class Mundo {
    friend std::ostream &operator<<(std::ostream &, Mundo&);
    public:
        Mundo();
        Arvore<Pais> get_paises();
        int get_n_paises();
        void set_paises();

    private:
        Arvore<Pais> paises;
        int n_paises;
};
