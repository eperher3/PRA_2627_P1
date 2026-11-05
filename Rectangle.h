#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
public:
    static int const N_VERTICES = 4;

protected:
    Point2D* vs;

private:
    static bool check(Point2D* vertices);

public:
    // Constructores
    Rectangle();
    Rectangle(std::string color, Point2D* vertices);
    Rectangle(const Rectangle &r);

    // Destructor
    ~Rectangle();

    // Consultores
    Point2D get_vertex(int ind) const;

    // Sobrecarga del operador []
    Point2D operator[](int ind) const;

    // Modificador de vértices
    virtual void set_vertices(Point2D* vertices);

    // Operador de asignación
    Rectangle& operator=(const Rectangle &r);

    // Métodos heredados de Shape
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() override;

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
};

#endif
