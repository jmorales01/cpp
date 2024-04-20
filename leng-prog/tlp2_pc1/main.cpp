#include <iostream>
#include <cctype>

using namespace std;

class Parser {
private:
    const string& input;
    size_t pos; // posición actual en la cadena de entrada

    // Función privada para obtener el siguiente token
    char getNextToken() {
        while (pos < input.length() && isspace(input[pos])) {
            ++pos; // ignorar espacios en blanco
        }
        if (pos < input.length()) {
            return input[pos++];
        }
        return '\0'; // fin de la cadena de entrada
    }

    // Función privada para imprimir el paso actual
    void printStep(const string& step) {
        cout << "Paso " << pos << ": " << step << endl;
    }

    // Función privada para reconocer los símbolos no terminales de la gramática
    bool S() {
        printStep("S -> E");
        return E() && pos == input.length(); // debe haber consumido toda la cadena
    }

    bool E() {
        printStep("E -> T");
        if (!T()) return false;
        while (input[pos] == '+' || input[pos] == '-') {
            char op = getNextToken(); // obtener el operador
            printStep("E -> " + string(1, op) + " T");
            if (!T()) return false;
        }
        return true;
    }

    bool T() {
        printStep("T -> F");
        if (!F()) return false;
        while (input[pos] == '*' || input[pos] == '/') {
            char op = getNextToken(); // obtener el operador
            printStep("T -> " + string(1, op) + " F");
            if (!F()) return false;
        }
        return true;
    }

    bool F() {
        printStep("F -> num");
        char next = getNextToken();
        if (next == '(') {
            printStep("F -> ( E )");
            bool result = E(); // recursión para manejar expresiones entre paréntesis
            if (input[pos] != ')') return false; // falta paréntesis de cierre
            ++pos; // consumir paréntesis de cierre
            return result;
        } else if (isdigit(next)) {
            // Si es un dígito, simplemente avanzamos
            while (isdigit(input[pos])) {
                ++pos;
            }
            return true;
        } else {
            // Si no es ni paréntesis ni dígito, no es válido
            return false;
        }
    }

public:
    // Constructor que toma la cadena de entrada
    Parser(const string& str) : input(str), pos(0) {}

    // Método público para iniciar el análisis sintáctico descendente
    bool parse() {
        return S();
    }
};

int main() {
    string input = "2+3*(4-1)";
    Parser parser(input);
    if (parser.parse()) {
        cout << "La cadena de entrada es valida." << endl;
    } else {
        cout << "La cadena de entrada no es valida." << endl;
    }
    return 0;
}