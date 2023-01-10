#define PY_SSIZE_T_CLEAN
#include <python3.10/Python.h>
#include "mundo.h"
#include "estatistica.h"
#include <limits>

int main(){

	std::cout << "===== Bem vindo ao Relatorio Internacional da Pandemia de Covid-19 =====" << std::endl;
	int opcao;
	std::string nome;
	Pais pais;
	Estatistica estatistica;
	Mundo m;


	for(;;){
		std::cout << "Escolha uma das opcoes: " << std::endl;
		std::cout << "1 - Mostrar Lista de paises carregados" << std::endl; // <- Funcao nao prevista no relatorio
		std::cout << "2 - Mostrar dados de um pais" << std::endl;		   // <- Funcao nao prevista no relatorio
		std::cout << "3 - Mostrar variaveis envolvidas" << std::endl;
		std::cout << "4 - Apresentar estatisticas relacionadas a um pais" << std::endl;	

	
		while(true){
			if (std::cin >> opcao) {
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
				pais = *(m.get_paises().buscar(new Pais("Brazil"))); // <- tentar corrigir problema de seg fault 
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

			
		}
	}		
}



//g++ $(python3-config --cflags) test.cpp -o tst $(python3-config --ldflags --embed)
// Comando para compilar, lembre-se de adicionar os cpp adicionais, caso necessario
