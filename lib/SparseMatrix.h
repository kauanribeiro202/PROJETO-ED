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

    //cria os cabeçalhos das linhas
    Node* aux = m_head;
    for (int i=1; i<n; i++){
        Node* m_cab = new Node(nullptr, nullptr, 0, i, 0.0);
        m_cab->abaixo = m_cab;
        aux->direita = m_cab;
        aux = m_cab;
    }

    //cria os cabeçalhos das colunas
    aux = m_head;
    for (int i=1; i<n; i++){
        Node* m_cab = new Node(nullptr, nullptr, i, 0, 0.0);
        m_cab->direita = m_cab;
        aux->abaixo = m_cab;
        aux = m_cab;
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
void insert(int n, int m, double value)
{
    if(m> Linha or n> Coluna or m<1 or n<1){
        std::__throw_out_of_range("fora de escopo");
        return;
    }
        if (value == 0)
            return;

    //chega na linha de inserção
    Node* l_atual = m_head->abaixo;
    while(l_atual->linha != m and l_atual->abaixo = m_head){
        l_atual = l_atual->abaixo;
    }
    //chega na coluna de inseção
    Node* c_atual - m_head->direita;
    while (c_atual->coluna != n and c_atual->direita != m_head){
        c_atual = c_atual->direita;
    }
    
    Node* aux = l_atual;
    while(l_atual->direita != l_atual and aux->direita->coluna < n){
        aux = aux->direita;
    }

    if(aux->direita->coluna == n){
        aux->direita->valor = value;
    } else {
        Node* inserted = new Node(aux->direita, c_atual->abaixo, m, n, value);
        aux->direita = inserted;
        c_atual->abaixo = inserted;
    } 
    
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