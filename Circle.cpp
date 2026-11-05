#include "Circle.h"
#include <cmath>
#include <stdexcept>

// Constructor por defecto
Circle::Circle() : Shape(), center(0,0), radius(1) {

}

// Constructor con parámetros
Circle::Circle(std::string color, Point2D center, double radius)
    : Shape(color), center(center), radius(radius) {

    if (radius < 0) {
        throw std::invalid_argument("El radio no puede ser negativo");
    }
}

// Devuelve el centro
Point2D Circle::get_center() const {
    return center;
}

// Devuelve el radio
double Circle::get_radius() const {
    return radius;
}

// Modifica el centro
void Circle::set_center(Point2D p) {
    center = p;
}

// Modifica el radio
void Circle::set_radius(double r) {
    if (r < 0) {
        throw std::invalid_argument("El radio no puede ser negativo");
    }

    radius = r;
}

// Calcula el área
double Circle::area() const {
    return 3.141592 * pow(radius, 2);
}

// Calcula el perímetro
double Circle::perimeter() const {
    return 2 * 3.141592 * radius;
}

// Traslada el círculo
void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

// Imprime el círculo
void Circle::print() {
    std::cout << *this << std::endl;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "[Circle: color = " << c.color
        << "; center = " << c.center
        << "; radius = " << c.radius << "]";

    return out;
}
