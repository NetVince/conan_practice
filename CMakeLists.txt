cmake_minimum_required(VERSION 3.15)
project(conan_pratice)
set(VERSION "1.0")

#include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# On indique les paquets que CMake doit trouver (on peut préciser la version aussi, si besoin)
find_package(fmt REQUIRED)
find_package(lz4 REQUIRED)
find_package(hello REQUIRED)

message("Building with CMake version: ${CMAKE_VERSION}")

add_executable(${PROJECT_NAME} src/main.cpp)

# On ajoute les lib nécessaires au bon fonctionnement de notre projet
target_link_libraries(${PROJECT_NAME} fmt::fmt)
target_link_libraries(${PROJECT_NAME} lz4::lz4)
target_link_libraries(${PROJECT_NAME} hello::hello)


#On package le binaire généré sous forme de RPM
set(CPACK_PACKAGE_VERSION ${VERSION})
set(CPACK_GENERATOR "RPM")
set(CPACK_PACKAGE_NAME "conan_practice")
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_PACKAGE_CONTACT "Vincent AUROYER")
set(CPACK_PACKAGE_VENDOR "Dummy Company")
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}.${CMAKE_SYSTEM_PROCESSOR}")
include(CPack)