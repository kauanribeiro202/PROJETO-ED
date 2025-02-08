#include <iostream> 
#include "SparseMatrix.h"
#include <fstream>//para ler o txt

//soma os elementos da matriz, tem um jeito especifico de fazer
SparseMatrix soma(SparseMatrix& a, SparseMatrix& b){
    SparseMatrix c;

    return c;
}

//MUltiplica os elementos, tambem tem um jeito especifico de fazer
SparseMatrix multiplicacao(SparseMatrix& a, SparseMatrix& b){
    SparseMatrix c;

    return c;
}

//recebe uma matriz vazia e le o arquivo de texto usando o fstream
void readSparseMatrix(SparseMatrix& m, const std::string& nomeArquivo) {
        //Abre o arquivo especificado pelo nome nomeArquivo e verifica se ele foi aberto corretamente.
        std::ifstream arquivo(nomeArquivo);

        if (!arquivo) {
            std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
            return;
        }
        //Lê a primeira linha do arquivo, que contém os valores linhas e colunas.
        int linhas, colunas;
        arquivo >> linhas >> colunas;

        // Atualiza as dimensões da matriz
       m = new SparseMatrix (linhas, colunas);


        // Lê as triplas (i, j, valor) do arquivo e insere os elementos na matriz.
        int i, j;
        double valor;
        while (arquivo >> i >> j >> valor) {
            m.insert(i, j, valor);
        }

        arquivo.close();
    }
//main
int main () {

    SparseMatrix* M = new SparseMatrix(4,4);
    M->insert(2,2, 666);

    std::cout<<"teste"<<"\n";

    return 0;
}
