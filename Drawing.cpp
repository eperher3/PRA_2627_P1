#include "Drawing.h"
#include <algorithm>
#include <iostream>

// Constructor
Drawing::Drawing() {
}

// Destructor
Drawing::~Drawing() {

    for (Shape* shape : shapes) {
        delete shape;
    }

    shapes.clear();
}

// Añadir figura al frente
void Drawing::add_front(Shape* shape) {
    shapes.insert(shapes.begin(), shape);
}

// Añadir figura al fondo
void Drawing::add_back(Shape* shape) {
    shapes.push_back(shape);
}

// Mostrar todas las figuras
void Drawing::print_all() {

    for (Shape* shape : shapes) {
        shape->print();
    }
}

// Calcular el área de todos los círculos
double Drawing::get_area_all_circles() {

    double total = 0.0;

    for (Shape* shape : shapes) {

        Circle* circle = dynamic_cast<Circle*>(shape);

        if (circle != nullptr) {
            total += circle->area();
        }
    }

    return total;
}

// Mover todos los cuadrados
void Drawing::move_squares(double incX, double incY) {

    for (Shape* shape : shapes) {

        Square* square = dynamic_cast<Square*>(shape);

        if (square != nullptr) {
            square->translate(incX, incY);
        }
    }
}
