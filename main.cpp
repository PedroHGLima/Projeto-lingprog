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

#include "mundo.h"

void rank_list(Mundo &mundo, int num){
    // TODO: ainda ta tudo errado aqui
    bool continuar = true;
    int variavel=9;

    while (continuar) {    
        switch (variavel){
            case 1:
                // Mostra os casos totais
                continuar = false;
                break;
            case 2:
                // Mostra o total de obitos
                continuar = false;
                break;
            case 3:
                // Mostra o total de recuperados
                continuar = false;
                break;
            case 4:
                // Mostra o total de casos ativos
                continuar = false;
                break;
            case 5:
                // Mostra a populacao
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

    //for (int i = 0; i < m.get_n_paises; i++){}
}

void menu(Mundo& mundo, int comando=9) {
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
                rank_list(mundo, num);
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
                return;
                break;
        }
        std::cout << "Insira o comando: "; std::cin >> comando;
    }
}

int main() {
    int comando = 9;
    Mundo mundo;

    menu(mundo, comando);

    return 0;
}
