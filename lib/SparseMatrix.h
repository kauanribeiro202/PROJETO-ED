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
    for (int i=1; i<=n; i++){
        Node* m_cab = new Node(nullptr, nullptr, 0, i, 0.0);
        m_cab->abaixo = m_cab;
        aux->direita = m_cab;
        aux = m_cab;
    }

    //cria os cabeçalhos das colunas
    aux = m_head;
    for (int i=1; i<=m; i++){
        Node* m_cab = new Node(nullptr, nullptr, i, 0, 0.0);
        m_cab->direita = m_cab;
        aux->abaixo = m_cab;
        aux = m_cab;
    }

}

//construtor sem parametro
SparseMatrix() {
        this->Linha = 1;
        this->Coluna = 1;

        m_head = new Node(nullptr, nullptr, 0, 0, 0.0);
        m_head->abaixo = m_head;
        m_head->direita = m_head;

        // Criação do cabeçalho da única linha
        Node* m_cab = new Node(nullptr, nullptr, 0, 1, 0.0);
        m_cab->abaixo = m_cab;
        m_head->direita = m_cab;

        // Criação do cabeçalho da única coluna
        m_cab = new Node(nullptr, nullptr, 1, 0, 0.0);
        m_cab->direita = m_cab;
        m_head->abaixo = m_cab;
    }

//destrutor
~SparseMatrix(){
clear();

// Desalocar todas as colunas da primeira linha separadamente
Node* colAtual = m_head->direita;
        while (colAtual != m_head) {
            Node* colTemp = colAtual;
            colAtual = colAtual->direita;
            delete colTemp;
        }

// Finalmente, desalocar o nó principal
delete m_head;
}

//funcao auxiliar clear
void clear(){
    // Desalocar todas as colunas de cada linha
        Node* linhaAtual = m_head->abaixo;
        while (linhaAtual != m_head) {
            Node* colAtual = linhaAtual->direita;
            while (colAtual != linhaAtual) {
                Node* colTemp = colAtual;
                colAtual = colAtual->direita;
                delete colTemp;
            }
            Node* linhaTemp = linhaAtual;
            linhaAtual = linhaAtual->abaixo;
            delete linhaTemp;
        }
}

//insert, busca a cordenada a qual deve inserir o valor e aloca ele la, se ja estiver preenchida, apenas substitui SEM ALOCAR NOVO NO
void insert(int n, int m, double valor)
{
    if (n > Linha || m > Coluna || n < 1 || m < 1) {
        std::__throw_out_of_range("fora de escopo");
        return;
    }
    if (valor == 0)
        return;

    // Chega na linha de inserção
    Node* l_atual = m_head->abaixo;
    while (l_atual->linha != n && l_atual->abaixo != m_head) {
        l_atual = l_atual->abaixo;
    }

    // Chega na coluna de inserção
    Node* c_atual = m_head->direita;
    while (c_atual->coluna != m && c_atual->direita != m_head) {
        c_atual = c_atual->direita;
    }
    
    Node* aux = l_atual;//Começa na linha correta.
    
    //Percorre as colunas na linha correta até encontrar a posição de inserção.
    while (aux->direita != l_atual && aux->direita->coluna < m) {
        aux = aux->direita;
    }
    
    //Se o nó já existir na posição, atualiza o valor
    if (aux->direita->coluna == m) {
        aux->direita->valor = valor;
    } else {
        //Caso contrário, insere um novo nó na posição correta e ajusta os ponteiros direita e abaixo.
        Node* inserted = new Node(aux->direita, c_atual->abaixo, n, m, valor);
        aux->direita = inserted;
        c_atual->abaixo = inserted;
    } 
}

//busca a coordenada solicitada e retorna  seu valor, se a coordenad nao existir retorna 0
double get(int n, int m) {
    if (n > Linha || m > Coluna || n < 1 || m < 1) {
        std::__throw_out_of_range("fora de escopo");
        return 0;
    }

    // Chega na linha correta
    Node *l_atual = m_head->abaixo;
    while (l_atual != m_head && l_atual->linha != n) {
        l_atual = l_atual->abaixo;
    }

    // Se a linha não for encontrada, retorna 0
    if (l_atual == m_head) {
        return 0;
    }

    // Chega na coluna correta dentro da linha
    Node *c_atual = l_atual->direita;
    while (c_atual != l_atual && c_atual->coluna != m) {
        c_atual = c_atual->direita;
    }

    // Se a coluna não for encontrada, retorna 0
    if (c_atual == l_atual) {
        return 0;
    }

    // Retorna o valor armazenado na posição (n, m)
    return c_atual->valor;
}



void print() {
    Node *auxl = m_head->abaixo;

    for (int i = 1; i <= Linha; i++) {
        Node *auxc = auxl->direita;

        for (int j = 1; j <= Coluna; j++) {
            if (auxc->linha == i && auxc->coluna == j) {
                std::cout << auxc->valor << " ";
                auxc = auxc->direita;
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
        auxl = auxl->abaixo;
    }
}


//funcao opcional de atribuicao
SparseMatrix& operator=(const SparseMatrix& matriz) {
        if (this != &matriz) {
            this->clear();
            this->Linha = matriz.Linha;
            this->Coluna = matriz.Coluna;

            Node* linhaAtual = matriz.m_head->abaixo;
            while (linhaAtual != matriz.m_head) {
                Node* colAtual = linhaAtual->direita;
                while (colAtual != linhaAtual) {
                    this->insert(colAtual->linha, colAtual->coluna, colAtual->valor);
                    colAtual = colAtual->direita;
                }
                linhaAtual = linhaAtual->abaixo;
            }
        }
        return *this;
    }

//funcao opcional de igualdade
bool operator==(const SparseMatrix& matriz) const {
        if (this->Linha != matriz.Linha || this->Coluna != matriz.Coluna) {
            return false;
        }

        Node* linhaAtual = this->m_head->abaixo;
        Node* linhaOutra = matriz.m_head->abaixo;
        while (linhaAtual != this->m_head) {
            Node* colAtual = linhaAtual->direita;
            Node* colOutra = linhaOutra->direita;
            while (colAtual != linhaAtual) {
                if (colAtual->linha != colOutra->linha || colAtual->coluna != colOutra->coluna || colAtual->valor != colOutra->valor) {
                    return false;
                }
                colAtual = colAtual->direita;
                colOutra = colOutra->direita;
            }
            linhaAtual = linhaAtual->abaixo;
            linhaOutra = linhaOutra->abaixo;
        }
        return true;
    }

//funcao opcional de desigualdade
bool operator!=(const SparseMatrix& matriz) const {
    return !(*this == matriz);
}

int getLinha(){
return Linha;
}

int getColuna(){
return Coluna;
}

};

#endif
