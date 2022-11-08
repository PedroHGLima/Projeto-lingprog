/**
 * @file main.cpp
 * @author Pedro Lima (pedrolima@poli.ufrj.br)
 * @brief Arquivo principal do programa
 * @version 1
 * @date 2022-11-08
 */

#include <iostream>

using namespace std;

void maioresContaminados(int num){
    cout << "Mostre os " << num << " paises com mais contaminados" << endl;
}

void menu(int comando=9) {
    /**
     * @brief Função que exibe o menu do programa
     * @param comando comando a ser executado pelo menu
     */
    int num;
    switch (comando){
        case 1:
            // TODO: implementar função que mostra os paises com maior numero de contaminados
            cout << "Digite o numero de paises a serem mostrados: "; cin >> num;
            maioresContaminados(num);
            break;
        case 2:
            // TODO: implementar função que mostra os paises com maior numero de obitos
            cout << "Comando 2" << endl;
            break;
        case 3:
            // TODO: implementar função que mostra os paises com maior numero de recuperados
            cout << "Comando 3" << endl;
            break;
        case 4:
            // TODO: implementar função que mostra os paises com maior numero de casos ativos
            cout << "Comando 4" << endl;
            break;
        case 5:
            // TODO: implementar função que mostra os paises mais populosos
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
