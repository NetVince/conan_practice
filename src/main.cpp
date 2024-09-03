#include <iostream>
#include <string>
#include <cstring>

#include <lz4.h>
#include <lz4hc.h>
#include <fmt/core.h>
#include <fmt/color.h>
#include <hello.h>



int main(int argc, char** argv)
{
    // Utilisation de la lib fmt pour affichage de traces
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "Bonjour le monde (en couleur avec fmt!) \n");
    fmt::print("Ceci est un projet pour s'entraîner avec Conan ! On compile avec Conan build (lib fmt)\n");
    
    // Utilisation de la lib locale hello (affichage Hello world avec la version de la lib)
    hello();

    // Utilisation de la lib externe zlib
    std::string msg = "This string is going to get compressed with external library";
    char buffer[1024];

    auto size = LZ4_compress_HC(msg.c_str(), buffer, msg.size() + 1, 1024, LZ4HC_CLEVEL_MAX);
    std::cout << "Compressed string is sized : " << size;
    
    return 0;
}