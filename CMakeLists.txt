cmake_minimum_required(VERSION 3.15)
project(training)

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# On indique les paquets que CMake doit trouver (on peut préciser la version aussi, si besoin)
find_package(fmt REQUIRED)
find_package(lz4 REQUIRED)

message("Building with CMake version: ${CMAKE_VERSION}")

add_executable(${PROJECT_NAME} src/main.cpp)

# On ajoute les lib nécessaires au bon fonctionnement de notre projet
target_link_libraries(${PROJECT_NAME} fmt::fmt)
target_link_libraries(${PROJECT_NAME} lz4::lz4)
