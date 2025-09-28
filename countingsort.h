#pragma once
#include <iostream>
#include <vector>
using namespace std;
void CounterSort(vector<int>& a, int n, int r, int lower)
{
	int i, j = 0;
	vector<int> counter(r, 0);
	// Counting the number occurrence of each element.
	for (i = 0; i < n; i++)
		counter[a[i] - lower]++;

	i = 0;
	// placing the elements back into array.
	while (i < r)
	{
	flag:
		a[j] = lower + i;
		j++;
		counter[i]--;

		// place the same element until its counter is zero.
		if (counter[i] > 0)
			goto flag;

		i++;
	}
}
