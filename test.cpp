#define PY_SSIZE_T_CLEAN
#include <python3.10/Python.h>
#include "mundo.h"
#include "estatistica.h"
#include <limits>

int main(){
	int opcao;
	double threshold;
	std::string nome;
	Pais pais;
	Estatistica estatistica;
	std::cout << "===== Bem vindo ao Relatorio Internacional da Pandemia de Covid-19 =====" << std::endl;
	
	Mundo m;


	for(;;){
		std::cout << std::endl;
		std::cout << "Escolha uma das opcoes: " << std::endl;
		std::cout << "1 - Mostrar Lista de paises carregados" << std::endl; // <- Funcao nao prevista no relatorio
		std::cout << "2 - Mostrar dados de um pais" << std::endl;		   // <- Funcao nao prevista no relatorio
		std::cout << "3 - Mostrar variaveis envolvidas" << std::endl;
		std::cout << "4 - Apresentar estatisticas relacionadas a um pais" << std::endl;	
		std::cout << "5 - Filtrar Paises por um valor de referencia" << std::endl;
		std::cout << std::endl;

	
		while(true){
			if (std::cin >> opcao) {
					std::cout << std::endl;
                	break;
            	} 
				else {
                	std::cout << "Erro, insira um inteiro" << std::endl;
			    	std::cin.clear(); std::cin.ignore();
				}
		}
        
		switch(opcao){
			case 1:
				std::cout << m << std::endl;
				break;

			case 2:
				std::cout << "Digite o nome do pais: " << std::endl;
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
				std::cout << "Nome: " << pais << std::endl;
				std::cout << "Total de Casos: " << pais.get_casos_totais() << std::endl;
				std::cout << "Total de Obitos: " << pais.get_total_obitos() << std::endl;
				std::cout << "Total de Recuperados: " << pais.get_total_recuperados() << std::endl;
				std::cout << "Casos Ativos: " << pais.get_casos_ativos() << std::endl;
				std::cout << "Populacao: " << pais.get_populacao() << std::endl;
				break;

			case 3:
				std::cout << "As Variaveis envolvidas sao: " << std::endl;
				std::cout << "1 - Paises " << std::endl;
				std::cout << "2 - Total de Casos" << std::endl;
				std::cout << "3 - Total de Obitos" << std::endl;
				std::cout << "4 - Total de Recuperados" << std::endl;
				std::cout << "5 - Casos Ativos" << std::endl;
				std::cout << "6 - Populacao" << std::endl;
				break;
			
			case 4:
				std::cout << "Digite o nome do pais: " << std::endl;
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
				std::cout << "O percentual de obitos em toda a populacao e: " << estatistica.obitosEPop(pais) << "%" << std::endl;
				std::cout << "O percentual de casos totais em toda a populacao e: " << estatistica.casosTotaisEPop(pais) << "%" << std::endl;
				std::cout << "O percentual de recuperados em toda a populacao e: " << estatistica.recuperadosEPop(pais) << "%" << std::endl;
				std::cout << "O percentual de casos ativos em toda a populacao e: " << estatistica.casosAtivosEPop(pais) << "%" << std::endl;
				std::cout << "O percentual de obitos em relacao aos casos totais e: " << estatistica.obitosECasosTotais(pais) << "%" << std::endl;
				std::cout << "O percentual de recuperados em relacao aos casos totais e: " << estatistica.recuperadosECasosTotais(pais)<< "%" << std::endl;
				break;
			case 5:
				std::cout << "Insira o valor de referencia, em termos percentuais: " << std::endl;
				while(true){
					if (std::cin >> threshold) {
						break;
					} 
					else {
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
					if (std::cin >> opcao) {
						break;
					} 
					else {
						std::cout << "Erro, insira um inteiro" << std::endl;
			    		std::cin.clear(); std::cin.ignore();
					}
				}
				std::cout << "Os paises com o percentual da opcao " << opcao << " acima de " << threshold << " % sao:" << std::endl;
				for(unsigned int i = 0; i < estatistica.mundoThreshold(m,threshold,opcao).size(); i++){
					std::cout << estatistica.mundoThreshold(m,threshold,opcao)[i] << std::endl;
				}
				break;


				
			
		}
	}		
}