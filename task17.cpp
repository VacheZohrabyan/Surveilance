#include <iostream>
#include <cmath>
#include <stdexcept>

class Shape {
public:
    virtual double area() const {
        throw std::logic_error("Area calculation not implemented for base Shape class.");
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (radius <= 0) {
            throw std::invalid_argument("Radius must be positive.");
        }
    }

    double area() const override {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {
        if (length <= 0 || width <= 0) {
            throw std::invalid_argument("Length and width must be positive.");
        }
    }

    double area() const override {
        return length * width;
    }
};

int main() {
    try {
        Circle circle(5);
        std::cout << "Area of circle: " << circle.area() << std::endl;

        Rectangle rectangle(4, 6);
        std::cout << "Area of rectangle: " << rectangle.area() << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}
