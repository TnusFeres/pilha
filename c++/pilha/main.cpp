#include <iostream>
#include <stack>
#include <string>

bool corresponde(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') || (abertura == '[' && fechamento == ']');
}

bool validaExpressao(const std::string &expressao) {
    std::stack<char> pilha;

    for (char ch : expressao) {

        if (ch == '(' || ch == '[') {
            pilha.push(ch);
        }
        else if (ch == ')' || ch == ']') {
            if (pilha.empty()) {
                return false;
            }
            char topo = pilha.top();
            pilha.pop();
            if (!corresponde(topo, ch)) {
                return false;
            }
        }
    }

    return pilha.empty();
}

int main() {
    std::string expressao;

    std::cout << "Digite uma expressão matemática: ";
    std::getline(std::cin, expressao);

    if (validaExpressao(expressao)) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "Errado" << std::endl;
    }

    return 0;
}
