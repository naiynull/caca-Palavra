#include "Palavra.h"


Palavra::Palavra()
{
    //ctor
}


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
         if (palavra.length() == 10) {
             palavras.push_back(palavra); // Adiciona a palavra à lista, 
            //(loop)cada palavra lida é adicionada ao vetor palavras usando a função push_back.Para modificar o código de modo a selecionar 10 palavras com apenas um caractere igual ao da palavra sorteada, você pode fazer a seguinte alteração na função `Palavra::Selecionadas`:
        }
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

/*std::vector<std::string> Palavra::Selecionadas(const std::string &palavraSorteada, const std::vector<std::string> &listaPalavras) {
    std::vector<std::string> palavrasSelecionadas;
    //Iterar através do vetor de palavras
    for (const std::string &palavra : listaPalavras) {
        if (palavra.length() == palavraSorteada.length()) {
            bool caracteresIguais = true;
         // Verificar se a palavra atual tem o mesmo número de caracteres da palavra sorteada
            for (size_t i = 0; i < palavra.length(); ++i) {
                 // Verificar se os caracteres são iguais
                if (palavra[i] != palavraSorteada[i]) {
                    caracteresIguais = false;
                    break;
                }
            }
            // Se os caracteres forem iguais, adiciona a palavra ao vetor de palavras selecionadas
            if (caracteresIguais) {
                palavrasSelecionadas.push_back(palavra);
            }
        }
    }

    return palavrasSelecionadas;
}*/

std::string Palavra::Selecionadas(const std::string &palavra, int indice) {
    if (indice >= 0 && indice < palavra.length()) {
        char letra = palavra[indice];
        // Agora você pode fazer algo com a letra selecionada, como procurar outra palavra no vetor 'palavras' com a mesma letra
        for (const std::string &outraPalavra : palavra) {
            if (outraPalavra.find(letra) != std::string::npos) {
                return outraPalavra;
            }
        }
    }
    // Se o índice estiver fora do intervalo da palavra ou se nenhuma palavra correspondente for encontrada, retorne uma string vazia.
    return "";
}










