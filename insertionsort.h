#pragma once
#include <vector>
#include <iostream>
using namespace std;

void insertionSort(vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
