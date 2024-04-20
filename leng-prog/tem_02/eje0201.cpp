#include <iostream>

using namespace std;
struct nodo
{
    int dato;
    nodo *der;
    nodo *izq;
};

nodo *crearNodo(int dato){
    nodo *aux=new nodo();
    aux->dato=dato;
    aux->der=aux->der=NULL;
    return aux;
}

void insertarNodo(nodo *&arbol, int dato){
    if(arbol==NULL){
        nodo *aux=crearNodo(dato);
        arbol=aux;
    }else{
        int valR=arbol->dato;
        if(dato<valR) insertarNodo(arbol->izq,dato);
        else insertarNodo(arbol->der,dato);
    }
}

int main(){
    cout<<"Principal";
    int dato,opc;
    nodo *arbol=NULL;
    do{
        cout<<"###### MENU ######\n";
        cout<<"1. Insertar\n";
        cout<<"0. Salir\n";
        switch(opc){
            case 1:
                cout<<"Ingrese el dato a insertar: ";
                cin>>dato;
                insertarNodo(arbol,dato);
                break;
            default:
                cout<<"Opcion no valida";
                break;
        }
    }while(opc==0);
    return 0;
}