#pragma once
#include <iostream>
#include <vector>
using namespace std;


// get maximum element from the vector
int getMax(const vector<int>& a) {
    int maxVal = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > maxVal)
            maxVal = a[i];
    }
    return maxVal;
}

void countingSort(vector<int>& a, int place) {
    int n = a.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        int digit = abs((a[i] / place) % 10); 
        count[digit]++;
    }

    // Cumulative frequency
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Place elements in sorted order
    for (int i = n - 1; i >= 0; i--) {
        int digit = abs((a[i] / place) % 10);
        int pos = count[digit] - 1;
        output[pos] = a[i];
        count[digit]--;
    }

    // Copy back
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

// standard radix sort for positive
void radixSortNonNegative(vector<int>& a) {
    int maxVal = getMax(a);
    for (int place = 1; maxVal / place > 0; place *= 10)
        countingSort(a, place);
}

// final radix sort for all integers
void radixSort(vector<int>& arr) {
    vector<int> negatives, positives;

    // Split negatives and positives
    for (int num : arr) {
        if (num < 0)
            negatives.push_back(-num); // store as positive
        else
            positives.push_back(num);
    }

    // Sort positives normally
    if (!positives.empty())
        radixSortNonNegative(positives);

    // Sort negatives (stored as positive values)
    if (!negatives.empty()) {
        radixSortNonNegative(negatives);
        // Convert back to negatives and reverse order
        for (int& num : negatives)
            num = -num;
        reverse(negatives.begin(), negatives.end());
    }

    // Combine: negatives first, then positives
    arr.clear();
    arr.insert(arr.end(), negatives.begin(), negatives.end());
    arr.insert(arr.end(), positives.begin(), positives.end());
}