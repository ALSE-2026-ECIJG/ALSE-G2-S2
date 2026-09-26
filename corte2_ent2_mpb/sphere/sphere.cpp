#include "sphere.h"
#include <iostream>

Sphere::Sphere() : radius(1.0) {
}

Sphere::Sphere(double radius) {
    if (radius > 0) {
        this->radius = radius;
    } else {
        this->radius = 1.0;
    }
}

double Sphere::getRadius() const {
    return radius;
}

void Sphere::setRadius(double radius) {
    if (radius > 0) {
        this->radius = radius;
    }
}

double Sphere::getVolume() const {
    return (4.0 / 3.0) * M_PI * std::pow(radius, 3);
}

double Sphere::getSurfaceArea() const {
    return 4.0 * M_PI * std::pow(radius, 2);
}

Sphere::~Sphere() {
    std::cout << "Sphere destructor called" << std::endl;
}
