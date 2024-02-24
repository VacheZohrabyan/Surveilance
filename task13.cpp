#include<iostream>

class Shape {
public:
    virtual double CalculateArea() const = 0;
};

class Circle : private Shape {
private:
    double m_radius;

public: 
    Circle(double radius) 
    :m_radius(radius) {}

    double CalculateArea() const override {
        return 3.14 * m_radius * m_radius;
    }
};

class  Rectangle: public Shape {
private:
    double m_weight;
    double m_height;

public:
    Rectangle(double weight, double height)
    :m_weight(weight)
    ,m_height(height) {}

    double CalculateArea() const override {
        return m_height * m_weight;
    }
};


int main() {
    Circle circle(5.0);
    Rectangle rectangle(6.0, 7.0);

    std::cout << circle.CalculateArea() << std::endl;
    std::cout << rectangle.CalculateArea() << std::endl;
}