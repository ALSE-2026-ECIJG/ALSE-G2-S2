add_executable(Ejercicio3_Carrito
    src/main.cpp
    src/Producto.cpp
    src/ItemCarrito.cpp
    src/CarritoCompras.cpp
    src/Usuario.cpp
)
target_include_directories(Ejercicio3_Carrito PRIVATE include)
