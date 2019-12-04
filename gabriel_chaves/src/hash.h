#include<iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
const int MAX_LENGTH = 64;

struct noHash {
    string palavra = "";
	int contador = 0;
	struct noHash* prox;
};
typedef struct noHash NoHash;

NoHash* inicializaNovoNoHash(string palavra) {
	NoHash *no = new NoHash();
	no->palavra = palavra;
	no->contador = 0;
	return no;
}

