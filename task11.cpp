#include<iostream>
#include<string>
#include<fstream>

enum SortingStrategy {
    BUBBLESORT, 
    SELCETIONSORT
};

struct SortingOption{
    SortingStrategy strategy;
    void (*sort) ();
};

void BubbleSort(void);
void SelectionSort(void);

const int size = 6;
int arr[size];

int main() {
    SortingOption strategy[] = {
        {BUBBLESORT,BubbleSort},
        {SELCETIONSORT,SelectionSort}
    };

    std::string fname;
    std::cout << "Enter the file name: ";
    std::cin >> fname;

    std::ifstream infile(fname);
    if (infile.is_open()) {
        int i = 0;
        std::string line;
        while (std::getline (infile, line) && i < size) {
            arr[i++] = std::stoi(line);
        }
    }
    else {

        std::cout << "Unable to open file" << std::endl;
    }

    infile.close();
    std::cout << "Enter your option" << std::endl;
    std::cout << "1.Bubble sort" << std::endl;
    std::cout << "2.selection sort" << std::endl;
    int opt;
    std::cin >> opt;


    if (opt >= 1 && opt <= 2) {
        strategy[opt - 1].sort();
    }


    for(int i = 0; i < size; ++i) {
        std::cout << " " << arr[i];
    }
}

void BubbleSort(void) {
    for (int i = 0; i < size; ++i) {
        for(int j = 0; j < size - 1 - i; ++j) {
            if(arr[j] > arr[j + 1]) {
                std::swap(arr[j],arr[j + 1]);
            }
        }
    }
}

void SelectionSort(void) {
    for (int i = 0; i < size - 1; ++i) {
        int minindex = i;
        for(int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        std::swap(arr[i],arr[minindex]);
    }
}