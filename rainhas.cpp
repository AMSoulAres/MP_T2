// "Copyright 2023 Gabriel Amorim Soares e Silva"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::string readFile(std::string filename) {
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
        return fullLine;
    }
    return "Erro";
}

std::string checa_ataque(std::vector<std::vector<int>> tabuleiro) {
    for (int linha1 = 0; linha1 < 8; linha1++) {
        for (int coluna1 = 0; coluna1 < 8; coluna1++) {
            if (tabuleiro[linha1][coluna1] == 1) {
                // Verifica ataque na linha
                for (int coluna2 = 0; coluna2 < 8; coluna2++) {
                    if (tabuleiro[linha1][coluna2] == 1 && coluna1 != coluna2) {
                        std::string s1("(");
                        std::string s2(")");
                        std::string s3(",");
                        std::stringstream ss;
                        ss << s1 << linha1 << s3 << coluna1 << s2 << s3 << s1 << linha1 << s3 << coluna2 << s2;
                        std::string resposta = ss.str();
                        return resposta;
                    }
                }
                // Verifica ataque na coluna
                for (int linha2 = 0; linha2 < 8; linha2++) {
                    if (tabuleiro[linha2][coluna1] == 1 && linha1 != linha2) {
                        std::string s1("(");
                        std::string s2(")");
                        std::string s3(",");
                        std::stringstream ss;
                        ss << s1 << linha1 << s3 << coluna1 << s2 << s3 << s1 << linha2 << s3 << coluna1 << s2;
                        std::string resposta = ss.str();
                        return resposta;
                    }
                }
                // Verifica ataque na diagonal principal
                // acima
                int coluna2 = coluna1;
                for (int linha2 = linha1; linha2 < 8; linha2++) {
                    if (tabuleiro[linha2][coluna2] == 1 && linha2 != linha2 && coluna2 != coluna2 && coluna2 < 8) {
                        std::string s1("(");
                        std::string s2(")");
                        std::string s3(",");
                        std::stringstream ss;
                        ss << s1 << linha1 << s3 << coluna1 << s2 << s3 << s1 << linha2 << s3 << coluna2 << s2;
                        std::string resposta = ss.str();
                        return resposta;
                    }
                    coluna2++;
                }
                // abaixo
                // for (int linha2 = linha1, int coluna2 = coluna1; linha2 < 8 && coluna2 < 8; linha2++, coluna2++) {
                //     if (tabuleiro[linha2][coluna2] == 1 && linha2 != linha2 && coluna2 != coluna2 ) {
                //         std::string s1("(");
                //         std::string s2(")");
                //         std::string s3(",");
                //         std::stringstream ss;
                //         ss << s1 << linha1 << s3 << coluna1 << s2 << s3 << s1 << linha2 << s3 << coluna2 << s2;
                //         std::string resposta = ss.str();
                //         return resposta;
                //     }
                // }
            }
        }
    }
    return "sucesso";
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
            if (j == 7) {
                std::cout << line << std::endl;
            }
    }}

    std::string request = checa_ataque(tabuleiro);

    if (request == "sucesso") {
        return 1;
    } else {
        std::cout << request << std::endl;
        return 0;
    }

    return -1;
}
// int main() {
//     checa_rainha("teste_8_rainhas.txt");
// }
// int main() {
//     checa_rainha("errocoluna.txt");
// }
