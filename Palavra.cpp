#include "Palavra.h"


Palavra::Palavra()
{
    //ctor
}
std::string Palavra::LetrasCompartilhadas( std::string, std::string){


};

std::string Palavra::SortearPalavra(const std::ifstream &Palavras) {//passando o endereço o arq palavra como parametro 
     // Abrir o arquivo de texto
    std::ifstream arquivo("Palavras.txt");
    //verificar se o arquivo pode ser aberto
    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return "";
    }
// cria uma variável palavras que é um vetor vazio de strings e uma variável palavra que é uma string vazia. Você pode posteriormente manipular e preencher
    std::vector<std::string> palavras;
    std::string palavra;

    // lê continuamente palavras do arquivo e as armazena no vetor palavras até que não haja mais palavras no arquivo para ler.

    while (arquivo >> palavra) { //será executado enquanto o operador >>  for bem-sucedido na leitura de uma palavra do arquivo  palavra. O operador >> é usado para ler dados do arquivo( ele lê palavras uma por uma até que não haja mais palavras para ler)
        palavras.push_back(palavra);//(loop)cada palavra lida é adicionada ao vetor palavras usando a função push_back.
    }

    arquivo.close();//fecha o arquivo

    // Verificar se há palavras no vetor
    if (palavras.empty()) {
        std::cout << "O arquivo não contém palavras." << std::endl;
        return "";
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));//Este é um operador de conversão de tipo. Ele converte o valor retornado por std::time(nullptr) em um tipo unsigned int. 
     // Escolher uma palavra aleatória
    int a = std::rand() % palavras.size();
    return palavras[a];
}



