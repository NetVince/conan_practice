from conan import ConanFile
from conan.tools.cmake import CMake,cmake_layout

class ConanTutorialRecipe(ConanFile):
    name = "conan_practice"
    version = "1.0"

    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    # On définit ici les libs externes que l'on veut installer (nom + version)
    def requirements(self):
        self.requires("fmt/11.0.2")
        self.requires("lz4/1.10.0")
        self.requires("hello/1.0")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()