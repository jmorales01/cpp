#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class AFD {
public:
    AFD() : state(0) {}

    bool accept(const std::string& input) {
        state = 0;
        for (size_t i = 0; i < input.length(); ++i) {
        	char c = input[i];
            switch (state) {
                case 0:
                    if (c == 'X') {
                        state = 1;
                    } else if (c == 'Y') {
                        state = 2;
                    } else {
                        return false;
                    }
                    break;
                case 1:
                    if (c == 'Y') {
                        state = 3;
                    } else if (isdigit(c) && c >= '0' && c <= '9') {
                        state = 1;
                    } else {
                        return false;
                    }
                    break;
                case 2:
                    if (c == 'X') {
                        state = 4;
                    } else if (isdigit(c) && c >= '0' && c <= '9') {
                        state = 2;
                    } else {
                        return false;
                    }
                    break;
                case 3:
                    if (isdigit(c) && c >= '0' && c <= '9') {
                        state = 3;
                    } else {
                        return false;
                    }
                    break;
                case 4:
                    if (isdigit(c) && c >= '0' && c <= '9') {
                        state = 4;
                    } else {
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        return (state == 3 || state == 4) && (input.length() % 5 == 0 || input.length() % 7 == 0) && input.length() >= 5 && input.length() <= 15;
    }

private:
    int state;
};

int main() {
    std::srand(std::time(0));

    for (int i = 0; i < 15; i++) {
        AFD afd;
        std::string input;
        int length = ((std::rand() % 15) / 5 + 1) * 5;  // Múltiplo de 5
        for (int j = 0; j < length; j++) {
            if (j == 0) {
                input += (std::rand() % 2 == 0) ? 'X' : 'Y';
            } else if (j == 1) {
                input += (input[0] == 'X') ? 'Y' : 'X';
            } else {
                input += (std::rand() % 10) + '0';
            }
        }

        std::string resultado = (afd.accept(input)) ? "Aceptada" : "Rechazada";
        std::cout << resultado << ": " << input << std::endl;
    }

    std::string customInput;
    std::cout << "Ingrese una cadena de texto personalizada: ";
    std::cin >> customInput;

    AFD afd;
    std::string resultado = (afd.accept(customInput)) ? "Aceptada" : "Rechazada";
    std::cout << resultado << ": " << customInput << std::endl;

    return 0;
}
