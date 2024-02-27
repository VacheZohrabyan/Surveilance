#include <iostream>
#include <cmath>

template<typename T>
class Shape {
public:
    virtual T area() const = 0;
    virtual ~Shape() {}
};

template<typename T>
class Circle : public Shape<T> {
private:
    T radius;

public:
    Circle(T r) : radius(r) {}

    T area() const override {
        return M_PI * radius * radius;
    }
};

template<typename T>
class Rectangle : public Shape<T> {
private:
    T length;
    T width;

public:
    Rectangle(T l, T w) : length(l), width(w) {}

    T area() const override {
        return length * width;
    }
};

int main() {
    Circle<float> circleF(5.0f);
    std::cout << "Area of circle (float): " << circleF.area() << std::endl;

    Circle<double> circleD(5.0);
    std::cout << "Area of circle (double): " << circleD.area() << std::endl;

    Rectangle<int> rectangleInt(4, 6);
    std::cout << "Area of rectangle (int): " << rectangleInt.area() << std::endl;

    Rectangle<double> rectangleDouble(4.5, 6.5);
    std::cout << "Area of rectangle (double): " << rectangleDouble.area() << std::endl;

    return 0;
}
