/**
 * @file main.cpp
 * @author Pedro Lima (pedrolima@poli.ufrj.br)
 * @brief Arquivo principal do programa
 * @version 1
 * @date 2022-11-08
 */

#include <iostream>

using namespace std;

void menu(int comando=9) {
    /**
     * @brief Função que exibe o menu do programa
     * @param comando comando a ser executado pelo menu
     */
    switch (comando){
        case 1:
            cout << "Comando 1" << endl;
            break;
        case 2:
            cout << "Comando 2" << endl;
            break;
        case 3:
            cout << "Comando 3" << endl;
            break;
        case 4:
            cout << "Comando 4" << endl;
            break;
        case 5:
            cout << "Comando 5" << endl;
            break;
        case 9:
            cout << "Printar ajuda" << endl;
            break;
        case 0:
            cout << "Encerrando o programa..." << endl;
            break;
        default:
            cout << "Comando desconhecido" << endl;
            break;
    }
}

int main() {
    int comando = 9;

    while (comando!=0){
        menu(comando);
        cout << "Digite um comando: "; cin >> comando;
    }

    return 0;
}
