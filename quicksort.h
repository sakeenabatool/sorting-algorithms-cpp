#pragma once
#include <vector>
#include <iostream>
using namespace std;

int partition(vector<int>& arr, size_t start, size_t end)
{
    int x = arr[start];
    int i = start;
    for (size_t j = start + 1; j < end; j++)
    {
        if (arr[j] <= x)
        {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[start]);
    return i;
}

void quickSort(vector<int>& arr, size_t start, size_t end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot);
        quickSort(arr, pivot + 1, end);
    }
}

