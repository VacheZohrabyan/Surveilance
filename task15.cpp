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
public:
    static std::vector<int> readArrayFromFile(const std::string &filename) {
        std::ifstream file(filename);
        std::vector<int> arr;
        int num;
        while (file >> num) {
            arr.push_back(num);
        }
        return arr;
    }

    static void saveArrayToFile(const std::vector<int> &arr, const std::string &filename) {
        std::ofstream file(filename);
        for (int num : arr) {
            file << num << " ";
        }
    }
};

class SortingApplication {
private:
    SortingStrategy *sortingStrategy;
    FileHandler fileHandler;

public:
    SortingApplication() : sortingStrategy(nullptr) {}

    ~SortingApplication() {
        delete sortingStrategy;
    }

    void promptUserInput(std::string &inputFile, std::string &outputFile, int &sortingChoice) {
        std::cout << "Enter input file name: ";
        std::cin >> inputFile;
        std::cout << "Enter output file name: ";
        std::cin >> outputFile;
        std::cout << "Choose sorting algorithm:\n1. Bubble Sort\n2. Selection Sort\n";
        std::cin >> sortingChoice;
    }

    void selectSortingStrategy(int sortingChoice) {
        delete sortingStrategy;
        if (sortingChoice == 1) {
            sortingStrategy = new BubbleSort();
        } else if (sortingChoice == 2) {
            sortingStrategy = new SelectionSort();
        } else {
            std::cerr << "Invalid choice! Defaulting to Bubble Sort.\n";
            sortingStrategy = new BubbleSort();
        }
    }

    void executeSorting(const std::string &inputFile, const std::string &outputFile) {
        std::vector<int> arr = FileHandler::readArrayFromFile(inputFile);
        if (sortingStrategy) {
            sortingStrategy->sort(arr);
            FileHandler::saveArrayToFile(arr, outputFile);
            std::cout << "Sorting completed and saved to " << outputFile << std::endl;
        } else {
            std::cerr << "No sorting strategy selected!\n";
        }
    }
};

int main() {
    SortingApplication app;
    std::string inputFile, outputFile;
    int sortingChoice;

    app.promptUserInput(inputFile, outputFile, sortingChoice);
    app.selectSortingStrategy(sortingChoice);
    app.executeSorting(inputFile, outputFile);

    return 0;
}
