#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Palavra.h"

using namespace std;
void Menu(){
    system("clear");
    cout<<"Escolha o nível de dificuldade:\n";
    cout<<"1.facil\n";
    cout<<"2.Medío\n";
    cout<<"3.Difícil\n";
}

int main()
{
    Menu();
 Palavra P;
   int i;
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

    std::string palavraSorteada =P.SortearPalavra(arq);// palavra sorteada recebe o arquivo ou seja o endereço de memoria do meu arquivo que esta na função SortearPalavra

    if(!palavraSorteada.empty()) {// se não estiver vazia 
        cout << "Palavra sorteada: " << palavraSorteada << endl;// vai mostrar a palavra sorteada 

        // Print each letter vertically
        for (size_t i = 0; i < palavraSorteada.length(); i++) {// para representar tamanhos de objetos ou índices de arrays.
        // ele só pode representar valores não negativos
        //A variável i é declarada como size_t para ser usada como um índice para percorrer cada caractere da string palavraSorteada. 
        //o método length() de uma string retorna um valor do tipo size_t,tornando mais apropriado para comparações e iterações relacionadas ao tamanho de strings.
            cout << palavraSorteada[i] << endl;
        }
      
    std::string palavraSelecionada =P.Selecionadas(palavraSorteada, i);
            std::cout << "Palavra com letra no índice " << i << ": " << palavraSelecionada << std::endl;
        
        }else {
        cerr << "Nenhuma palavra disponível." << endl;
    }

    arq.close();
    return 0;
}



