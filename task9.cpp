#include<iostream>

const int size = 6;
int arr[size];

enum SortingStrategies {
    SELECTION_SORT = 1,
    BUBBLE_SORT = 2,
};

typedef struct {
    void (*sort) ();
    int ptr[2];
    SortingStrategies strategy;
}SortingOption;

void SelectionSort();
void BubbleSort();

int main() {
    SortingOption sort;

    std::cout << "Enter your array: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int j = 0;
    std::cout << "Enter your option: " << std::endl;
    std::cout << "1. Selection Sort: " << std::endl;
    std::cout << "2. Bubblesort: ";
    std::cin >> j;

    if (j == SELECTION_SORT) {
        sort.sort = &SelectionSort;
        sort.sort();
    } else if (j == BUBBLE_SORT) {
        sort.sort = &BubbleSort;
        sort.sort();
    }
}

void BubbleSort() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 1; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j],arr[j + 1]);
            }
        }
    }
    
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
    }
}

void SelectionSort() {
    for (int i = 0; i < size - 1; ++i) {
        int minindex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        std::swap(arr[i],arr[minindex]);
    }
    
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
    }
}