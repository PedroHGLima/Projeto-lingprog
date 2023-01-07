//#define PY_SSIZE_T_CLEAN
//#include <python3.10/Python.h>
#include "pais.h"
#include <iostream>
#include <string>

int main(){
	Pais p("USA");
	Pais p1(p);
	Pais p2;
	//p2.carregar_dados();
	std::cout << p << std::endl;
	return 0;
}

//g++ $(python3-config --cflags) test.cpp -o tst $(python3-config --ldflags --embed)
