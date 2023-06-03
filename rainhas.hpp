/**
 * @brief Função para ler arquivo de entrada no formato especificado.
 * 
 * Regras do formato: 8 linhas formadas por 8 caracteres entre 0 e 1.
*/
std::string readFile(std::string filename);

void writeFile(std::string resposta, std::string tipoAtaque, std::string nomeArquivo);

std::string checa_ataque(std::vector<std::vector<int>>);

int checa_rainha(std:: string nomeDoArquivo);