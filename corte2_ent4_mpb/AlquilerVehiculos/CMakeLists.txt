cmake_minimum_required(VERSION 3.10)
project(AlquilerVehiculos CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Librería con la lógica de Vehiculo, Auto, Bicicleta y SistemaAlquiler.
add_library(AlquilerLib
    src/Vehiculo.cpp
    src/Auto.cpp
    src/Bicicleta.cpp
    src/SistemaAlquiler.cpp
)
target_include_directories(AlquilerLib PUBLIC include)

# Ejecutable de demostración.
add_executable(AlquilerApp src/main.cpp)
target_link_libraries(AlquilerApp PRIVATE AlquilerLib)

# Target opcional `doc` para generar documentación HTML con Doxygen,
# si está instalado (cmake --build . --target doc).
find_package(Doxygen QUIET)
if(DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/docs")
    doxygen_add_docs(doc
        include/Vehiculo.h
        include/Auto.h
        include/Bicicleta.h
        include/SistemaAlquiler.h
        src/Vehiculo.cpp
        src/Auto.cpp
        src/Bicicleta.cpp
        src/SistemaAlquiler.cpp
        src/main.cpp
        COMMENT "Generando documentación Doxygen en docs/"
    )
endif()
