#include<iostream>

void MaxElementArray(int* ,int);
void MinElementArray(int* ,int);
void AverageValueArray(int* ,int);

void ConcatString(char* ,char* );
int SizeString(char*, char*, int*);
int main(){
    const int size = 6;
    int arr[size] = {0};
    
    std::cout << "Enter your array element: ";
    for(int i = 0; i < size; ++i)
        std::cin >> arr[i];

    MaxElementArray(arr, size);
    MinElementArray(arr, size);
    AverageValueArray(arr, size);

    char string_1[30];
    char string_2[30];

    std::cout << "Enter your string_1: ";
    std::cin >> string_1;

    std::cout << "Enter your string_2: ";
    std::cin >> string_2;

    ConcatString(string_1,string_2);

    return 0;
}

void MaxElementArray(int* arr, int size){
    int max = 0;
    for(int i = 0; i < size; ++i){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    std::cout << "Your array maximum element = " << max << std::endl;
}

void MinElementArray(int* arr, int size){
    int min = 0;
    for(int i = 0; i < size; ++i){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    std::cout << "Your array minimum element = " << min << std::endl;
}

void AverageValueArray(int* arr, int size){
    int sum = 0;
    for(int i = 0; i < size; ++i){
        sum += arr[i];
    }
    sum = sum / size;
    std::cout << "Your average value of mass = " << sum << std::endl;
}


void ConcatString(char* string_1,char* string_2){
    int size_1 = 0;
    size_1 = SizeString(string_1,string_2,&size_1);

    for(int i = size_1, k = 0; string_2[k] != '\0'; ){
        string_1[i++] = string_2[k++]; 
    }

    std::cout << "Your String_1: " << string_1 << std::endl;
    std::cout << "Your String_2: " << string_2 << std::endl;

    std::cout << "Your String_1 size = " << size_1 << std::endl;
}

int SizeString(char* string_1, char* string_2, int* size_1){
    for(int i = 0; string_1[i] != '\0'; ++i)
    {
        ++(*size_1);
    }
    return *size_1;
}