#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

class Point2D {
public:
    double x;
    double y;

    // Constructor
    Point2D(double x = 0.0, double y = 0.0);

    // Calcula la distancia entre dos puntos
    static double distance(const Point2D &a, const Point2D &b);

    // Operadores de comparación
    bool operator==(const Point2D &other);
    bool operator!=(const Point2D &other);

    // Operador de salida
    friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
};

#endif
