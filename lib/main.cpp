#include <iostream>
#include "SparseMatrix.h"
#include <fstream> // Para operações com arquivos
#include <sstream> // Para operações com strings

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
      m = SparseMatrix(linhas, colunas);


        // Lê as triplas (i, j, valor) do arquivo e insere os elementos na matriz.
        int i, j;
        double valor;
        while (arquivo >> i >> j >> valor) {
            m.insert(i, j, valor);
        }

        arquivo.close();
    }

SparseMatrix sum(SparseMatrix& A, SparseMatrix& B) {
    if (A.getLinha() != B.getLinha() || A.getColuna() != B.getColuna()) {
        throw std::invalid_argument("Dimensões das matrizes não são iguais");
    }

    SparseMatrix C(A.getLinha(), A.getColuna());

    // Somar os valores da matriz A na matriz C
    for (int i = 1; i <= A.getLinha(); i++) {
        for (int j = 1; j <= A.getColuna(); j++) {
            double valorA = A.get(i, j);
            if (valorA != 0) {
                C.insert(i, j, valorA);
            }
        }
    }

    // Somar os valores da matriz B na matriz C
    for (int i = 1; i <= B.getLinha(); i++) {
        for (int j = 1; j <= B.getColuna(); j++) {
            double valorB = B.get(i, j);
            if (valorB != 0) {
                double valorC = C.get(i, j);
                C.insert(i, j, valorC + valorB);
            }
        }
    }

    return C;
}


int main(){
SparseMatrix matrizA;
    SparseMatrix matrizB;

    // Nome dos arquivos de entrada
    std::string nomeArquivoA = "matrizA.txt";
    std::string nomeArquivoB = "matrizB.txt";

    // Lê as matrizes esparsas dos arquivos
    readSparseMatrix(matrizA, nomeArquivoA);
    readSparseMatrix(matrizB, nomeArquivoB);

    // Imprime as matrizes lidas dos arquivos
    std::cout << "Matriz A:\n";
    matrizA.print();
    std::cout << "\nMatriz B:\n";
    matrizB.print();

    // Soma as matrizes A e B
    SparseMatrix matrizC = sum(matrizA, matrizB);

    // Imprime a matriz resultante da soma
    std::cout << "\nMatriz C (A + B):\n";
    matrizC.print();

    return 0;
}
