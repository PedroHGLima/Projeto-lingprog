#pragma once

#include <iostream>
#include <string>

class Pais {
    friend std::ostream& operator<<(std::ostream& os, const Pais& pais);
    public:
        Pais(std::string nome);
        Pais(std::string nome, int populacao, int casos_totais, int total_obitos, int total_recuperados, int casos_ativos);
        ~Pais();
        void set_nome(std::string nome);
        void set_populacao(int populacao);
        void set_casos_totais(int casos_totais);
        void set_total_obitos(int total_obitos);
        void set_total_recuperados(int total_recuperados);
        void set_casos_ativos(int casos_ativos);
        std::string get_nome();
        int get_populacao();
        int get_casos_totais();
        int get_total_obitos();
        int get_total_recuperados();
        int get_casos_ativos();
        bool operator<(Pais &p);
        bool operator>(Pais &p);
        bool operator==(Pais &p);
    private:
        //['Country, Other', 'Total Cases', 'Total Deaths', 'Total Recovered', 'Active Cases', 'Population'] cols do python
        std::string nome;
        int casos_totais;
        int total_obitos;
        int total_recuperados;
        int casos_ativos;
        int populacao;
};
