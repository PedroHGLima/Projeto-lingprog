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

std::vector<Pais> Estatistica::mundoThreshold(Mundo &mundo, double threshold, int opcao){
    std::vector<Pais> todosPaises = mundo.get_paises().arvoreToVector();
    std::vector<Pais> thresholdPaises;

    for (unsigned int i = 0; i < todosPaises.size(); i++){
        switch (opcao){
            case 1:
                percentual = obitosEPop(todosPaises[i]);
                break;
            case 2:
                percentual = casosTotaisEPop(todosPaises[i]);
                break;
            case 3:
                percentual = casosAtivosEPop(todosPaises[i]);
                break;
            case 4:
                percentual = recuperadosEPop(todosPaises[i]);
                break;
            case 5:
                percentual = obitosECasosTotais(todosPaises[i]);
                break;
            case 6:
                percentual = recuperadosECasosTotais(todosPaises[i]);
                break;
            default:
                std::cout << "Opcao invalida" << std::endl;
                break;
        }
        if (percentual >= threshold){
            thresholdPaises.push_back(todosPaises[i]);
        }
    }
    return thresholdPaises;
}