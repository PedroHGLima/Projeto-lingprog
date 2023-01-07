/**
 * @file main.cpp
 * @author Pedro Lima (pedrolima@poli.ufrj.br)
 * @brief Arquivo principal do programa
 * @version 1
 * @date 2022-11-08
 */
#define PY_SSIZE_T_CLEAN
#include <python3.10/Python.h>

#include <iostream>
#include <string>

void rank_list(int num){
   // Set PYTHONPATH TO working directory
   setenv("PYTHONPATH",".",1);

    bool continuar = true;
    int variavel=9;
    PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *presult;

    // Initialize the Python Interpreter
    Py_Initialize();

    // Build the name object
    pName = PyUnicode_FromString((char*)"get_tops");

    // Load the module object
    pModule = PyImport_Import(pName);

    // pDict is a borrowed reference 
    pDict = PyModule_GetDict(pModule);

    // pFunc is also a borrowed reference

    while (continuar) {    
        switch (variavel){
            case 1:
                // Mostra os casos totais
                pFunc = PyDict_GetItemString(pDict, (char*)"top_total");
                continuar = false;
                break;
            case 2:
                // Mostra o total de obitos
                pFunc = PyDict_GetItemString(pDict, (char*)"top_deaths");
                continuar = false;
                break;
            case 3:
                // Mostra o total de recuperados
                pFunc = PyDict_GetItemString(pDict, (char*)"top_recovered");
                continuar = false;
                break;
            case 4:
                // Mostra o total de casos ativos
                pFunc = PyDict_GetItemString(pDict, (char*)"top_active");
                continuar = false;
                break;
            case 5:
                // Mostra a populacao
                pFunc = PyDict_GetItemString(pDict, (char*)"top_population");
                continuar = false;
                break;
            case 9:
                std::cout << "Opcoes de variaveis: " << std::endl;
                std::cout << "1 - Total de contaminados" << std::endl;
                std::cout << "2 - Total de obitos" << std::endl;
                std::cout << "3 - Total de recuperados" << std::endl;
                std::cout << "4 - Total de casos ativos" << std::endl;
                std::cout << "5 - Populacao" << std::endl;
                break;
            default:
                std::cout << "Opcao invalida" << std::endl;
                break;
        }
        if (continuar) {
            std::cout << "Digite a variavel a ser mostrada: "; std::cin >> variavel;
        }
    }

    if (PyCallable_Check(pFunc)){
        pValue=Py_BuildValue("(i)", (int)num);
        PyErr_Print();
        presult=PyObject_CallObject(pFunc,pValue);
        PyErr_Print();
        for (int i = 0; i < num; i++){
            std::cout << _PyUnicode_AsString(PyList_GetItem(presult, i)) << std::endl;
        }
    } else {
        PyErr_Print();
    }

    Py_DECREF(pValue);

    // Clean up
    Py_DECREF(pModule);
    Py_DECREF(pName);

    // Finish the Python Interpreter
    Py_FinalizeEx();
}

void menu(int comando=9) {
    /**
     * @brief Função que exibe o menu do programa
     * @param comando comando a ser executado pelo menu
     */
    int num;
    while (true) {
        switch (comando){
            case 1:{
                // TODO: imprimir coluna
                break;
                }
            case 2:
                std::cout << "Digite o numero de paises a serem mostrados: "; std::cin >> num;
                rank_list(num);
                break;
            case 3:
                // TODO: calculo de estatisticas
                std::cout << "Comando 3" << std::endl;
                break;
            case 4:
                // TODO: estabelecer trheshold
                std::cout << "Comando 4" << std::endl;
                break;
            case 5:
                // TODO: gerar boletim
                std::cout << "Comando 5" << std::endl;
                break;
            case 9:
                std::cout << "Printar ajuda" << std::endl;
                break;
            case 0:
                std::cout << "Encerrando o programa..." << std::endl;
                break;
            default:
                std::cout << "Comando desconhecido" << std::endl;
                break;
        }
        std::cout << "Insira o comando: "; std::cin >> comando;
    }
}

int main() {
    int comando = 9;

    menu(comando);

    return 0;
}
