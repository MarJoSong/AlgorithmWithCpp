#pragma once
#include <ctime>
#include <stdlib.h>
#include <cassert>

namespace SortTestHelper {
	int* generateRandomArray(int n, int rangeL, int rangeR)
	{
		assert(rangeL <= rangeR);
		int* arr = new int[n];
		srand((unsigned int)time(NULL));
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}

	template<typename T>
	void printArray(T* arr, int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	template<typename T>
	bool isSort(T arr[], int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}

	template<typename T>
	void testSort(string name, void(*sort)(T[], int), T arr[], int n)
	{
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();

		assert(isSort(arr, n));
		cout << name << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	}
}