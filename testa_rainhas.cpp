// "Copyright 2023 Gabriel Amorim Soares e Silva"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "./catch.hpp"
#include "./rainhas.hpp"

TEST_CASE("Teste leitura de arquivo", "[rainhas]") {
    REQUIRE(checa_rainha("teste_8_rainhas.txt") == 0);
}

TEST_CASE("Teste erro leitura", "[rainhas]") {
    REQUIRE(checa_rainha("any.txt") == -1);
}
