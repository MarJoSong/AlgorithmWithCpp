#include <iostream>
#include <algorithm>

using namespace std;  

void SelectSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//Ѱ��[i, n)����(���ұ�)����Сֵ
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