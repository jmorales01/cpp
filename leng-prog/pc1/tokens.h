class token{
public:
	char sep[500];
	int valor;

	/*
	+ - / *  10
	:=  13
	; 14
	variables 11
	numeros 12
	numeros negativos 16
	< > 15
	^ 17
	error 0
	*/

	void tk(){
		if( strcmp(sep,"+")==0 ||
			strcmp(sep,"-")==0 ||
			strcmp(sep,"*")==0 ||
			strcmp(sep,"/")==0 
		)valor=10;
		else if((sep[0]>=48 && sep[0]<=57) && (sep[1]>=65 && sep[1]<=90 ||sep[1]>=97 && sep[1]<=122))valor=0; // Casos de error
		else if(sep[0]==60 || sep[0]==62)valor=15;
		else if(sep[0]>=48 && sep[0]<=57)valor=12;
		else if(sep[0]>=45 && sep[1]>=48 && sep[1]<=57)valor=16; 
		else if(sep[0]>=65 && sep[0]<=90 ||sep[0]>=97 && sep[0]<=122)valor=11;
		else if(strcmp(sep,":=")==0)valor=13;
		else if(strcmp(sep,";")==0)valor=14;
		else if(strcmp(sep,"^")==0)valor=17;
		else valor = 0;
	}
};