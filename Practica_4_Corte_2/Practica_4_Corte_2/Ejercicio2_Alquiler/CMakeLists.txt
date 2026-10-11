add_executable(Ejercicio2_Alquiler
    src/main.cpp
    src/Vehiculo.cpp
    src/Auto.cpp
    src/Bicicleta.cpp
    src/SistemaAlquiler.cpp
)
target_include_directories(Ejercicio2_Alquiler PRIVATE include)
