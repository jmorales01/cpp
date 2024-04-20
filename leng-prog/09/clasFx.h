class estadosL{
	public:
		char qS[5];
		int qE;
		void asignarV(){
			switch(qE){
				case E0: strcpy(qS,"E0");break;
				case E1: strcpy(qS,"E1");break;
				case E2: strcpy(qS,"E2");break;
				case E3: strcpy(qS,"E3");break;
				case Ex: strcpy(qS,"Ex");break;
				default: strcpy(qS,"");break;
			}
		}
};

class celda{
	public:
		char simbolo;
		int estN;
		int est[50];
		int ce=0;
		void asignar(int e){
			est[ce]=e;
			ce++;
		}
		void imprimir(){
			for(int i=0;i<ce;i++){
				cout<<est[i]<<"\t";
			}cout<<endl;
		}
		void celdarStr(char x[]){
			estadosL aux;
			strcpy(x,"");
			for(int i=0;i<ce;i++){
				aux.qE=est[i];
				aux.asignarV();
				strcat(x,aux.qS);
				strcat(x,",");
				//cout<<est[i]<<"\t";
			}
			x[strlen(x)-1]='\0';
		}
};

class tabla{
	public:
		celda ma[50][50];
		int fil, col;
		void asignar(int f, int c){
			fil=f;
			col=c;
		}
		void asignar(int f, int c, celda Es){
			ma[f][c]=Es;
		}
		void imprimir(){
			for(int i=0;i<fil;i++){
				for(int j=0;j<col;j++){
					char x[50], y[50];
					estadosL aux;
					aux.qE=ma[i][j].estN;
					aux.asignarV();
					ma[i][j].celdarStr(x);
					cout<<ma[i][j].estN<<"-"<<ma[i][j].simbolo<<"-"<<x<<"\t";
				}cout<<endl;
			}
		}
};


