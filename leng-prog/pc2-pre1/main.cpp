#include <iostream>
#include <string.h>
#include <cstdlib>
#include <time.h>
using namespace std;
#include "Estados.h"
#include "Class.h"

int main(int argc, char** argv) {
	srand(time(NULL));
	int n = rand() % 15;
	cout <<"########### ADF ###########" << endl;
	cout << endl;
        Cadena ob;
        for (int i = 0; i < 15; i++) {
	        ob.generarValoresAleatorios();
	        ob.validarCadena();
	        cout << endl;
        }
}
