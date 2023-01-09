#define PY_SSIZE_T_CLEAN
#include <python3.10/Python.h>
#include "mundo.h"

int main(){

	std::cout << "===== Bem vindo ao Relatorio Internacional da Pandemia de Covid-19 =====" << std::endl;
	int opcao;
	Mundo m;
	for(;;){
		std::cout << "Escolha uma das opcoes: " << std::endl;
		std::cout << "1 - Mostrar Lista de paises carregados" << std::endl; // <- Funcao nao prevista no relatorio
		std::cout << "2 - Mostrar dados de um pais" << std::endl;		   // <- Funcao nao prevista no relatorio
		std::cout << "3 - Mostrar Variaveis envolvidas" << std::endl;		

	
		if (std::cin >> opcao) {
                break;
            } else {
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
				std::string nome;
				std::cin >> nome;
				std::cout << m.get_paises().get(nome) << std::endl;
				break;

			case 3:
				std::cout << "As Variaveis envolvidas sao: " << std::endl;
				for(unsigned int i=0; i<m.getNomesPaises().size(); i++){
					std::cout << m.getNomesPaises()[i] << std::endl;
				}
				break;
		}
}



//g++ $(python3-config --cflags) test.cpp -o tst $(python3-config --ldflags --embed)
// Comando para compilar, lembre-se de adicionar os cpp adicionais, caso necessario
