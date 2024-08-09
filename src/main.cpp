#include <iostream>
#include <string>
#include <cstring>

#include <lz4.h>
#include <lz4hc.h>
#include <fmt/core.h>



int main(int argc, char** argv)
{
    fmt::v11::print("Hello World! \n");
    fmt::v11::print("Ceci est un projet pour s'entraîner avec Conan ! :)\n");

    std::string msg = "This string is going to get compressed with external library";
    char buffer[1024];

    auto size = LZ4_compress_HC(msg.c_str(), buffer, msg.size() + 1, 1024, LZ4HC_CLEVEL_MAX);
    std::cout << "Compressed string is sized : " << size;
    
    return 0;
}