#include <iostream>
#include <algorithm>

using namespace std;  

void SelectSort(int arr[], int n)
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
		cout << arr[i] << endl;
	}
}