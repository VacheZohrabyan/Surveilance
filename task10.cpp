#include<iostream>
#include<fstream>
#include<string>

char y_n;

int main() {
    std::string name;
    std::ofstream outfile("name.txt");

    if (!outfile.is_open()) {
        std::cout << "Unable to open file"; 
        return 1;
    }

    std::cout << "If you want to write your name press y, if not n.";
    std::cin >> y_n;
    while (y_n == 'y') {
        std::cout << "Enter your name: ";
        std::cin >> name;
        
        outfile << name << '\n';  

        std::cout << "if you want to continue writing your name press y, if not n: ";
        std::cin >> y_n;
    }
    outfile.close();

    std::ifstream infile("name.txt"); 
    if (infile.is_open()) {
        std::string line;
        while(std::getline(infile,line)) {
            std::cout<< line <<'\n';
        }
        infile.close();
    }
}