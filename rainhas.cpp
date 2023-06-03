// "Copyright 2023 Gabriel Amorim Soares e Silva"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>

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
            // O windows não lê a quebra de linha, mas o linux sim.
            // Portanto faço essa dupla verificação.
            if (str.length() == 8 && countLines < 8) {
                countLines++;
                fullLine.append(str);
            } else if (str.length() == 9) {
                countLines++;
                str.erase(8, 1);
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

void writeFile(std::string resposta, std::string tipoAtaque, std::string nomeArquivo) {
    std::string erroString = "erro";
    const char * teste = strstr(nomeArquivo.c_str(), erroString.c_str());

    if (teste) {
        std::string nomeArquivoEscrito = "ataquesArquivoTeste" + tipoAtaque + ".txt";
        std::ofstream outfile(nomeArquivoEscrito);
        outfile << resposta << std::endl;
        outfile.close();
    } else {
        std::ofstream outfile("ataques.txt");
        outfile << resposta << std::endl;
        outfile.close();
    }
}

std::string checa_ataque(std::vector<std::vector<int>> tabuleiro, std::string nomeArquivo) {
    for (int linha1 = 0; linha1 < 8; linha1++) {
        for (int coluna1 = 0; coluna1 < 8; coluna1++) {
            if (tabuleiro[linha1][coluna1] == 1) {
                // Verifica ataque na linha
                for (int coluna2 = 0; coluna2 < 8; coluna2++) {
                    if (tabuleiro[linha1][coluna2] == 1 && coluna1 != coluna2) {
                        std::string tipoAtaque = "Linha";
                        std::string s1(" ");
                        std::string s3(",");
                        std::stringstream ss;
                        ss << linha1 << s3 << coluna1 << s1 << linha1 << s3 << coluna2;
                        std::string resposta = ss.str();

                        writeFile(resposta, tipoAtaque, nomeArquivo);

                        return resposta;
                    }
                }
                // Verifica ataque na coluna
                for (int linha2 = 0; linha2 < 8; linha2++) {
                    if (tabuleiro[linha2][coluna1] == 1 && linha1 != linha2) {
                        std::string tipoAtaque = "Coluna";
                        std::string s1(" ");
                        std::string s3(",");
                        std::stringstream ss;
                        ss << s1 << linha1 << s3 << coluna1 << s1 << linha2 << s3 << coluna1;
                        std::string resposta = ss.str();

                        writeFile(resposta, tipoAtaque, nomeArquivo);

                        return resposta;
                    }
                }
                // Verifica ataque na diagonal principal
                // abaixo
                int coluna2 = coluna1;
                for (int linha2 = linha1; linha2 < 8; linha2++) {
                    if (tabuleiro[linha2][coluna2] == 1 && linha1 != linha2 && coluna1 != coluna2 && coluna2 < 8) {
                        std::string tipoAtaque = "DiagonalPrincipal";
                        std::string s1(" ");
                        std::string s3(",");
                        std::stringstream ss;
                        ss << s1 << linha1 << s3 << coluna1 << s1 << linha2 << s3 << coluna2;
                        std::string resposta = ss.str();

                        writeFile(resposta, tipoAtaque, nomeArquivo);

                        return resposta;
                    }
                    coluna2++;
                }

                // acima
                coluna2 = coluna1;
                for (int linha2 = linha1; linha2 >= 0; linha2--) {
                    if (tabuleiro[linha2][coluna2] == 1 && linha1 != linha2 && coluna1 != coluna2 && coluna2 < 8) {
                        std::string tipoAtaque = "DiagonalPrincipal";
                        std::string s1(" ");
                        std::string s3(",");
                        std::stringstream ss;
                        ss << s1 << linha1 << s3 << coluna1 << s1 << linha2 << s3 << coluna2;
                        std::string resposta = ss.str();

                        writeFile(resposta, tipoAtaque, nomeArquivo);

                        return resposta;
                    }
                    coluna2--;
                }
                // Não tenho certeza se a verificação acima é necessária

                // Verfica diagonal secundária
                // abaixo
                coluna2 = coluna1;
                for (int linha2 = linha1; linha2 < 8; linha2++) {
                    if (tabuleiro[linha2][coluna2] == 1 && linha1 != linha2 && coluna1 != coluna2 && coluna2 >= 0) {
                        std::string tipoAtaque = "DiagonalSecundaria";
                        std::string s1(" ");
                        std::string s3(",");
                        std::stringstream ss;
                        ss << s1 << linha1 << s3 << coluna1 << s1 << linha2 << s3 << coluna2;
                        std::string resposta = ss.str();

                        writeFile(resposta, tipoAtaque, nomeArquivo);

                        return resposta;
                    }
                    coluna2--;
                }

                // acima
                coluna2 = coluna1;
                for (int linha2 = linha1; linha2 >= 8; linha2--) {
                    if (tabuleiro[linha2][coluna2] == 1 && linha1 != linha2 && coluna1 != coluna2 && coluna2 >= 0) {
                        std::string tipoAtaque = "DiagonalSecundaria";
                        std::string s1(" ");
                        std::string s3(",");
                        std::stringstream ss;
                        ss << s1 << linha1 << s3 << coluna1 << s1 << linha2 << s3 << coluna2;
                        std::string resposta = ss.str();

                        writeFile(resposta, tipoAtaque, nomeArquivo);

                        return resposta;
                    }
                    coluna2++;
                }
                // Não tenho certeza se a verificação acima é necessária
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

    std::string request = checa_ataque(tabuleiro, nomeDoArquivo);

    if (request == "sucesso") {
        return 1;
    } else {
        return 0;
    }

    return -1;
}
