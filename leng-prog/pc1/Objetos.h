#include <iostream>
using namespace std;
void separador(char frase[],char datos[][500],int &n,bool &e){
	int l = strlen(frase),x = 0;
	n=0;
	if(frase[l-1]!=';'){
		e = false;
	}else{
		e=true;
		for(int i=0;i<l;i++){
			if( (frase[i]>=65 && frase[i]<=90) || 
			    (frase[i]>=97&&frase[i]<=122) ||
			    (frase[i]>=48&&frase[i]<=57) ||
			    (frase[i]==58)||
			    (frase[i]==59)||
			    (frase[i]==42)||
			    (frase[i]==43)||
			    (frase[i]==45)||
			    (frase[i]==47)||
			    (frase[i]==61)||
			    (frase[i]==60)||
			    (frase[i]==62)||
			    (frase[i]==94)
			){
				datos[n][x]=frase[i];
				x++;
			}else{
				datos[n][x]='\0';
				//cout<<datos[n];
				x=0;
				n++;
			}
		}
	}
}