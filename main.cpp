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
#include <algorithm>

#include "mundo.h"

std::vector<Pais> get_top(Arvore<Pais> *arv, std::vector<Pais> *v, int var) {
	if (arv != nullptr) {
		get_top(arv->get_esq(), v, var);
		if (arv->get_valor()->get_dado(var) > (*v).back().get_dado(var)) {
			(*v).back() = *(arv->get_valor());
			std::sort((*v).begin(), (*v).end(), [var](Pais a, Pais b) {
				return a.get_dado(var) > b.get_dado(var);
			});
		}
		get_top(arv->get_dir(), v, var);
	}
	return (*v);
}

std::vector<Pais> get_top(Mundo& m, int var, int qtd=10) {
	if (qtd > m.get_n_paises()) {
        qtd = m.get_n_paises();
        std::cout << "Quantidade maior do que o numero de paises, reduzindo para " << qtd << std::endl;
    }
    
    std::vector<Pais> v(qtd);
    Arvore<Pais> paises = m.get_paises();
	return get_top(&paises, &v, var);
}

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
                std::cout << "9 - Mostrar opcoes" << std::endl;
                std::cout << "0 - Sair" << std::endl;
                break;
            case 0:
                continuar = false;
                break;
            default:
                std::cout << "Opcao invalida" << std::endl;
                break;
        }
        if (continuar) {
            std::cout << "Digite a variavel a ser mostrada: "; std::cin >> variavel;
        }
    }
    if (variavel == 0) {
        return;
    } else {
        std::vector<Pais> top = get_top(mundo, --variavel, num);
        for (size_t i=0; i<top.size(); i++) {
            std::cout << top[i].get_nome() << std::endl;
        }
    }
    return;
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
                return;
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
    Mundo mundo;

    menu(mundo);

    return 0;
}
