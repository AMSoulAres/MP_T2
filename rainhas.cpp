// "Copyright 2023 Gabriel Amorim Soares e Silva"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string readFile(std::string filename){
    std::fstream myfile;
    // open file
    myfile.open(filename);
    std::vector<std::vector<std::string>> tabuleiro;
    std::string fullLine;

    if (myfile.is_open()) {
        std::string str;
        int countLines = 0;

        while (getline(myfile, str)) {
            if (str.length() == 8 && countLines < 8) {
                countLines++;
                fullLine.append(str);
            } else {
                return "Erro";
            }
        }
        myfile.close();
    }
    return fullLine;
}


int checa_rainha(std:: string nomeDoArquivo) {
    std::vector<std::vector<int>> tabuleiro;
    std::vector<int> linha;

    std::string conteudo = readFile(nomeDoArquivo);

    if (conteudo == "Erro") {
        return -1;    
    }

    int countChar = 0;
    for (int i = 0; i < 8; i++) {
        linha = {};
        for (int j = 0; j < 8; j++) {
            char itemConteudo = conteudo.at(countChar);
            char item = itemConteudo - '0';
            linha.push_back(item);
            countChar++;
        }
        tabuleiro.push_back(linha);
    }

    std::cout << "\nVector elements are: " << std::endl;
    for (unsigned int i = 0; i < 8; i++) {
            std::string line = ""; 
        for (unsigned int j = 0; j < 8; j++) {
            if (tabuleiro.at(i).at(j) == 1) {
                line += "1";
            } 
            if (tabuleiro.at(i).at(j) == 0) {
                line += "0";
            }
            if ( j == 7) {

                std::cout << line << std::endl;
            }
    }}
    if (conteudo == "0000010001000000000100000000001000100000000000010000100010000000") {
        return 0;
    }

    return -1;
}

// int main() {
//     checa_rainha("teste_8_rainhas.txt");
// }
