class Estados{
	public:
		char estadoActual[5];
		void procesarEstados(char value){
			if (value == 88) {
			    strcpy(estadoActual, "E0");
			} else if (value == 89) {
			    strcpy(estadoActual, "E1");
			} else if (value >= 48 && value <= 57) {
			    strcpy(estadoActual, "E2");
			} else {
			    strcpy(estadoActual, "Ex");
			}
		}
};

class Celda{
	public:
		void procesarCelda(char valor,char data[]){
			Estados estado;
			estado.procesarEstados(valor);
			strcpy(data,estado.estadoActual);
		}
	
};

class Tabla{
	public:
		Celda celda[50][50];
		int row,col;
		
		void asignarTabla(int r , int c){
			row = r ;
			col = c;
		}
		
		bool validarCelda(char target[]){
			if(target == "Ex"){
				return false;
			}
			return true;
		}
		void imprimir(char valorActual[]) {
		    for (int i = 0; i < strlen(valorActual); i++) {
		        for (int j = 0; j < col; j++) {
		            char aux[50];
		            celda[i][j].procesarCelda(valorActual[i], aux);
		            if (!validarCelda(aux)) {
		                cout << "LA CADENA NO ES VALIDA!";
		                break;
		            } else {
		                cout << valorActual[i] << "->" << aux << "  ";
		            }
		        }
		    }
		    cout << "  ===> ";
		}
};


class Cadena{
	private:
		Tabla tabla;
	public:
		
		char value[50];
		
		void generarValoresAleatorios() {
		    int longitud = rand() % 16;
		    if (longitud < 5) {
		        longitud = 5;
		    }
		    
		    for (int i = 0; i < longitud; i++) {
		        char aux;
		        if (i > 1) {
		            aux = '0' + (rand() % 10);
		        } else {
		            aux = (rand() % 2 == 0) ? 'X' : 'Y';
		        }
		        value[i] = aux;
		    }
		    value[longitud] = '\0';
		}
		void validarCadena() {
		    int longitud = strlen(value);
		    cout << "Cantidad de caracteres: " << longitud << endl;
		
		    tabla.imprimir(value);
		
		    if (longitud == 5 || longitud == 7 || longitud == 10 || longitud == 14) {
		        cout << "AFD ACEPTADO" << endl;
		    } else {
		        cout << "AFD NO ACEPTADO" << endl;
		    }
		}
};
