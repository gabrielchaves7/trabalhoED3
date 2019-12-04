#include <iostream>
#include "hash.h"

struct no {
	NoHash *valor;
	struct no* ant;
	struct no* prox;
};
typedef struct no No;

No* inicializaNovoNo(NoHash *valor) {
	No *no = new No();
	no->valor = valor;
	return no;
}

class Lista 
{ 
    int tamanho = 0;
	No *inicio;

public: 
    void inserir(NoHash *valor); 
	void inserirNaPosicao(int position, NoHash *valor); 
    void inicializaLista(int tamanho);
    void acharElemento(string valor);
    void imprimeLista();

	int hashFunction(NoHash *x) { 
        return x->palavra.length();
	} 
}; 

No* inicializaNoVazio(){
    NoHash *hashAtual = inicializaNovoNoHash("");
    No *novoNo = inicializaNovoNo(hashAtual);
    return novoNo;
}

void Lista::inicializaLista(int tamanho){
    this->tamanho = tamanho;
    No *novoNo = inicializaNoVazio();
    this->inicio = novoNo;
    No *noAtual = this->inicio;
    for(int i =0; i < tamanho; i++){
        noAtual->prox = inicializaNoVazio();
        noAtual = noAtual->prox;
    }
}

void Lista::inserirNaPosicao(int position, NoHash *valor){
    No *noAtual = this->inicio;
    for(int i= 0; i < position - 1; i ++){
     noAtual = noAtual->prox;   
    }

    if(noAtual->valor->palavra == "" && noAtual->valor->contador == 0){
        noAtual->valor = valor;
        noAtual->valor->contador = 1;
    } else {
        NoHash *segundoNo = noAtual->valor;
        while(true){            
            if(segundoNo->palavra.compare(valor->palavra)  == 0){
                segundoNo->contador = segundoNo->contador + 1;
                break;
            } else if(segundoNo->prox == NULL){
                valor->contador = 1;
                segundoNo->prox = valor;
                break;
            }

            segundoNo = segundoNo->prox;
        }
    }
}

void Lista::inserir(NoHash *valor){
    int posicao = hashFunction(valor);
    inserirNaPosicao(posicao, valor);
}

void Lista::acharElemento(string valor){
    int posicao = valor.length();
    No *noAtual = this->inicio;
    for(int i= 0; i < posicao - 1; i ++){
        noAtual = noAtual->prox;   
    }

    NoHash *noHashAtual = noAtual->valor;
    while(noHashAtual->palavra != valor){
        noHashAtual = noHashAtual->prox;
    }

    cout << noHashAtual->contador << "\n";
}

void Lista::imprimeLista(){
    No *noAtual = this->inicio;
    for(int i=0; i<this->tamanho; i ++){

        if(noAtual->valor->contador > 0)
            cout << noAtual->valor->palavra << " " << noAtual->valor->contador << "\n";

        if(noAtual->valor->prox != NULL){
            NoHash *segundoNo = noAtual->valor->prox;
            while(segundoNo != NULL){
                cout << segundoNo->palavra << " " << segundoNo->contador << "\n";
                segundoNo = segundoNo->prox;
            }
        }

        noAtual = noAtual->prox;
    }
}