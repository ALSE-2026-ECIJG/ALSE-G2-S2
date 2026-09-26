#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>

class Sphere {
private:
    double radius;

public:
    Sphere();
    Sphere(double radius);

    double getRadius() const;
    void setRadius(double radius);

    double getVolume() const;
    double getSurfaceArea() const;

    ~Sphere();
};

#endif
