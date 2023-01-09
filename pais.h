#pragma once

#include <iostream>
#include <string>
#include <vector>

class Pais {
    friend std::ostream& operator<<(std::ostream& os, const Pais& pais);
    public:
        Pais();
        Pais(std::string nome);
        Pais(std::string nome, int casos_totais, int total_obitos, int total_recuperados, int casos_ativos, int populacao);
        Pais(const Pais& p);
        ~Pais();
        void set_nome(std::string nome);
        void set_populacao(int populacao);
        void set_casos_totais(int casos_totais);
        void set_total_obitos(int total_obitos);
        void set_total_recuperados(int total_recuperados);
        void set_casos_ativos(int casos_ativos);
        std::string get_nome() const;
        int get_populacao() const;
        int get_casos_totais() const;
        int get_total_obitos() const;
        int get_total_recuperados() const;
        int get_casos_ativos() const;
        int get_dado(int var);
        bool operator<(Pais &p);
        bool operator>(Pais &p);
        bool operator==(Pais &p);
        Pais operator=(const Pais &p);
    private:
        //['Country, Other', 'Total Cases', 'Total Deaths', 'Total Recovered', 'Active Cases', 'Population'] cols do python
        std::string nome;
        std::vector<int> dados; //casos_totais, total_obitos, total_recuperados, casos_ativos, populacao
        //                                0           1                 2                 3           4
};
