#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Palavra.h"

using namespace std;

int main()
{
    Palavra P;

    // ler todas as palavras em um array
    const int Tam = 1471; // quantidade de palavras presente no arquivo




   // ifstream arq;
    //arq.open("Palavra.txt");

   // string let[Tam];
    // vamos manter esse vector é tipo uma matriz de strings (estrutura 2d)
   // vector<vector<string>> crowssword;
    // interar um vetor em outro vetor
    std::string palavraSorteada = SortearPalavra("Palavras.txt");
    if (!palavraSorteada.empty()) {
        std::cout << "Palavra sorteada: " << palavraSorteada << std::endl;
    }
}
