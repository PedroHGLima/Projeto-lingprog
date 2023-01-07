#define PY_SSIZE_T_CLEAN

#include "pais.h"
#include <python3.10/Python.h>


Pais::Pais() {
    this->nome = "";
    this->populacao = 0;
    this->total_contaminados = 0;
    this->total_obitos = 0;
    this->total_recuperados = 0;
    this->total_ativos = 0;
}

Pais::Pais(Pais& p) {
    this->nome = p.nome;
    this->populacao = p.populacao;
    this->total_contaminados = p.total_contaminados;
    this->total_obitos = p.total_obitos;
    this->total_recuperados = p.total_recuperados;
    this->total_ativos = p.total_ativos;
}

Pais::Pais(std::string nome){

    setenv("PYTHONPATH",".",1);
    PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *presult;

    Py_Initialize();
    pName = PyUnicode_FromString((char*)"read");
    pModule = PyImport_Import(pName);
    pDict = PyModule_GetDict(pModule);
    pFunc = PyDict_GetItemString(pDict, (char*)"ler_pais");

    if (PyCallable_Check(pFunc)){
        pValue=Py_BuildValue("(z)", (char*)nome.c_str());
        PyErr_Print();
        presult=PyObject_CallObject(pFunc,pValue);
        PyErr_Print();
        //cols = ['Country, Other', 'Total Cases', 'Total Deaths', 'Total Recovered', 'Active Cases', 'Population']
        this->nome = _PyUnicode_AsString(PyList_GetItem(presult, 0));
        this->total_contaminados = (int)PyFloat_AsDouble(PyList_GetItem(presult, 1));
        this->total_obitos = (int)PyFloat_AsDouble(PyList_GetItem(presult, 2));
        this->total_recuperados = (int)PyFloat_AsDouble(PyList_GetItem(presult, 3));
        this->total_ativos = (int)PyFloat_AsDouble(PyList_GetItem(presult, 4));
        this->populacao = (int)PyFloat_AsDouble(PyList_GetItem(presult, 5));

    } else {
        PyErr_Print();
    }

    Py_DECREF(pValue);
    Py_DECREF(pModule);
    Py_DECREF(pName);
    Py_FinalizeEx();
}

Pais::Pais(std::string nome, int populacao, int total_contaminados, int total_obitos, int total_recuperados, int total_ativos) {
    this->nome = nome;
    this->populacao = populacao;
    this->total_contaminados = total_contaminados;
    this->total_obitos = total_obitos;
    this->total_recuperados = total_recuperados;
    this->total_ativos = total_ativos;
}

void Pais::carregar_dados() {
    if ("" == this->nome) {
        std::cout << "Nome do pais vazio, por favor carregue um nome." << std::endl;
        std::cout << "Nome: ";
        std::cin.clear();
        std::getline(std::cin, this->nome);
        std::cout << "Pegou: " << this->nome << std::endl;
    }
    this->carregar_dados(this->nome);
}

void Pais::carregar_dados(std::string n) {
    std::cout<< "Entrou com o nome de " << n << std::endl;
    Pais aux = Pais(n);
    std::cout << "Chegou aqui" << std::endl;
    this->nome = aux.nome;
    this->populacao = aux.populacao;
    this->total_contaminados = aux.total_contaminados;
    this->total_obitos = aux.total_obitos;
    this->total_recuperados = aux.total_recuperados;
    this->total_ativos = aux.total_ativos;
}

std::string Pais::get_nome() {
    return this->nome;
}

int Pais::get_populacao() {
    return this->populacao;
}

int Pais::get_total_contaminados() {
    return this->total_contaminados;
}

int Pais::get_total_obitos() {
    return this->total_obitos;
}

int Pais::get_total_recuperados() {
    return this->total_recuperados;
}

int Pais::get_total_ativos() {
    return this->total_ativos;
}

void Pais::set_nome(std::string nome) {
    this->nome = nome;
}

void Pais::set_populacao(int populacao) {
    this->populacao = populacao;
}

void Pais::set_total_contaminados(int total_contaminados) {
    this->total_contaminados = total_contaminados;
}

void Pais::set_total_obitos(int total_obitos) {
    this->total_obitos = total_obitos;
}

void Pais::set_total_recuperados(int total_recuperados) {
    this->total_recuperados = total_recuperados;
}

void Pais::set_total_ativos(int total_ativos) {
    this->total_ativos = total_ativos;
}

std::ostream& operator<< (std::ostream& os, const Pais& pais) {
    os << "Nome: " << pais.nome << std::endl;
    os << "Populacao: " << pais.populacao << std::endl;
    os << "Total de contaminados: " << pais.total_contaminados << std::endl;
    os << "Total de obitos: " << pais.total_obitos << std::endl;
    os << "Total de recuperados: " << pais.total_recuperados << std::endl;
    os << "Total de ativos: " << pais.total_ativos << std::endl;
    return os;
}

void Pais::print() {
    std::cout << *this << std::endl;
}
