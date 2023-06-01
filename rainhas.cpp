// "Copyright 2023 Gabriel Amorim Soares e Silva"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int checa_rainha(std:: string nomeDoArquivo) {
    std::fstream myfile;
    // open file
    myfile.open(nomeDoArquivo);
    std::vector<std::string> g1;
    std::string fullLine;

    if (myfile.is_open()) {
        std::string str;
        int countLines = 0;

        while (getline(myfile, str)) {
            if (str.length() == 8 && countLines < 8) {
                countLines++;
                g1.push_back(str);
                fullLine.append(str);
            } else {
                return -1;
            }
        }
        myfile.close();
    }
    std::cout << "\nVector elements are: " << std::endl;
    for (unsigned int i = 0; i < g1.size(); i++) {
        std::cout << g1[i] << std::endl;
    }
    if (fullLine == "0000010001000000000100000000001000100000000000010000100010000000") {
        return 0;
    }

    return -1;
}
// int main() {
//     checa_rainha("teste_8_rainhas.txt");
// }
