#ifndef DRAWING_H
#define DRAWING_H

#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"

class Drawing {

private:
    std::vector<Shape*> shapes;

public:
    // Constructor
    Drawing();

    // Destructor
    ~Drawing();

    // Añadir figuras
    void add_front(Shape* shape);
    void add_back(Shape* shape);

    // Mostrar todas las figuras
    void print_all();

    // Calcular el área de todos los círculos
    double get_area_all_circles();

    // Mover todos los cuadrados
    void move_squares(double incX, double incY);
};

#endif
