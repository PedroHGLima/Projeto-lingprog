#include "pais.h"

//['Country, Other', 'Total Cases', 'Total Deaths', 'Total Recovered', 'Active Cases', 'Population'] cols do python

Pais::Pais() : dados(5) {
    /// @brief Construtor padrao, inicializa todos os atributos com 0
    this->nome = "";
    this->dados.at(0) = 0;                  // casos totais
    this->dados.at(1) = 0;                  // obitos
    this->dados.at(2) = 0;                  // recuperados
    this->dados.at(3) = 0;                  // ativos
    this->dados.at(4) = 0;                  // populacao
}

Pais::Pais(std::string nome) : dados(5) {
    /// @brief Construtor padrao, inicializa todos os atributos com 0
    /// @param nome Nome do pais
    this->nome = nome;
    this->dados.at(0) = 0;                  // casos totais
    this->dados.at(1) = 0;                  // obitos
    this->dados.at(2) = 0;                  // recuperados
    this->dados.at(3) = 0;                  // ativos
    this->dados.at(4) = 0;                  // populacao
}

Pais::Pais(std::string nome, int casos_totais, int total_obitos, int total_recuperados, int casos_ativos, int populacao) : dados(5) {
    /// @brief Construtor completo, inicializa todos os atributos com os valores passados
    this->nome = nome;
    this->dados.at(0) = casos_totais;
    this->dados.at(1) = total_obitos;
    this->dados.at(2) = total_recuperados;
    this->dados.at(3) = casos_ativos;
    this->dados.at(4) = populacao;
}

Pais::Pais(const Pais& p) : dados(5) {
    /// @brief Construtor de copia
    this->nome = p.get_nome();
    this->dados.at(0) = p.get_casos_totais();
    this->dados.at(1) = p.get_total_obitos();
    this->dados.at(2) = p.get_total_recuperados();
    this->dados.at(3) = p.get_casos_ativos();
    this->dados.at(4) = p.get_populacao();
}

Pais::~Pais() {
}

//['Country, Other', 'Total Cases', 'Total Deaths', 'Total Recovered', 'Active Cases', 'Population'] cols do python

void Pais::set_nome(std::string nome) {
    this->nome = nome;
}

void Pais::set_casos_totais(int casos_totais) {
    this->dados.at(0) = casos_totais;
}

void Pais::set_total_obitos(int total_obitos) {
    this->dados.at(1) = total_obitos;
}

void Pais::set_total_recuperados(int total_recuperados) {
    this->dados.at(2) = total_recuperados;
}

void Pais::set_casos_ativos(int casos_ativos) {
    this->dados.at(3) = casos_ativos;
}

void Pais::set_populacao(int populacao) {
    this->dados.at(4) = populacao;
}

std::string Pais::get_nome() const {
    return this->nome;
}

int Pais::get_casos_totais() const {
    return this->dados.at(0);
}

int Pais::get_total_obitos() const {
    return this->dados.at(1);
}

int Pais::get_total_recuperados() const {
    return this->dados.at(2);
}

int Pais::get_casos_ativos() const {
    return this->dados.at(3);
}

int Pais::get_populacao() const {
    return this->dados.at(4);
}

int Pais::get_dado(int var) {
    return this->dados.at(var);
}

bool Pais::operator<(Pais &p) {
    return this->nome < p.get_nome();
}

bool Pais::operator>(Pais &p) {
    return this->nome > p.get_nome();
}

bool Pais::operator==(Pais &p) {
    return this->nome == p.get_nome();
}

std::ostream& operator<<(std::ostream& os, const Pais& pais) {
    /// @brief A impressao do pais trata-se apenas do nome
    /// @param os 
    /// @param pais 
    /// @return 
    os << pais.nome;
    return os;
}

Pais Pais::operator=(const Pais& p){
    this->nome = p.get_nome();
    this->dados.at(0) = p.get_casos_totais();
    this->dados.at(1) = p.get_total_obitos();
    this->dados.at(2) = p.get_total_recuperados();
    this->dados.at(3) = p.get_casos_ativos();
    this->dados.at(4) = p.get_populacao();
    return *this;
}
