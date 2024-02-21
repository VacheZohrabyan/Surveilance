#include<iostream>

int main() {
    int number;
    std::cout << "Enter number: ";
    std::cin >> number;

    if (number < 0) {
        std::cout << "Number is less than zero: " << std::endl;
        return 0;
    } else if (number > 0) {
        std::cout << "Number is greater than zero: " << std::endl;
    } else {
        std::cout << "Number is equal to zero: " << std::endl;
    }

    switch(number ) {
        case 90 ... 100: {
            std::cout << "For level A" << std::endl;
        } break;
        case 80 ... 89: {
            std::cout << "For level B" << std::endl;
        } break;
        case 70 ... 79: {
            std::cout << "For level C" << std::endl;
        } break;
        case 60 ... 69: {
            std::cout << "For level D" << std::endl;
        } break;
        case 50 ... 59: {
            std::cout << "For level E" << std::endl;
        } break;
        case 40 ... 49: {
            std::cout << "For level F" << std::endl;
        } break;
        case 30 ... 39: {
            std::cout << "For level G" << std::endl;
        } break;
        case 20 ... 29: {
            std::cout << "For level H" << std::endl;
        } break;
        case 10 ... 19: {
            std::cout << "For level J" << std::endl;
        } break;
        case 0 ... 9: {
            std::cout << "For level K" << std::endl;
        } break;
        default: {
            std::cout << "NO VALID NUMBER: " << std::endl;
        }
    }

    for(int i = 1; i <= 10; ++i) {
        std::cout << "number = " << i << std::endl;
    }
}