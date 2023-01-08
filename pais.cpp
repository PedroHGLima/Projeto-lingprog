#include "pais.h"

Pais::Pais(std::string nome) {
    this->nome = nome;
    this->populacao = 0;
    this->casos_totais = 0;
    this->total_obitos = 0;
    this->total_recuperados = 0;
    this->casos_ativos = 0;
}

Pais::Pais(std::string nome, int populacao, int casos_totais, int total_obitos, int total_recuperados, int casos_ativos) {
    this->nome = nome;
    this->populacao = populacao;
    this->casos_totais = casos_totais;
    this->total_obitos = total_obitos;
    this->total_recuperados = total_recuperados;
    this->casos_ativos = casos_ativos;
}

Pais::~Pais() {
}

void Pais::set_nome(std::string nome) {
    this->nome = nome;
}

void Pais::set_populacao(int populacao) {
    this->populacao = populacao;
}

void Pais::set_casos_totais(int casos_totais) {
    this->casos_totais = casos_totais;
}

void Pais::set_total_obitos(int total_obitos) {
    this->total_obitos = total_obitos;
}

void Pais::set_total_recuperados(int total_recuperados) {
    this->total_recuperados = total_recuperados;
}

void Pais::set_casos_ativos(int casos_ativos) {
    this->casos_ativos = casos_ativos;
}

std::string Pais::get_nome() {
    return this->nome;
}

int Pais::get_populacao() {
    return this->populacao;
}

int Pais::get_casos_totais() {
    return this->casos_totais;
}

int Pais::get_total_obitos() {
    return this->total_obitos;
}

int Pais::get_total_recuperados() {
    return this->total_recuperados;
}

int Pais::get_casos_ativos() {
    return this->casos_ativos;
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
    os << pais.nome;
    return os;
}
