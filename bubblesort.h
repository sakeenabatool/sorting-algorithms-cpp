#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    bool changed;
    size_t length = arr.size()-1;
    for (size_t i = 0; i < length; i++) {
        changed = false;
        for (size_t j = 0; j < length - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                changed = true;
            }
        }
        if (changed == false)
            return;
    }
}