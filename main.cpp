#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

class Palavra {
private:
    std::string selecionada;
    std::string Palavras;

public:
    const char *wordcenter;

    std::string GetSeleciona() {
        return selecionada;
    }

    std::string GetPalavras() {
        return Palavras;
    }

    std::string Centralpala(const char *wordcenter) {
        const int numPalavras = 1471;

        std::ifstream arq(wordcenter);

        if (!arq.is_open()) {
            std::cerr << "Erro ao abrir o arquivo." << std::endl;
            return "";
        }

        int Total = 0;
        int palavrasDe10Caracteres = 0;

        // Ler todas as palavras do arquivo
        while (arq >> Palavras) {
            Total++;

            // Verificar se a palavra tem 10 caracteres
            if (Palavras.length() == 10) {
                palavrasDe10Caracteres++;

                // Com probabilidade 1/palavrasDe10Caracteres, escolher esta palavra
                if (rand() % palavrasDe10Caracteres == 0) {
                    selecionada = Palavras;
                }
            }
        }

        arq.close();

        if (!selecionada.empty()) {
            // Imprimir a palavra selecionada aleatoriamente com 10 caracteres
            std::cout << "Palavra selecionada aleatoriamente: " << selecionada << std::endl;
        } else {
            std::cout << "Nenhuma palavra com 10 caracteres encontrada." << std::endl;
        }
        return selecionada;
    }
 void GerarPalavra(const char* word) {
        const int numPalavras = 10;
        std::ifstream arq(word);
        if (!arq.is_open()) {
            std::cerr << "Erro ao abrir o arquivo." << std::endl;
            return;
        }

        std::string selecionadas[numPalavras];
        int Total = 0;

        // Ler todas as palavras do arquivo
        while (arq >> Palavras) {
            Total++;
        
            // Se ainda não selecionamos 10 palavras aleatórias, escolha esta palavra
            if (Total <= numPalavras) {
                selecionadas[Total - 1] = Palavras;
            } else {
                // Com probabilidade 10/Total, substitua uma das palavras aleatórias já escolhidas
                int let = rand() % Total;
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

    void sortearpalavra(const char *wordcenter) {
        std::string palavraprincipal = Centralpala(wordcenter); // Chama Centralpala para selecionar a palavra
       std::string palavraSelecionada = GetSeleciona();
        if (!palavraSelecionada.empty()) {
            // Imprimir a palavra selecionada aleatoriamente com 10 caracteres
            std::cout << "Palavra selecionada em sortearpalavra: " << palavraSelecionada << std::endl;
        } else {
            std::cout << "Nenhuma palavra com 10 caracteres encontrada em sortearpalavra." << std::endl;
        }
    }
};

int main() {
    srand(time(NULL));
    const char* word = "Palavras.txt";
    Palavra P;
    P.GerarPalavra(word);
    P.sortearpalavra(word);
    return 0;
}
