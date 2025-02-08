#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "Node.h"
#include <iomanip>
#include <iostream>


class SparseMatrix{
private:
Node* m_head; 
int Linha;
int Coluna;

public:

//n linhas e m colunas, constrtutor com parametro
SparseMatrix(int n, int m)
{
    if(n<=0 or m<=0 or n>30000 or m>30000) {
        std::__throw_out_of_range("valores fora do escopo");
        return;
    }

    this->Linha = n;
    this->Coluna = m;

    m_head = new Node(nullptr, nullptr, 0, 0, 0.0);
    m_head->abaixo = m_head;
    m_head->direita = m_head;

    Node* aux = m_head;
    for (int i=1; i<n; i++) {
        Node* m_cab = new Node(nullptr, nullptr, 0, i, 0.0);
        m_cab->abaixo = m_cab;
        aux->direita = m_cab;
    }



}

//construtor sem parametro
SparseMatrix(){

}

//destrutor
~SparseMatrix(){
clear();

}

//funcao auxiliar clear
void clear(){

}

//insert, busca a cordenada a qual deve inserir o valor e aloca ele la, se ja estiver preenchida, apenas substitui SEM ALOCAR NOVO NO
void insert(int n, int m, double valor){

}

//busca a coordenada solicitada e retorna  seu valor, se a coordenad nao existir retorna 0
double get(int n, int m){


}

//usa a funcao get como auxiliar para printar a funcao
void print(){

}

//funcao opcional de atribuicao
void operator=(SparseMatrix&matriz){

}

//funcao opcional de igualdade
bool operator==(SparseMatrix&matriz){

    return false;
}

//funcao opcional de desigualdade
void operator!=(SparseMatrix&matriz){
    //return (!operator==(matriz));
}

int getLinha(){
return Linha;
}

int getColuna(){
return Coluna;
}

};

#endif