cmake_minimum_required(VERSION 3.10)
project(Biblioteca CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Librería con la lógica de Libro y Biblioteca.
add_library(BibliotecaLib src/Libro.cpp src/Biblioteca.cpp)
target_include_directories(BibliotecaLib PUBLIC include)

# Ejecutable de demostración.
add_executable(BibliotecaApp src/main.cpp)
target_link_libraries(BibliotecaApp PRIVATE BibliotecaLib)

# Target opcional `doc` para generar documentación HTML con Doxygen,
# si está instalado (cmake --build . --target doc).
find_package(Doxygen QUIET)
if(DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/docs")
    doxygen_add_docs(doc
        include/Libro.h
        include/Biblioteca.h
        src/Libro.cpp
        src/Biblioteca.cpp
        src/main.cpp
        COMMENT "Generando documentación Doxygen en docs/"
    )
endif()
