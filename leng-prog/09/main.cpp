#include <iostream>
#include <string.h>
using namespace std;
#include  "estadosFx.h"
#include "clasFx.h"

int main(int argc, char** argv) {
	tabla td;
	celda x1; 
		td.asignar(2,3);
		
		x1.asignar(E2); td.asignar(0,0,x1);td.ma[0][0].estN=E1; td.ma[0][0].simbolo='a';
		x1.ce=0; x1.asignar(E3); td.asignar(0,1,x1); td.ma[0][1].estN=E1; td.ma[0][1].simbolo='b';
		x1.ce=0; x1.asignar(E2); td.asignar(0,2,x1); td.ma[0][2].estN=E1; td.ma[0][2].simbolo='c';
		x1.ce=0; x1.asignar(E2); td.asignar(1,0,x1); td.ma[1][0].estN=E1; td.ma[1][0].simbolo='a';
		x1.ce=0; x1.asignar(E2); td.asignar(1,1,x1); td.ma[1][1].estN=E1; td.ma[1][1].simbolo='b';
		x1.ce=0; x1.asignar(E2); td.asignar(1,2,x1); td.ma[1][2].estN=E1; td.ma[1][2].simbolo='c';
		td.imprimir();
		cout<<endl;
	tabla tdN;
		tdN.asignar(2,3);
		x1.ce=0;x1.asignar(E2);x1.asignar(E3);tdN.asignar(0,0,x1);
			tdN.ma[0][0].estN=E1;tdN.ma[0][0].simbolo='a';
		x1.ce=0;x1.asignar(E1);x1.asignar(E3);tdN.asignar(0,1,x1);
			tdN.ma[0][1].estN=E1;tdN.ma[0][1].simbolo='b';
		x1.ce=0;x1.asignar(E2);tdN.asignar(0,2,x1);
			tdN.ma[0][2].estN=E1;tdN.ma[0][2].simbolo='c';
		x1.ce=0;x1.asignar(E1);x1.asignar(E3);tdN.asignar(1,0,x1);
			tdN.ma[1][0].estN=E1;tdN.ma[1][0].simbolo='a';
		x1.ce=0;x1.asignar(E2);tdN.asignar(1,1,x1);
			tdN.ma[1][1].estN=E1;tdN.ma[1][1].simbolo='b';
		x1.ce=0;x1.asignar(E2);x1.asignar(E3);tdN.asignar(1,2,x1);
			tdN.ma[1][2].estN=E1;tdN.ma[1][2].simbolo='c';
		tdN.imprimir();
	return 0;
}
