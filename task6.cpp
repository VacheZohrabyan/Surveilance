#include<iostream>

int Add(int ,int );
int Subtract(int, int);
int Multiply(int, int);
int Divide(int, int);
int main(){
    while(1)
    {
        int number_1 = 0;
        std::cout << "Enter number_1: ";
        std::cin >> number_1;

        char expression;
        std::cout << "1.add: Enter (+) " << std::endl;
        std::cout << "2.subtract: Enter (-) " << std::endl;
        std::cout << "3.multiply: Enter (*) " << std::endl;
        std::cout << "4.divide: Enter (/) " << std::endl;
        std::cout << "5.Exit proogram: Enter e" << std::endl;
        std::cout << "Enter your option: ";
        std::cin >> expression;
        if(expression != '+' && expression != '-' && expression != '*' && expression != '/' && expression != 'e')
        {
            std::cout <<  "Invalid Option" << std::endl;
            continue;
        }
        int number_2 = 0;
        std::cout << "Enter number_2: ";
        std::cin >> number_2;

        switch (expression)
        {
            case '+':{
                std::cout << "Your rezat = " << Add(number_1,number_2) << std::endl;
            }break;
            case '-':{
                std::cout << "Your rezat = " << Subtract(number_1,number_2) << std::endl;
            }break;
            case '*':{
                std::cout << "Your rezat = " << Multiply(number_1,number_2) << std::endl;
            }break;
            case '/':{
                std::cout << "Your rezat = " << Divide(number_1,number_2) << std::endl;
            }break;
            case 'e':{
                return 0;
            }
        }
    }
}

int Add(int number_1, int number_2){
    return number_1 + number_2;
}

int Subtract(int number_1, int number_2){
    return number_1 - number_2;
}

int Multiply(int number_1, int number_2){
    return number_1 * number_2;
}

int Divide(int number_1, int number_2){
    if(number_2 == 0){
        return -999999999; // Return a special value for error.
    }
    return number_1 / number_2;
}