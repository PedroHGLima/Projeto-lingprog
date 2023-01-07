#pragma once
#include <iostream>
#include <string>

class Pais {
    friend std::ostream& operator<<(std::ostream& os, const Pais& pais);
    public:
        Pais();
        Pais(Pais& p);
        Pais(std::string nome);
        Pais(std::string nome, int populacao, int total_contaminados, int total_obitos, int total_recuperados, int total_ativos);
        void carregar_dados();
        void carregar_dados(std::string n);
        std::string get_nome();
        int get_populacao();
        int get_total_contaminados();
        int get_total_obitos();
        int get_total_recuperados();
        int get_total_ativos();
        void set_nome(std::string nome);
        void set_populacao(int populacao);
        void set_total_contaminados(int total_contaminados);
        void set_total_obitos(int total_obitos);
        void set_total_recuperados(int total_recuperados);
        void set_total_ativos(int total_ativos);
        void print();
    private:
        std::string nome;
        int populacao;
        int total_contaminados;
        int total_obitos;
        int total_recuperados;
        int total_ativos;
};
