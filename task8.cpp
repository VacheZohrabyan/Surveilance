#include<iostream>

enum Days {
    Su = 1,
    Mo, 
    Tu,
    We,
    Th,
    Fr,
    Sa,
};

typedef struct{
    Days days;
    int WithDay;
    int Year;
    char* Month;
} Date;


int main(){
    Date date;
    date.Year = 2024;
    date.Month = "February";
    date.WithDay = 23;
    std::cout << date.days << std::endl;
    std::cout << date.WithDay << std::endl;
    std::cout << date.Month << std::endl;
    std::cout << date.Year << std::endl;
}