/**
 * @file
 * @brief Funções para leitura e escrita de arquivos, e verificação de ataques.
 */

#include <string>
#include <vector>

/**
 * @brief Lê o conteúdo de um arquivo.
 * - Assertiva de entrada: as assertivas de entrada consiste do parâmetro a seguir:
 * @param filename O nome do arquivo a ser lido.
 * Assertiva de saída:
 *      A função lê o conteúdo de um arquivo, se este for válido retorna seu conteúdo como uma string.
 *      Caso contrário, retorna "Erro".
 * @return O conteúdo do arquivo como uma string ou "Erro".
 * @return Uma string com "Erro".
 */
std::string readFile(std::string filename);

/**
 * @brief Escreve uma resposta em um arquivo, juntamente com o tipo de ataque.
 * - Assertiva de entrada: as assertivas de entrada consistem dos parâmetros a seguir:
 * @param resposta A resposta a ser escrita.
 * @param tipoAtaque O tipo de ataque relacionado à resposta.
 * @param nomeArquivo O nome do arquivo onde a resposta será escrita.
 * 
 * Assertiva de saída: 
 *      A função processa o ataque de rainha specificado e e grava em um arquivo.
 *      Os arquivos gerados são os de casos teste e o principal, que depende da entrada no arquivo teste_8_rainhas.txt.
 *      Não há retorno para essa função.
 */
void writeFile(std::string resposta, std::string tipoAtaque, std::string nomeArquivo);

/**
 * @brief Verifica se há algum ataque em um tabuleiro de xadrez representado como uma matriz de inteiros.
 * - Assertiva de entrada: as assertivas de entrada consistem dos parâmetros a seguir:
 * @param tabuleiro O tabuleiro de xadrez representado como uma matriz de inteiros.
 * @param nomeArquivo Nome do arquivo lido.
 * - Assertiva de saída:
 *      Essa função faz todas as verificações de ataque para cada rainha posicionada.
 *      Verificando ataques em linha, coluna e suas diagonais.
 *      Caso ocorra um ataque, a função writeFile é chamada e são passados o tipo de ataque, posições do ataque e o nome do arquivo para ela.
 *      Além disso, a função retorna uma string com as posições de ataque.
 *      Caso não ocorra nenhum ataque, retorna uma string com "sucesso".
 * @return Uma string indicando as posições de ataque.
 * @return Uma string indicando "sucesso".
 */
std::string checa_ataque(std::vector<std::vector<int>> tabuleiro, std::string nomeArquivo);

/**
 * @brief Função principal que verifica se a entrada é uma solução.
 * - Assertiva de entrada: a assertiva de entrada consiste do parâmetro a seguir:
 * @param nomeDoArquivo O nome do arquivo que contém o tabuleiro de xadrez.
 * @return O número -1 indicando falha na leitura.
 * @return O número 0 indicando que a entrada não é uma solução.
 * @return O número 1 indicando que a entrada é uma solução.
 * - Assertiva de saída:
 *      A função chama readFile para ler o arquivo, se receber "Erro", retorna -1.
 *      Se não receber o erro continua o processamento e salva o conteúdo em uma matriz representando o tabuleiro.
 *      Após isso chama a função checa_ataque, se houver um ataque, retorna 0 e, se não houver, retorna -1
 */
int checa_rainha(std::string nomeDoArquivo);