#include<iostream>
using namespace std;
int findSqrt(int n)
{
	int num = n / 2;
	while (num > 0)
	{
		if ((num * num) <= n)
			return num;
		num--;
	}
	return 0;
}
int* productExceptSelf(int* nums, int size)
{
	int* left = new int[size];
	int* right = new int[size];
	int leftCount = 0;
	int rightCount = 0;
	int j = 1;
	int product = 1;
	for (int i = 0; i < size;)
	{
		if (i != 0 && (i - j) >= 0)
		{
			product *= nums[i - j];
			j++;
		}
		else
		{
			left[leftCount] = product;
			leftCount++;
			i++;
			j = 1;
			product = 1;
		}
	}
	for (int i = 0; i < size;)
	{
		if (i != size - 1 && (i + j) < size)
		{
			product *= nums[i + j];
			j++;
		}
		else
		{
			right[rightCount] = product;
			rightCount++;
			i++;
			j = 1;
			product = 1;
		}
	}
	for (int i = 0; i < size; i++)
	{
		right[i] *= left[i];
	}
	/*int product = 1;
		for (int j = 0; j < size; j++)
		{
			if (i != j)
				product *= nums[j];
		}
		result[i] = product;*/
	return right;
}
double* findAverage(int* nums, int size, int k)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (i + k <= size)
		{
			count++;
		}
	}
	double* averages = new double[count];
	int cnt = 1;
	double sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += nums[i];
	}
	averages[0] = sum;
	for (int i = 0, j = k; cnt < count; i++, j++, cnt++)
	{
		sum = sum - nums[i];
		sum = sum + nums[j];
		averages[cnt] = sum / k;
	}
	return averages;
}
int main()
{
	/*int nums[4] = { 2,3,1,1};
	int* result = productExceptSelf(nums, 4);
	for (int i = 0; i < 4; i++)
	{
		cout << result[i] << ",";
	}*/
	//cout << findSqrt(28);
	int nums[6] = { 1,2,3,4 };
	double* result = findAverage(nums, 4, 3);
	for (int i = 0; i < 2; i++)
	{
		cout << result[i] << ",";
	}
}