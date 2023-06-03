// "Copyright 2023 Gabriel Amorim Soares e Silva"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "./catch.hpp"
#include "./rainhas.hpp"

TEST_CASE("Teste principal", "[rainhas]") {
    REQUIRE(checa_rainha("teste_8_rainhas.txt") == 1);
}

TEST_CASE("Teste erro leitura", "[rainhas]") {
    REQUIRE(checa_rainha("any.txt") == -1);
}

TEST_CASE("Teste verifica 8 caracteres na linha", "[rainhas]") {
    REQUIRE(checa_rainha("erro8caracteres.txt") == -1);
}

TEST_CASE("Teste verifica 8 linhas", "[rainhas]") {
    REQUIRE(checa_rainha("erro8linhas.txt") == -1);
}

TEST_CASE("Teste verifica se ocorre ataque na linha (Falha)", "[rainhas]") {
    REQUIRE(checa_rainha("errolinha.txt") == 0);
}

TEST_CASE("Teste verifica se ocorre ataque na coluna (Falha)", "[rainhas]") {
    REQUIRE(checa_rainha("errocoluna.txt") == 0);
}

TEST_CASE("Teste verifica se ocorre ataque na diagonal principal (Falha)", "[rainhas]") {
    REQUIRE(checa_rainha("erroDiagonalPrincipal.txt") == 0);
}

TEST_CASE("Teste verifica se ocorre ataque na diagonal secundária (Falha)", "[rainhas]") {
    REQUIRE(checa_rainha("erroDiagonalPrincipal.txt") == 0);
}
