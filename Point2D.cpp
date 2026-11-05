#include <ostream>
#include <cmath>
#include "Point2D.h"

// Constructor
Point2D::Point2D(double x, double y) {
    this->x = x;
    this->y = y;
}

// Distancia euclidiana
double Point2D::distance(const Point2D &a, const Point2D &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Comprueba si dos puntos son iguales
bool Point2D::operator==(const Point2D &other) {
    return (x == other.x && y == other.y);
}

// Comprueba si dos puntos son diferentes
bool Point2D::operator!=(const Point2D &other) {
    return !(*this == other);
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
