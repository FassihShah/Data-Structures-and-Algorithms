#include<iostream>
#include"Stack_Implementation.cpp"
using namespace std;
int* func(int* arr, int size)
{
	int* greaters = new int[size];
	for (int i = 0; i < size; i++)
	{
		Stack<int> max(size);
		int j = 0;
		while (j < i)
		{
			if (arr[j] > arr[i])
				max.push(arr[j]);
			j++;
		}
		greaters[i] = max.top();
	}
	return greaters;
}
void printArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ",";
	}
	cout << endl;
}
int main()
{
	int array[6] = { 1, 6, 4, 10, 2, 5 };
	int* result = func(array, 6);
	printArray(result, 6);
	delete[] result;
	cout << endl;
	return 0;
}