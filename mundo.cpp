#define PY_SSIZE_T_CLEAN

#include "mundo.h"
#include <python3.10/Python.h>

Arvore<Pais> Mundo::get_paises() {
    return this->paises;
}

void Mundo::set_paises() {
    static bool paises_existem = false;
    if (!paises_existem) {
        //this->paises = Arvore<Pais>(new Pais("Brasil"));

        Py_Initialize();
        PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *presult;
        int qtd;
        while (true) {
            std::cout << "Digite a quantidade de paises que deseja adicionar: ";
            if (std::cin >> qtd) {
                std::cout << "qtd: " << qtd << std::endl;
                break;
            } else {
                std::cout << "Erro, insira um inteiro" << std::endl;
			    std::cin.clear(); std::cin.ignore();
            }
        }

        pName = PyUnicode_FromString((char*)"read");
        pModule = PyImport_Import(pName);
        pDict = PyModule_GetDict(pModule);
        std::cout << "chegou aqui" << std::endl;
        pFunc = PyDict_GetItemString(pDict, (char*)"ler_paises");

        if (PyCallable_Check(pFunc)){
            pValue=Py_BuildValue("(i)", (int)qtd);
            PyErr_Print();
            presult=PyObject_CallObject(pFunc,pValue);
            PyErr_Print();
            for (int i = 0; i < qtd; i++){
                std::cout << _PyUnicode_AsString(PyList_GetItem(presult, i)) << std::endl;
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

