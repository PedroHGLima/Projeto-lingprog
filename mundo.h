#pragma once

#include <iostream>
#include <string>
#include "arvore.h"
#include "pais.h"

class Mundo {
    public:
        Arvore<Pais> get_paises();
        void set_paises();
    private:
        Arvore<Pais> paises;
};
