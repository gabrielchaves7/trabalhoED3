#include <cstdio>
#include "lista.h"
using namespace std; 

int main() {
  int n;
  scanf("%d", &n);
  char word[64];
  Lista lista;
  lista.inicializaLista(65);
  for (int i = 0; i < n; ++i) {
    scanf("%s", word);
    string palavra(word);
    NoHash *no = inicializaNovoNoHash(palavra);    
    lista.inserir(no);
  }

  char op;  // CUIDADO para não ler o '\n' ao invés da operação
            // o espaço antes do %c está lá pra isso
  while (scanf(" %c %s", &op, word) != EOF) {
    if (op == 'q')
        lista.acharElemento(word);
  }
  return 0;
}
