#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cstring>  // Para strlen

class Palavra
{
private:
    std::string selecionada;
    std::string palavras[10]; // Tamanho fixo de 10 para as palavras verticais
    char grade[10][50] = {{0}};
    int tentativasRestantes;
    std::string palavraEncontrada;

public:
    Palavra() : tentativasRestantes(10), palavraEncontrada("") {}

    std::string GetSeleciona()
    {
        return selecionada;
    }

    std::string GetPalavras(int index)
    {
        return palavras[index];
    }

    void DecrementarTentativas()
    {
        tentativasRestantes--;
    }

    int GetTentativasRestantes()
    {
        return tentativasRestantes;
    }

    std::string GetPalavraEncontrada()
    {
        return palavraEncontrada;
    }

    void setPalavraEncontrada(const std::string &palavra)
    {
        palavraEncontrada = palavra;
    }

    std::string Centralpala(const std::string &wordcenter)
    {
        std::ifstream arq(wordcenter);

        if (!arq.is_open())
        {
            std::cerr << "Erro ao abrir o arquivo." << std::endl;
            return "";
        }

        int palavrasValidas = 0;
        std::string palavra;

        while (arq >> palavra)
        {
            if (palavra.length() == 10) // Verifica se a palavra tem tamanho igual a 10
            {
                palavrasValidas++;
                if (rand() % palavrasValidas == 0)
                {
                    selecionada = palavra;
                }
            }
        }

        arq.close();

        if (!selecionada.empty())
        {
            std::cout << "Palavra selecionada aleatoriamente: " << selecionada << std::endl;
        }
        else
        {
            std::cout << "Nenhuma palavra válida encontrada." << std::endl;
        }
        return selecionada;
    }

    void sortearpalavra(const std::string &wordcenter)
    {
        Centralpala(wordcenter);
        std::string palavraSelecionada = GetSeleciona();
        if (!palavraSelecionada.empty())
        {
            std::cout << "Palavra selecionada em sortearpalavra: " << palavraSelecionada << std::endl;
        }
        else
        {
            std::cout << "Nenhuma palavra válida encontrada em sortearpalavra." << std::endl;
        }
    }

    std::string LerPalavrasDoArquivo(const std::string &word10)
    {
        std::ifstream arquivo(word10);
        std::string Palaword;

        if (!arquivo.is_open())
        {
            std::cerr << "Erro ao abrir o arquivo." << std::endl;
            return "";
        }

        std::string palavra;
        while (arquivo >> palavra)
        {
            Palaword += palavra + " ";
        }

        arquivo.close();

        return Palaword;
    }

    std::string encontrapala(char letra)
    {
        for (int i = 0; i < 10; i++)
        {
            if (palavras[i].find(letra) != std::string::npos)
            {
                return palavras[i];
            }
        }
        return "";
    }

    void dezpala()
    {
        for (int i = 0; i < 10; i++)
        {
            int inicioEspaco = 25 - palavras[i].length();
            for (int j = 0; j < 50; j++)
            {
                if (j < inicioEspaco || j >= inicioEspaco + palavras[i].length())
                {
                    std::cout << " ";
                }
                else
                {
                    std::cout << palavras[i][j - inicioEspaco];
                }
            }
            std::cout << std::endl;
        }
    }

    void PreencherMatriz()
    {
        if (selecionada.length() == 0)
        {
            std::cerr << "Nenhuma palavra selecionada." << std::endl;
            return;
        }

        int inicioVertical = 5 - selecionada.length() / 2;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                if (j == 25 && i >= inicioVertical && i < inicioVertical + selecionada.length())
                {
                    grade[i][j] = selecionada[i - inicioVertical];
                }
                else
                {
                    grade[i][j] = '_';
                }
            }
        }
    }

    void ExibirMatriz()
    {
        std::cout << "Caça-Palavras:" << std::endl;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                std::cout << grade[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    bool VerificarVitoria()
    {
        for (int i = 0; i < 10; i++)
        {
            if (palavras[i] != GetSeleciona())
            {
                return false;
            }
        }
        return true;
    }
};


void Menu(){
std::cout << "Escolha a dificuldade:" << std::endl;
std::cout << "1. Fácil " << std::endl;
std::cout << "2. Médio " << std::endl;
std::cout << "3. Difícil " << std::endl;
std::cout << "Digite o número da dificuldade: ";
}
int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    const std::string word = "Palavras.txt";
    int tentativas = 0;

        Menu();
        int op;
        std::cin >> op;

        switch (op) {
            case 1:
                std::cout<<"Você escolheu a opção facíl\n";
                std::cout<<"A opção facíl possui 10 tentativas \n";
                std::cout<<"Boa Sorte!!\n";
                tentativas = 10;
                break;
            case 2:
                std::cout<<"Você escolheu a opção médio\n";
                std::cout<<"A opção facíl possui 8 tentativas \n";
                std::cout<<"Boa Sorte!!\n";
                tentativas = 10;
                break;
            case 3:
                std::cout<<"Você escolheu a opção difícil\n";
                std::cout<<"A opção facíl possui 5 tentativas \n";
                std::cout<<"Boa Sorte!!\n";
                tentativas = 5;
                break;
            default:
                std::cout << "Opção inválida. Por favor, escolha uma opção válida." << std::endl;
        }


    Palavra P;
    P.sortearpalavra(word);
    P.PreencherMatriz();
    P.ExibirMatriz();

    std::string palavraSelecionada = P.GetSeleciona();
    if (!palavraSelecionada.empty()) {
        std::cout << "Adivinhe as palavras cruzadas!" << std::endl;
        std::cout << "Você tem " << tentativas << " tentativas." << std::endl;

        while (tentativas > 0) {
            char letra;
            std::cout << "Digite uma letra: ";
            std::cin >> letra;

            std::string encontrada = P.encontrapala(letra);
            if (!encontrada.empty() && encontrada != P.GetPalavraEncontrada()) {
                std::cout << "Palavra encontrada: " << encontrada << std::endl;
                P.setPalavraEncontrada(encontrada);
            } else {
                std::cout << "Letra incorreta. Você tem " << tentativas - 1 << " tentativas restantes." << std::endl;
                tentativas--;
            }

            if (P.VerificarVitoria()) {
                std::cout << "Você ganhou! Adivinhou todas as palavras cruzadas." << std::endl;
                break;
            }
        }

        if (!P.VerificarVitoria()) {
            std::cout << "Você perdeu! As palavras cruzadas eram: " << std::endl;
            P.dezpala(); // Chama dezpala para imprimir as palavras quando o jogador perde.
        }
    }

    return 0;
}
