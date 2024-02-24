#include<iostream>

void BubbleSort(int*, int);
int* SelectionSort(int*, int);

int main(){
    const int size_1 = 6;
    int* arr_1 = new int[size_1];
    if(arr_1 == NULL){
        return 0;
    }

    for(int i = 0; i < size_1; ++i){
        std::cin >> arr_1[i];
    }
    BubbleSort(arr_1,size_1);
    std::cout << "Your array ";
    for(int i = 0; i < size_1; ++i)
    {
        std::cout << arr_1[i];
    }
    
    const int size_2 = 8;
    int* arr_2 = new int[size_2]; 
    srand(time(0));  
    for(int i = 0; i < size_2; ++i){
        arr_2[i] = 1 + rand() % 10;
    }
    int* arr = SelectionSort(arr_2,size_2);
    for(int i = 0; i < size_2; ++i){
        std::cout << arr[i];
    }
    delete[] arr;
}

void BubbleSort(int* arr ,int size){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size - 1; ++j){
            if(arr[i] < arr[j]){
                std::swap(arr[i],arr[j]);        
            }
        }
    }
}

int* SelectionSort(int* arr_2, int size_2) {
    int* arr = new int[size_2];
    for (int i = 0; i < size_2; ++i) {
        arr[i] = arr_2[i];
    }

    for (int i = 0; i < size_2; ++i) {
        int minindex = i;
        for (int j = i + 1; j < size_2; ++j) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        std::swap(arr[i], arr[minindex]);
    }
    return arr;
}
