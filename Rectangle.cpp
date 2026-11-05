#include "Rectangle.h"
#include <cmath>
#include <stdexcept>

// Comprueba si los vértices forman un rectángulo válido
bool Rectangle::check(Point2D* vertices) {

    if (vertices == nullptr) {
        return false;
    }

    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return (d01 == d23 && d12 == d30);
}

// Constructor por defecto
Rectangle::Rectangle() : Shape(), vs(new Point2D[N_VERTICES]) {

    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

// Constructor con parámetros
Rectangle::Rectangle(std::string color, Point2D* vertices)
    : Shape(color), vs(nullptr) {

    if (!check(vertices)) {
        throw std::invalid_argument("Vertices no validos");
    }

    vs = new Point2D[N_VERTICES];

    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Constructor de copia
Rectangle::Rectangle(const Rectangle &r)
    : Shape(r.color), vs(new Point2D[N_VERTICES]) {

    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

// Destructor
Rectangle::~Rectangle() {
    delete[] vs;
}

// Devuelve un vértice
Point2D Rectangle::get_vertex(int ind) const {

    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Indice fuera de rango");
    }

    return vs[ind];
}

// Sobrecarga del operador []
Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

// Modifica los vértices
void Rectangle::set_vertices(Point2D* vertices) {

    if (!check(vertices)) {
        throw std::invalid_argument("Vertices no validos");
    }

    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Operador de asignación
Rectangle& Rectangle::operator=(const Rectangle &r) {

    if (this != &r) {

        Shape::set_color(r.color);

        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = r.vs[i];
        }
    }

    return *this;
}

// Calcula el área
double Rectangle::area() const {

    double base = Point2D::distance(vs[0], vs[1]);
    double altura = Point2D::distance(vs[1], vs[2]);

    return base * altura;
}

// Calcula el perímetro
double Rectangle::perimeter() const {

    double base = Point2D::distance(vs[0], vs[1]);
    double altura = Point2D::distance(vs[1], vs[2]);

    return 2 * (base + altura);
}

// Traslada el rectángulo
void Rectangle::translate(double incX, double incY) {

    for (int i = 0; i < N_VERTICES; i++) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

// Imprime el rectángulo
void Rectangle::print() {
    std::cout << *this << std::endl;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Rectangle &r) {

    out << "[Rectangle: color = " << r.color << "; vertices = ";

    for (int i = 0; i < Rectangle::N_VERTICES; i++) {

        out << r.vs[i];

        if (i < Rectangle::N_VERTICES - 1) {
            out << ", ";
        }
    }

    out << "]";

    return out;
}
