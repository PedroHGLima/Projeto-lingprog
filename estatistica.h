#pragma once
#include "pais.h"
#include <cmath>


class Estatistica{

    public:
        double obitosEPop(Pais&);
        double casosTotaisEPop(Pais&);
        double casosAtivosEPop(Pais&);
        double recuperadosEPop(Pais&);
        double obitosECasosTotais(Pais&);
        double recuperadosECasosTotais(Pais&);
        double round_to(double value, double precision);
    private:
        double percentual;
};