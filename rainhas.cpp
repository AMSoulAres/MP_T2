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
        // checking if the file is open
        std::string str;

        // read data from file object
        // and put it into string.
        while (getline(myfile, str)) {
            int countLines;

            if(str.length() == 8 && countLines < 8){
                countLines++;
                g1.push_back(str);
                fullLine.append(str);
            }
            else {
                return -1;
            }
        }
        // close the file object.
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

//     std::ifstream file("teste_8_rainhas.txt");
//     if (file.is_open()) {
//         std::string line;
//         while (std::getline(file, line)) {
//             // using printf() in all tests for consistency
//             printf("%s\n", line.c_str());
//         }
//     file.close();
//     }
// }
