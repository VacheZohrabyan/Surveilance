#include <iostream>

class Shape {
public:
    virtual double area() const = 0; 
    virtual ~Shape() {} 
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override { return length * width; }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
};

void printArea(const Shape* shapePtr) {
    std::cout << "Area: " << shapePtr->area() << std::endl;
}

int main() {
    Rectangle rectangle(4, 5);
    Circle circle(3);

    printArea(&rectangle);
    printArea(&circle);

    return 0;
}
