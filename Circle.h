#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"

class Circle : public Shape {
private:
    Point2D center;
    double radius;

public:
    // Constructores
    Circle();
    Circle(std::string color, Point2D center, double radius);

    // Métodos consultores
    Point2D get_center() const;
    double get_radius() const;

    // Métodos modificadores
    void set_center(Point2D p);
    void set_radius(double r);

    // Métodos heredados de Shape
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() override;

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const Circle &c);
};

#endif
