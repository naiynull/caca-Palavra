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
  ifstream arq("Palavras.txt");
 if(!arq.is_open()) {
    cerr << "Erro ao abrir o arquivo de palavras." <<endl;
        
 
    }

    std::string palavraSorteada =P.SortearPalavra(arq);

    if(!palavraSorteada.empty()) {
        std::cout << "Palavra sorteada: " << palavraSorteada << std::endl;
    }else{
        std::cerr << "Nenhuma palavra disponível." << std::endl;
    }

    arq.close();
    return 0;
}
