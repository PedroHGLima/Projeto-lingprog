#define PY_SSIZE_T_CLEAN
#include <python3.10/Python.h>

int main()
{
	Py_Initialize();
    // Import modules
    PyRun_SimpleString("import pandas as pd");
	PyRun_SimpleString("import numpy as np");

    PyRun_SimpleString("df = pd.read_csv('Covid Live.csv')");

	Py_Finalize();
	
	return 0;
}
