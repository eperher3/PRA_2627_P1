#include "Square.h"
#include <stdexcept>

// Comprueba si los cuatro lados tienen la misma longitud
bool Square::check(Point2D* vertices) {

    if (vertices == nullptr) {
        return false;
    }

    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return (d01 == d12 && d12 == d23 && d23 == d30);
}

// Constructor por defecto
Square::Square() : Rectangle() {

    Point2D vertices[N_VERTICES] = {
        Point2D(-1, 1),
        Point2D(1, 1),
        Point2D(1, -1),
        Point2D(-1, -1)
    };

    set_vertices(vertices);
}

// Constructor con parámetros
Square::Square(std::string color, Point2D* vertices)
    : Rectangle(color, vertices) {

    if (!check(vertices)) {
        throw std::invalid_argument("Vertices no validos para un cuadrado");
    }
}

// Modifica los vértices
void Square::set_vertices(Point2D* vertices) {

    if (!check(vertices)) {
        throw std::invalid_argument("Vertices no validos para un cuadrado");
    }

    Rectangle::set_vertices(vertices);
}

// Imprime el cuadrado
void Square::print() {
    std::cout << *this << std::endl;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Square &square) {

    out << "[Square: color = " << square.get_color()
        << "; vertices = ";

    for (int i = 0; i < Square::N_VERTICES; i++) {

        out << square[i];

        if (i < Square::N_VERTICES - 1) {
            out << ", ";
        }
    }

    out << "]";

    return out;
}
