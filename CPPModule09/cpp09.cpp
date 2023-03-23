#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Error: Argumento faltante\n";
    return 1;
  }

  stack<int> pila;

  string expresion = argv[1];

  for (int i = 0; i < expresion.length(); i++) {
  	char token = expresion[i];
    if (isdigit(token)) {
      int numero = token - '0';
      if (numero >= 10) {
        cout << "Error: Operandos mayores que 9\n";
        return 1;
      }
      pila.push(numero);
    } else if (token == '+' || token == '-' || token == '*' || token == '/') {
      if (pila.size() < 2) {
        cout << "Error: Sintaxis incorrecta\n";
        return 1;
      }
      int op2 = pila.top();
      pila.pop();
      int op1 = pila.top();
      pila.pop();
      int resultado;
      switch (token) {
        case '+':
          resultado = op1 + op2;
          break;
        case '-':
          resultado = op1 - op2;
          break;
        case '*':
          resultado = op1 * op2;
          break;
        case '/':
          if (op2 == 0) {
            cout << "Error: División por cero\n";
            return 1;
          }
          resultado = op1 / op2;
          break;
      }
      pila.push(resultado);
    }
  }

  if (pila.size() != 1) {
    cout << "Error: Sintaxis incorrecta\n";
    return 1;
  }

  cout << pila.top() << endl;

  return 0;
}