#define PY_SSIZE_T_CLEAN

#include "mundo.h"
#include <python3.10/Python.h>

Mundo::Mundo() {
    this->n_paises = 0;
    set_paises();
}

Arvore<Pais> Mundo::get_paises() {
    return this->paises;
}

void Mundo::set_paises() {
    /// @brief Função que lê os dados do arquivo csv e os adiciona na árvore de países
    static bool paises_existem = false;         // Devido a um bug do python, a função só pode ser chamada uma vez
    if (!paises_existem) {
    // Se sim, eh a primeira execucao
        setenv("PYTHONPATH",".",1);
        Py_Initialize();
        PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *presult;   // Ponteiros para objetos do python
        std::string nome;                                               // Nome do pais 
        int total, obitos, recuperados, ativos, populacao;              // Dados do pais
        int qtd;                                                        // Quantidade de paises a serem lidos
        while (true) {
        // Laco para prevenir erros de leitura
            std::cout << "(<0): Nenhum | 0: Todos | (>0): Quantidade" << std::endl;
            std::cout << "Digite a quantidade de paises que deseja carregar: ";
            if (std::cin >> qtd) {
                break;
            } else {
                std::cout << "Erro, insira um inteiro" << std::endl;
			    std::cin.clear(); std::cin.ignore();
            }
        }

        pName = PyUnicode_FromString((char*)"read_data");           // Nome do arquivo python
        pModule = PyImport_Import(pName);                           // Importa o arquivo
        pDict = PyModule_GetDict(pModule);                          // Dicionario do arquivo
        pFunc = PyDict_GetItemString(pDict, (char*)"ler_paises"); 
        
        if (PyCallable_Check(pFunc)){
            pValue=Py_BuildValue("(i)", (int)qtd);                  // Argumento da funcao
            PyErr_Print();
            presult = PyObject_CallObject(pFunc,pValue);              // Chama a funcao
            PyErr_Print();
            qtd = (int) PyList_Size(presult);            // Quantidade de paises a serem lidos, rededifinida para evitar erros
            /* Dentro da funcao, podemos passar arquivos >=0 para definir quantos paises serao lidos.
            *  Passando 0, a funcao lera todos os paises.
            *  Passsando um numero negativo, a funcao nao lera nada
            */
            for (int i = 0; i < qtd; i++){
                // ['Country, Other', 'Total Cases', 'Total Deaths', 'Total Recovered', 'Active Cases', 'Population']  // Colunas do arquivo csv
                /* O retorno eh uma lista de listas
                *  Neste laco, cada iteracao se trata de uma lista de tamanho 6, que representa um pais
                *  Entao, nao precisamos iterar sobre a lista de listas, apenas sobre a lista
                */
                nome = _PyUnicode_AsString(PyList_GetItem(PyList_GetItem(presult, i), 0));              // Primeira posicao, trata-se do nome
                total = (int) PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(presult, i), 1));          // Segunda posicao, trata-se do total de casos
                obitos = (int) PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(presult, i), 2));         //  ...
                recuperados = (int) PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(presult, i), 3));
                ativos = (int) PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(presult, i), 4));
                populacao = (int) PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(presult, i), 5));
                this->paises.inserir(new Pais(nome, total, obitos, recuperados, ativos, populacao));    // Adiciona o pais na arvore
            }
            this->n_paises = qtd;       // Atualiza a quantidade total de paises
        } else {
            PyErr_Print();
        }


        Py_DECREF(pValue);
        Py_DECREF(pModule);
        Py_DECREF(pName);
        Py_FinalizeEx();

        paises_existem = true;      // A funcao foi executada
    }
    else {
    // Ja foi executada, nao faz nada
        std::cout << "Paises ja existem" << std::endl;
        return;
    }
}

int Mundo::get_n_paises () {
    return this->n_paises;
}

std::ostream &operator<<(std::ostream &out, Mundo&m){
    out << m.paises;
    return out;
}