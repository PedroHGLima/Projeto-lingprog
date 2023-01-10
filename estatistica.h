#pragma once
#include "pais.h"


class Estatistica{

    public:
        double obitosEPop(Pais&);
        double casosTotaisEPop(Pais&);
        double casosAtivosEPop(Pais&);
        double recuperadosEPop(Pais&);
        double obitosECasosTotais(Pais&);
        double recuperadosECasosTotais(Pais&);
    
    private:
        double percentual;
};