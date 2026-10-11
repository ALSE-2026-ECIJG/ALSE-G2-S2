cmake_minimum_required(VERSION 3.10)
project(CarritoCompras CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Librería con la lógica de Producto, ItemCarrito, CarritoCompras y Usuario.
add_library(CarritoLib
    src/Producto.cpp
    src/ItemCarrito.cpp
    src/CarritoCompras.cpp
    src/Usuario.cpp
)
target_include_directories(CarritoLib PUBLIC include)

# Ejecutable de demostración.
add_executable(CarritoApp src/main.cpp)
target_link_libraries(CarritoApp PRIVATE CarritoLib)

# Target opcional `doc` para generar documentación HTML con Doxygen,
# si está instalado (cmake --build . --target doc).
find_package(Doxygen QUIET)
if(DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/docs")
    doxygen_add_docs(doc
        include/Producto.h
        include/ItemCarrito.h
        include/CarritoCompras.h
        include/Usuario.h
        src/Producto.cpp
        src/ItemCarrito.cpp
        src/CarritoCompras.cpp
        src/Usuario.cpp
        src/main.cpp
        COMMENT "Generando documentación Doxygen en docs/"
    )
endif()
