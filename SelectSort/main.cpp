#include <iostream>
#include <algorithm>
#include <string>
#include "Student.h"

using namespace std;  

template<typename T>
void SelectSort(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//寻找[i, n)区间(左开右闭)的最小值
		int minIndex = i;
		for (int j = i; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
				swap(arr[j], arr[minIndex]);
		}
	}
}

int main()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	SelectSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;

	float arr2[] = { 10.9,87.6,5,4.3,21 };
	SelectSort(arr2, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << ", ";
	}
	cout << endl;

	string str[] = { "C", "A", "B", "E", "D"};
	SelectSort(str, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << str[i] << ", ";
	}
	cout << endl;

	Student stu[] = { "C", 100, "D", 85, "B", 94, "E", 66, "A", 85 };
	SelectSort(stu, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << stu[i] << ", ";
	}
	cout << endl;
}