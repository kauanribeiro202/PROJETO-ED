#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node {
    Node* direita;
    Node* abaixo;
    int linha;
    int coluna;
    double valor;
    
    Node(Node* direita, Node* abaixo, int linha, int coluna, double valor){
        this->direita = direita;
        this->abaixo = abaixo;
        this->linha = linha;
        this->coluna = coluna;
        this->valor = valor;
    }
};


#endif