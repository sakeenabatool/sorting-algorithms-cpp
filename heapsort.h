#pragma once
#include <vector>
#include <iostream>
using namespace std;

void MaxHeapify(vector<int>& A, int low, int i, int HeapSize)
{
	int largest;
	int l = 2 * (i)+1; //LEFT(i)
	int r = 2 * (i)+1 + 1; // RIGHT(i)
	if (l< HeapSize && A[low + l]>A[low + i])
	{
		largest = low + l;
	}
	else largest = low + i;
	if (r< HeapSize && A[low + r]>A[largest])
	{
		largest = low + r;
	}
	if (largest != (low + i))
	{
		int temp = A[i + low];
		A[i + low] = A[largest];
		A[largest] = temp;
		MaxHeapify(A, low, largest - low, HeapSize);
	}
}

void BuildMaxHeap(vector<int>& A, int low, int high, int HeapSize)
{
	for (int i = (high - low + 1) / 2 - 1; i >= 0; i--)
	{
		MaxHeapify(A, low, i, HeapSize);
	}
}

void heapSort(vector<int>& A, int low, int high)
{
	int HeapSize = high - low + 1;
	BuildMaxHeap(A, low, high, HeapSize);
	for (int i = high; i > low; i--)
	{
		int temp = A[i];
		A[i] = A[low];
		A[low] = temp;
		HeapSize--;
		MaxHeapify(A, low, 0, HeapSize);
	}
}