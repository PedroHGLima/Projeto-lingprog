#include "estatistica.h"

double Estatistica::obitosEPop(Pais &pais){
    percentual = (double) pais.get_total_obitos() / (double) pais.get_populacao();
    return round_to(percentual*100, 0.01);
}

double Estatistica::casosTotaisEPop(Pais &pais){
    percentual = (double) pais.get_casos_totais() / (double) pais.get_populacao();
    return round_to(percentual*100, 0.01);
}

double Estatistica::casosAtivosEPop(Pais &pais){
    percentual = (double) pais.get_casos_ativos() / (double) pais.get_populacao();
    return round_to(percentual*100, 0.01);
}

double Estatistica::recuperadosEPop(Pais &pais){
    percentual = (double) pais.get_total_recuperados() / (double) pais.get_populacao();
    return round_to(percentual*100, 0.01);
}

double Estatistica::obitosECasosTotais(Pais &pais){
    percentual = (double) pais.get_total_obitos() / pais.get_casos_totais();
    return round_to(percentual*100, 0.01);
}

double Estatistica::recuperadosECasosTotais(Pais &pais){
    percentual = (double) pais.get_total_recuperados() / (double) pais.get_casos_totais();
    return round_to(percentual*100, 0.01);
}

double Estatistica::round_to(double value, double precision = 1.0)
{
    return std::round(value / precision) * precision;
}