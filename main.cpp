#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Palavra.h"

using namespace std;

int main()
{

    // ler todas as palavras em um array
    const int Size = 11; // quantidade de palavras presente no arquivo

    ifstream arq;
    arq.open("Palavra.txt");

    string let[Size];
    // vamos manter esse vector é tipo uma matriz de strings (estrutura 2d)
    vector<vector<string>> crowssword;
    // interar um vetor em outro vetor
    crowssword.resize(Size);

    for (int i; i < 10; i++)
    {
        crowssword[i].resize(Size);
    }
    string linha;
    int cont = 0;
    while (getline(arq, linha))
    {
        // colocaremos cada palavra em um indice assim amarzenando cada palavra em uma linha
        let[cont] = linha;
        cont++;
    }
// variavel de contador 
    return 0;
}
