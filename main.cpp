#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

void GerarPalavra(const char* Palavra) {
    const int numPalavras = 10;
    std::string selecionadas[numPalavras];

    std::ifstream arq(Palavra);

    if (!arq.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    // Seed para geração de números aleatórios
    std::srand(std::time(nullptr));

    std::string Palavras;
    int Total = 0;

    // Ler todas as palavras do arquivo
    while (arq >> Palavras) {
        Total++;

        // Se ainda não selecionamos 10 palavras aleatórias, escolha esta palavra
        if (Total <= numPalavras) {
            selecionadas[Total - 1] = Palavras;
        } else {
            // Caso contrário, substitua uma das palavras aleatórias já escolhidas com probabilidade 10/Total
            int let = std::rand() % Total;
            if (let < numPalavras) {
                selecionadas[let] = Palavras;
            }
        }
    }

    arq.close();

    // Imprimir as 10 palavras selecionadas aleatoriamente
    for (int i = 0; i < numPalavras; i++) {
        std::cout << selecionadas[i] << std::endl;
    }
}

string PalavraCentral()

int main() {
    const char* Palavra = "Palavras.txt";
    GerarPalavra(Palavra);
    return 0;
}
