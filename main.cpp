#include <iostream>
#include "bubblesort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"
#include "countingsort.h"
#include "radixsort.h"
#include "bucketsort.h"
#include <chrono>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
using namespace std::chrono;

//read numbers from CSV file

vector<int> readNumbersFromCSV(const string& filename, int& count) {
    ifstream file(filename);
    vector<int> numbers;
    string line;

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        count = 0;
        return numbers; // return empty vector
    }

    // Skip header line
    getline(file, line);

    // Read numbers line by line
    while (getline(file, line)) {
        if (!line.empty()) {
            numbers.push_back(stoi(line));
        }
    }

    file.close();
    count = numbers.size(); // update count
    return numbers;
}

// Function to find the minimum and maximum values in an array
pair<int, int> findLimits(const std::vector<int>& arr) {
    if (arr.empty()) {
        throw invalid_argument("Array is empty");
    }

    int lower = numeric_limits<int>::max();
    int upper = numeric_limits<int>::min();

    for (int num : arr) {
        if (num < lower) lower = num;
        if (num > upper) upper = num;
    }

    return { lower, upper };
}

int main() {
    int count = 0;
    vector<int> numbers = readNumbersFromCSV("data.csv", count);
    cout << "Numbers read from file" << endl;
    cout << "Count = " << count << endl;
	//find limits
    pair<int, int> limits = findLimits(numbers);
    int lower = limits.first;
    int upper = limits.second;
    int range = upper - lower + 1;
    auto start = high_resolution_clock::now();
    //algorithms
	//bubbleSort(numbers, count);
	//insertionSort(numbers);
	//mergeSort(numbers.data(), 0, count - 1);
	//heapSort(numbers, 0, count - 1);
	//quickSort(numbers, 0, numbers.size());
	//CounterSort(numbers, count, range, lower);
	//radixSort(numbers);
	bucketSort(numbers, count, upper, 10);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
}