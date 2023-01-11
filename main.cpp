#define PY_SSIZE_T_CLEAN
#include <python3.10/Python.h>

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <limits>

#include "estatistica.h"
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
		texto = "\\documentclass[11pt]{beamer}\n\\usetheme{Madrid}\n\\usepackage[utf8]{inputenc}\n\n\\usepackage{wrapfig}\n\\DeclareMathOperator {\\argmin}{argmin}\n\n\\begin{document}\n\n\\begin{frame}{Relatório Nacional}\n\\begin{center}\n\\begin{itemize}\n\\item País: "+nome+" \\newline\n\\end{itemize}\n\\begin{tabular}{c|c|c|c|c}\nTotal & Óbitos & Recuperados & Ativos & População \\\\\n\\hline\n"+casos_totais+" & "+obitos+" & "+recuperados+" & "+ativos+" & "+populacao+"\n\\end{tabular}\n\\end{center}\n\\begin{figure}\n\\centering\n\\includegraphics[width=5cm]{data/bandeiras/"+nome+".pdf}\n\\end{figure}\n\\end{frame}\n\n\\end{document}\n";
		std::ofstream arquivo;
		arquivo.open("relatorio.tex");
		arquivo << texto;
		arquivo.close();
		system("pdflatex relatorio.tex >/dev/null");
		system("rm relatorio.aux relatorio.log relatorio.nav relatorio.out relatorio.snm relatorio.toc relatorio.tex");
		std::string cmd = "mv relatorio.pdf docs/relatorios/relatorio_\""+nome+"\".pdf";
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
		std::cout << std::endl;
        for (size_t i=0; i<top.size(); i++) {
            std::cout << i+1 << " - " << top[i].get_nome() << std::endl;
        }
    }
    return;
}


int main(){
	int opcao=9, var;
	double threshold;
	std::string nome;
	Pais pais;
	Estatistica estatistica;
	std::cout << "===== Bem vindo ao Relatorio Internacional da Pandemia de Covid-19 =====" << std::endl;
	
	Mundo m;

	for(;;){
		switch(opcao){
			case 1:
				std::cout << "As Variaveis envolvidas sao: " << std::endl; 
				std::cout << "1 - Paises " << std::endl;   
				std::cout << "2 - Total de Casos" << std::endl;   
				std::cout << "3 - Total de Obitos" << std::endl;
				std::cout << "4 - Total de Recuperados" << std::endl;
				std::cout << "5 - Casos Ativos" << std::endl;
				std::cout << "6 - Populacao" << std::endl;
				break;
            case 2: {
				int num;
				bool continuar = true;
                std::cout << "Digite o numero de paises a serem mostrados: ";
				while(continuar){
					if (std::cin >> num) {
							continuar = false;
						} 
						else {
							std::cout << "Erro, insira um inteiro" << std::endl;
							std::cin.clear(); std::cin.ignore();
						}
				}

                rank_list(m, num);
                break;
				}
			case 3:
				std::cout << "Digite o nome do pais: ";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(std::cin, nome);
				std::cout << std::endl;
				try{
					if(m.get_paises().buscar(new Pais(nome))==nullptr){
						throw PonteiroNuloException();
					}
				}
				catch(PonteiroNuloException &e){
					std::cout << e.what() << std::endl;
					break;
				}
				pais = *(m.get_paises().buscar(new Pais(nome)));
				std::cout << std::endl;
				std::cout << "Para o pais " << pais << " as estatisticas sao: " << std::endl;
				std::cout << "O percentual de obitos em toda a populacao eh: " << estatistica.obitosEPop(pais) << "%" << std::endl;
				std::cout << "O percentual de casos totais em toda a populacao eh: " << estatistica.casosTotaisEPop(pais) << "%" << std::endl;
				std::cout << "O percentual de recuperados em toda a populacao eh: " << estatistica.recuperadosEPop(pais) << "%" << std::endl;
				std::cout << "O percentual de casos ativos em toda a populacao eh: " << estatistica.casosAtivosEPop(pais) << "%" << std::endl;
				std::cout << "O percentual de obitos em relacao aos casos totais eh: " << estatistica.obitosECasosTotais(pais) << "%" << std::endl;
				std::cout << "O percentual de recuperados em relacao aos casos totais eh: " << estatistica.recuperadosECasosTotais(pais)<< "%" << std::endl;
				break;
			case 4:
				std::cout << "Insira o valor de referencia, em termos percentuais: ";
				while(true){
					if (std::cin >> threshold) {
						break;
					} else {
						std::cout << "Erro, insira um numero" << std::endl;
			    		std::cin.clear(); std::cin.ignore();
					}
				}
				std::cout << "Escolha um dentre os criterios abaixo:" << std::endl;
				std::cout << "1 - Percentual de obitos em toda a populacao" << std::endl;
				std::cout << "2 - Percentual de casos totais em toda a populacao" << std::endl;
				std::cout << "3 - Percentual de casos ativos em toda a populacao" << std::endl;
				std::cout << "4 - Percentual de recuperados em toda a populacao" << std::endl;
				std::cout << "5 - Percentual de obitos em relacao aos casos totais" << std::endl;
				std::cout << "6 - Percentual de recuperados em relacao aos casos totais" << std::endl;
				while(true){
					if (std::cin >> var) {
						break;
					} 
					else {
						std::cout << "Erro, insira um inteiro" << std::endl;
			    		std::cin.clear(); std::cin.ignore();
					}
				}
				std::cout << "Os paises com o percentual da opcao " << var << " acima de " << threshold << " % sao:" << std::endl;
				for(unsigned int i = 0; i < estatistica.mundoThreshold(m,threshold,var).size(); i++){
					std::cout << estatistica.mundoThreshold(m,threshold,var)[i] << std::endl;
				}
				break;
            case 5:{
                std::string nome;
                Arvore<Pais> paises = m.get_paises();
                std::cout << "Digite o nome do pais: "; 
                std::cin.ignore();
                getline(std::cin, nome);
				Pais *p = paises.buscar(new Pais(nome));
				try{
					if(p==nullptr){
						throw PonteiroNuloException();
					}
				}
				catch(PonteiroNuloException &e){
					std::cout << e.what() << std::endl;
					break;
				}
				std::cout << "Gerando relatorio para " << nome << "..." << std::endl;
				gerar_relatorio(paises.buscar(new Pais(nome)));
				std::cout << "Concluido" << std::endl;
				break;
            }
			
			case 6:
				std::cout << m;
				break;

			case 7:
				std::cout << "Digite o nome do pais: ";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(std::cin, nome);
				try{
					if(m.get_paises().buscar(new Pais(nome))==nullptr){
						throw PonteiroNuloException();
					}
				}
				catch(PonteiroNuloException &e){
					std::cout << e.what() << std::endl;
					break;
				}
				pais = *(m.get_paises().buscar(new Pais(nome)));
				std::cout << "Nome: " << pais << std::endl;
				std::cout << "Total de Casos: " << pais.get_casos_totais() << std::endl;
				std::cout << "Total de Obitos: " << pais.get_total_obitos() << std::endl;
				std::cout << "Total de Recuperados: " << pais.get_total_recuperados() << std::endl;
				std::cout << "Casos Ativos: " << pais.get_casos_ativos() << std::endl;
				std::cout << "Populacao: " << pais.get_populacao() << std::endl;
				break;
			case 9:
				std::cout << "Escolha uma das opcoes: " 							<< std::endl;
				std::cout << "1 - Mostrar variaveis envolvidas" 					<< std::endl;   //ok
				std::cout << "2 - Ranquear paises com base em uma variavel" 		<< std::endl;   //ok
				std::cout << "3 - Apresentar estatisticas relacionadas a um pais" 	<< std::endl;   
				std::cout << "4 - Filtrar Paises por um valor de referencia" 		<< std::endl; 
				std::cout << "5 - Gerar um boletim em PDF sobre um pais" 			<< std::endl;   //ok
				std::cout << "6 - Mostrar Lista de paises carregados"				<< std::endl;   //ok
				std::cout << "7 - Mostrar dados de um pais"							<< std::endl;   
				std::cout << "9 - Impressao da ajuda"								<< std::endl;  //ok
				std::cout << "0 - Sair" 											<< std::endl;
				break;
			case 0:
				return 0;
				break;
		}
		while(true){
			std::cout << std::endl << "Digite a opcao desejada: ";
			if (std::cin >> opcao) {
                	break;
            } else {
				std::cout << "Erro, insira um inteiro" << std::endl;
				std::cin.clear(); std::cin.ignore();
			}
		}
		std::cout << std::endl;
	}
}
