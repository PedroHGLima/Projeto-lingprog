#include "estatistica.h"

double Estatistica::obitosEPop(Pais &pais){
    percentual = pais.get_total_obitos() / pais.get_populacao();
    return percentual*100;
}

double Estatistica::casosTotaisEPop(Pais &pais){
    percentual = pais.get_casos_totais() / pais.get_populacao();
    return percentual*100;
}

double Estatistica::casosAtivosEPop(Pais &pais){
    percentual = pais.get_casos_ativos() / pais.get_populacao();
    return percentual*100;
}

double Estatistica::recuperadosEPop(Pais &pais){
    percentual = pais.get_total_recuperados() / pais.get_populacao();
    return percentual*100;
}

double Estatistica::obitosECasosTotais(Pais &pais){
    percentual = pais.get_total_obitos() / pais.get_casos_totais();
    return percentual*100;
}

double Estatistica::recuperadosECasosTotais(Pais &pais){
    percentual = pais.get_total_recuperados() / pais.get_casos_totais();
    return percentual*100;
}