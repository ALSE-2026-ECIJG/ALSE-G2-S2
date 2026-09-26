#include "sphere.h"
#include <iostream>

int main() {
    Sphere sphere1(3.0);

    std::cout << "Radio: " << sphere1.getRadius() << std::endl;
    std::cout << "Volumen: " << sphere1.getVolume() << std::endl;
    std::cout << "Area superficial: " << sphere1.getSurfaceArea() << std::endl;

    sphere1.setRadius(5.0);

    std::cout << "\nNuevo radio: " << sphere1.getRadius() << std::endl;
    std::cout << "Nuevo volumen: " << sphere1.getVolume() << std::endl;
    std::cout << "Nueva area superficial: " << sphere1.getSurfaceArea() << std::endl;

    return 0;
}
