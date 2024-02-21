#include<iostream>

int main() {
    char ch = 'A'; // ASCII value of 'A' is 65 in decimal.
    short sh = ch; // Implicit conversion from char to short.
    int in = sh;   // Implicit conversion from short to int.
    float fl = in; // Implicit conversion from int to float.
    double db = fl;// Explicit conversion from float to double.
    bool bo = true;

    std::cout << "char = " << ch << std::endl;
    std::cout << "short = " << sh << std::endl;
    std::cout << "int = " << in << std::endl;
    std::cout << "float = " << fl << std::endl;
    std::cout << "double = " << db << std::endl;
    std::cout << "bool = " << bo << std::endl;
}