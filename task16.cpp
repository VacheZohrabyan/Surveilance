#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class SortingStrategy {
public:
    virtual void sort(std::vector<int> &arr) const = 0;
    virtual ~SortingStrategy() {} 
};

class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int> &arr) const override {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

class SelectionSort : public SortingStrategy {
public:
    void sort(std::vector<int> &arr) const override {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            int min_index = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            std::swap(arr[i], arr[min_index]);
        }
    }
};

class FileHandler {
private:
    std::ifstream inputFileStream;
    std::ofstream outputFileStream;

public:
    FileHandler(const std::string &inputFile, const std::string &outputFile)
        : inputFileStream(inputFile), outputFileStream(outputFile) {
        if (!inputFileStream) {
            std::cerr << "Error: Failed to open input file: " << inputFile << std::endl;
        }
        if (!outputFileStream) {
            std::cerr << "Error: Failed to open output file: " << outputFile << std::endl;
        }
    }

    ~FileHandler() {
        inputFileStream.close();
        outputFileStream.close();
    }

    std::vector<int> readArrayFromFile() {
        std::vector<int> arr;
        int num;
        while (inputFileStream >> num) {
            arr.push_back(num);
        }
        return arr;
    }

    void saveArrayToFile(const std::vector<int> &arr) {
        for (int num : arr) {
            outputFileStream << num << " ";
        }
    }
};

class SortingApplication {
private:
    SortingStrategy *sortingStrategy;
    FileHandler fileHandler;

public:
    SortingApplication(const std::string &inputFile, const std::string &outputFile, int sortingChoice)
        : fileHandler(inputFile, outputFile), sortingStrategy(nullptr) {
        selectSortingStrategy(sortingChoice);
    }

    ~SortingApplication() {
        delete sortingStrategy;
    }

    void selectSortingStrategy(int sortingChoice) {
        if (sortingChoice == 1) {
            sortingStrategy = new BubbleSort();
        } else if (sortingChoice == 2) {
            sortingStrategy = new SelectionSort();
        } else {
            std::cerr << "Invalid choice! Defaulting to Bubble Sort.\n";
            sortingStrategy = new BubbleSort();
        }
    }

    void executeSorting() {
        std::vector<int> arr = fileHandler.readArrayFromFile();
        if (sortingStrategy) {
            sortingStrategy->sort(arr);
            fileHandler.saveArrayToFile(arr);
            std::cout << "Sorting completed and saved to output file.\n";
        } else {
            std::cerr << "No sorting strategy selected!\n";
        }
    }
};

int main() {
    std::string inputFile, outputFile;
    int sortingChoice;

    std::cout << "Enter input file name: ";
    std::cin >> inputFile;
    std::cout << "Enter output file name: ";
    std::cin >> outputFile;
    std::cout << "Choose sorting algorithm:\n1. Bubble Sort\n2. Selection Sort\n";
    std::cin >> sortingChoice;

    SortingApplication app(inputFile, outputFile, sortingChoice);
    app.executeSorting();

    return 0;
}
