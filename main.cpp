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
#include <fstream>
#include <stdlib.h>

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

void gerar_relatorio(Pais *p) {
	if (p == nullptr) {
		return;
	} else {
		std::string texto;
		std::string nome, casos_totais, obitos, recuperados, ativos, populacao;
		nome 			= p->get_nome();
		casos_totais 	= std::to_string(p->get_casos_totais());
		obitos 			= std::to_string(p->get_total_obitos());
		recuperados 	= std::to_string(p->get_total_recuperados());
		ativos 			= std::to_string(p->get_casos_ativos());
		populacao 		= std::to_string(p->get_populacao());
		texto = "\\documentclass[11pt]{beamer}\n\\usetheme{Madrid}\n\\usepackage[utf8]{inputenc}\n\n\\usepackage{wrapfig}\n\\DeclareMathOperator {\\argmin}{argmin}\n\n\\begin{document}\n\n\\begin{frame}{Relatório Nacional}\n\\begin{center}\n\\begin{itemize}\n\\item País: "+nome+" \\newline\n\\end{itemize}\n\\begin{tabular}{c|c|c|c|c}\nTotal & Obitos & Recuperados & Ativos & Populacao \\\\\n\\hline\n"+casos_totais+" & "+obitos+" & "+recuperados+" & "+ativos+" & "+populacao+"\n\\end{tabular}\n\\end{center}\n\\begin{figure}\n\\centering\n\\includegraphics[width=5cm]{data/bandeiras/"+nome+".pdf}\n\\end{figure}\n\\end{frame}\n\n\\end{document}\n";
		std::ofstream arquivo;
		arquivo.open("relatorio.tex");
		arquivo << texto;
		arquivo.close();
		system("pdflatex relatorio.tex >/dev/null");
		system("rm relatorio.aux relatorio.log relatorio.nav relatorio.out relatorio.snm relatorio.toc relatorio.tex");
		std::string cmd = "mv relatorio.pdf docs/relatorios/relatorio_"+nome+".pdf";
		system(cmd.c_str());
	}
}

void rank_list(Mundo &mundo, int num){
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
            case 5:{
                // TODO: gerar boletim
                std::string nome;
                Arvore<Pais> paises = mundo.get_paises();
                std::cout << "Digite o nome do pais: "; 
                std::cin.ignore();
                std::getline(std::cin, nome);
                gerar_relatorio(paises.buscar(new Pais(nome)));
                break;
            }
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
