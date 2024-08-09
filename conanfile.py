from conan import ConanFile
from conan.tools.cmake import cmake_layout

class ConanTutorialRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    # On définit ici les libs externes que l'on veut installer (nom + version)
    def requirements(self):
        self.requires("fmt/11.0.2")
        self.requires("lz4/1.10.0")