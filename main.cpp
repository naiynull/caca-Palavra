#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

class Palavra {
private:
    std::string selecionada;
    std::string palavras[10]; // Matriz de 10 linhas
    char grade[10][50]; // Matriz de 10 linhas e 50 colunas

public:
    const char *wordcenter;

    std::string GetSeleciona() {
        return selecionada;
    }

    std::string GetPalavras(int index) {
        return palavras[index];
    }

    std::string Centralpala(const char *wordcenter) {
        const int numPalavras = 1471;
        std::string Palavras; // Declare a variável para armazenar as palavras

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

    void sortearpalavra(const char *wordcenter) {
        Centralpala(wordcenter); // Chama Centralpala para selecionar a palavra
        std::string palavraSelecionada = GetSeleciona();
        while (!palavraSelecionada.empty()) {
        int Total = 0;
        int palavrassort = 0;
        int j=0;
        std::string pala[10];
        std::ifstream arq(word);

        // Ler todas as palavras do arquivo
        if (arq >> Palavras) {
            Total++;
            // Verificar se a palavra tem 10 caracteres
            if (Palavras[i] == selecionada[j]) {
                palavrassort++;
                j++;
            }
                i++;

                // Com probabilidade 1/palavrasDe10Caracteres, escolher esta palavra
                if (rand() % palavrassort == 0) {
                    pala = Palavras;
                }
        }

        } else {
            std::cout << "Nenhuma palavra com 10 caracteres encontrada em sortearpalavra." << std::endl;
        }
    }

  void PreencherMatriz() {
    // Verifique se a palavra selecionada tem exatamente 10 caracteres
    if (selecionada.length() != 10) {
        std::cerr << "A palavra selecionada não tem 10 caracteres." << std::endl;
        return;
    }

    // Encontre o ponto de partida para a vertical no centro da matriz (linha 5)
    int inicioVertical = 5 - selecionada.length() / 2;

    // Preencha a matriz com a palavra "centralpala" na vertical
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            if (j == 25 && i >= inicioVertical && i < inicioVertical + selecionada.length()) {
                grade[i][j] = selecionada[i - inicioVertical];
            } else {
                grade[i][j] = '_'; // Preenche com '.' fora da vertical
            }
        }
    }
}


    void ExibirMatriz() {
        std::cout << "Caça-Palavras:" << std::endl;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 50; j++) {
                std::cout << grade[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    srand(time(NULL));
    const char* word = "Palavras.txt";
    std::cout<<"oi";
    Palavra P;
    P.sortearpalavra(word);
    P.PreencherMatriz();
    P.ExibirMatriz();
    return 0;
}
