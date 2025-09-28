#pragma once
#include <iostream>
#include <vector>
using namespace std;
void bucketSort(vector<int> arr, size_t n, int upper, int number_of_buckets)
{
    // Calculate the divider value dividing the maximum element and number of buckets.
    int divider = ceil(float(upper + 1) / float(number_of_buckets));
    // Create the buckets array.
    std::vector<std::vector<int>> buckets;
    buckets.resize(number_of_buckets);

    // Place every number into a corresponding bucket.
    for (size_t i = 0; i < n; i++)
    {
        int j = floor(arr[i] / divider);
        buckets[j].push_back(arr[i]);
    }

    // Sort every bucket.
    int index = 0;
    for (size_t i = 0; i < number_of_buckets; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
        // Place the sorted numbers into the original array.
        for (int number : buckets[i])
        {
            arr[index] = number;
            index++;
        }
    }
}
