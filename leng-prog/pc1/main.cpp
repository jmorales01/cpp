#include <iostream>
#include <string.h>
using namespace std;
#include "tokens.h"
#include "Objetos.h"

/*
42 *
43 +
45 -
46 .
47 /
60 <
62 >
94 ^
48-57 numeros
59;
65-90 mayusculas
97-122 minusculas

xy := x2 ^ 3 * 5 * xy ;
yx := 6 / 3 + 45 * xy + 4x3 - 40 ;
yxz := 6 < -20 ;

*/

int main(int argc, char** argv) {
	char frase[500],ma[500][500];
	int n=0;
	int error = 0;
	bool es=false;
	
	strcpy(frase,"yxz := 6 < -20 ;");

    // Llama a la función separador para dividir la frase en elementos
	separador(frase,ma,n,es);
	
    // Imprime los elementos separados
	cout<<frase<<" Elementos: "<<n<<endl;
	for(int i=0;i<n;i++){
		cout<<ma[i]<<endl;
	}
	
    // Crea objetos token y asigna valores
	cout<<endl<<endl;
	token v[50];
	for(int i=0;i<n;i++){
		strcpy(v[i].sep,ma[i]);
		v[i].tk();
	}
	
    // Imprime los tokens y sus valores
	for(int i=0;i<n;i++){
		if(v[i].valor == 0){
			error = i;
		}
		cout<<v[i].sep<<"  ==>  "<<v[i].valor<<endl;
	}
	if(error > 0){
		cout<<"Error en la linea de codigo: "<<error+1<<" ==> valor: "<<v[error].sep<<endl;
	}
	
	return 0;
}