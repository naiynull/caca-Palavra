#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
class Palavra
{
    public:
        Palavra();
        //comparar duas strings e determinara o numero de letras que são comuns entre as duas e transformarar as letras comuns e uma nova string
       std::string SortearPalavra(const std::ifstream&); 
     std::string Selecionadas(const std::string &, int);
    private:
    std::string palavra;
    std::string letrasReveladas;
};
