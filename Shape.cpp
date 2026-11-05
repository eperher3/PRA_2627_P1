#include "Shape.h"
#include <stdexcept>
#include <string>

// Constructor por defecto
Shape::Shape() : color("red") {

}

// Constructor con color
Shape::Shape(std::string color) {
    set_color(color);
}

// Devuelve el color
std::string Shape::get_color() const {
    return color;
}

// Modifica el color
void Shape::set_color(std::string c) {
    if (c != "red" && c != "green" && c != "blue") {
        throw std::invalid_argument("Color no valido");
    }

    color = c;
}
