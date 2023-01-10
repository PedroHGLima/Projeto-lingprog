#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "mundo.h"

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

int main() {
    Mundo m;
    Arvore<Pais> paises = m.get_paises();

	std::cout << paises.buscar(new Pais("China")) << std::endl;
	gerar_relatorio(paises.buscar(new Pais ("China")));

    return 0;
}

//g++ $(python3-config --cflags) test.cpp -o tst $(python3-config --ldflags --embed)
// Comando para compilar, lembre-se de adicionar os cpp adicionais, caso necessario
