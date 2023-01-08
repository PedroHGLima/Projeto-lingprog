#define PY_SSIZE_T_CLEAN

#include "mundo.h"
#include <python3.10/Python.h>

Mundo::Mundo() {
    set_paises();
}

Arvore<Pais> Mundo::get_paises() {
    return this->paises;
}

void Mundo::set_paises() {
    static bool paises_existem = false;
    if (!paises_existem) {
        setenv("PYTHONPATH",".",1);
        Py_Initialize();
        PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *presult;
        std::string nome;
        int total, obitos, recuperados, ativos, populacao;
        int qtd;
        while (true) {
            std::cout << "Digite a quantidade de paises que deseja adicionar: ";
            if (std::cin >> qtd) {
                break;
            } else {
                std::cout << "Erro, insira um inteiro" << std::endl;
			    std::cin.clear(); std::cin.ignore();
            }
        }

        pName = PyUnicode_FromString((char*)"read_data");
        pModule = PyImport_Import(pName);
        pDict = PyModule_GetDict(pModule);
        pFunc = PyDict_GetItemString(pDict, (char*)"ler_paises");

        if (PyCallable_Check(pFunc)){
            pValue=Py_BuildValue("(i)", (int)qtd);
            PyErr_Print();
            presult=PyObject_CallObject(pFunc,pValue);
            PyErr_Print();
            qtd = (int) PyList_Size(presult);
            for (int i = 0; i < qtd; i++){
                // ['Country, Other', 'Total Cases', 'Total Deaths', 'Total Recovered', 'Active Cases', 'Population']
                nome = _PyUnicode_AsString(PyList_GetItem(PyList_GetItem(presult, i), 0));
                total = (int) PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(presult, i), 1));
                obitos = (int) PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(presult, i), 2));
                recuperados = (int) PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(presult, i), 3));
                ativos = (int) PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(presult, i), 4));
                populacao = (int) PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(presult, i), 5));
                this->paises.inserir(new Pais(nome, total, obitos, recuperados, ativos, populacao));
            }
        } else {
            PyErr_Print();
        }

        Py_DECREF(pValue);
        Py_DECREF(pModule);
        Py_DECREF(pName);
        Py_FinalizeEx();

        paises_existem = true;
    }
    else {
        std::cout << "Paises ja existem" << std::endl;
        return;
    }
}

