#include<iostream>

void IntegerVariable(int ,int );
void PointerVariables(int* ,int* );
 
int main(){
    int num_1 = 6;
    int num_2 = 14;

    IntegerVariable(num_1,num_2);
    std::cout << "Your integer variable num1 = " << num_1 << "and num_2 = " << num_2 << std::endl;

    PointerVariables(&num_1,&num_2);
    std::cout << "Your pointer variale num1 = " << num_1 << "and num_2 = " << num_2 << std::endl;
}

void IntegerVariable(int num_1, int num_2){
    int tmp = num_1;
    num_1 = num_2;
    num_2 = tmp;
}wref;

void PointerVariables(int* num_1, int* num_2){
    int tmp = *num_1;
    *num_1 = *num_2;
    *num_2 = tmp;
}