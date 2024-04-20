#include <iostream>
#include <string.h>

#define q1 1
#define q2 2
#define q3 3
#define q4 4
#define q5 5
#define qE -1

using namespace std;

// Declaración de la función estados
void estados(char c, int &e);

// Declaración de la función procesar
int procesar(char frase[], int &e);

int main(int argc, char** argv) {
    char frase[500];
    int e = q1, x;

    strcpy(frase, "abcaaaaa");
    x = procesar(frase, e);

    cout << "Frase : " << frase << endl;
    cout << "Estado: " << e << endl;
    cout << "Válido: " << x << endl;

    return 0;
}

// Definición de la función estados
void estados(char c, int &e) {
    switch (c) {
        case 'a': case 'b': case 'c':
            if (e == q1) {
                if (c == 'a') e = q2;
                if (c == 'b') e = q3;
                if (c == 'c') e = q5;
            }
            else if (e == q2) {
                e = q5;
            }
            else if (e == q3) {
                if (c == 'a' || c == 'b') e = q4;
                if (c == 'c') e = q5;
            }
            else if (e == q4) {
                e = q5;
            }
            else if (e == q5) e = q5;
            break;
        default:
            e = qE;
            break;
    }
}

// Definición de la función procesar
int procesar(char frase[], int &e) {
    int x = 0;
    for (int i = 0; i < strlen(frase); i++) {
        estados(frase[i], e);
        if (e == qE) {
            x = -1;
            break;
        }
    }
    return x;
}
