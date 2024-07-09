#include <iostream>
#include"Array ADT_Implementation.cpp"
using namespace std;
template<typename T>
Array<T> findElements(Array<T> nums, int k)
{
    Array<T> result(2);
    for (int i = 0, j = nums.getSize() - 1; i < nums.getSize();)
    {
        if (nums[i] + nums[j] == k)
        {
            result.insert(0, nums[i]);
            result.insert(1, nums[j]);
            return result;
        }
        else if (nums[i] + nums[j] > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return result;
}
template<typename T>
int maximumSum(Array<T> nums)
{
    int i = nums.getSize() - 2;
    int j = nums.getSize() - 1;
    int sum = nums[j];
    int maxSum = sum;
    while (j > 0)
    {
        sum += nums[i];
        if (sum > maxSum)
            maxSum = sum;
        i--;
        if (i <= 0)
        {
            j--;
            sum = nums[j];
            i = j - 1;
        }
    }
    return maxSum;
}
int main()
{
    Array<int> a(10);
    /*a.insert(0, 5);
    a.insert(1, 9);
    a.insert(2, -9);
    a.insert(3, 28);
    a.insert(4, 3);
    a.insert(5, 4);*/
    a.insert(0, -2);
    a.insert(1, 1);
    a.insert(2, -3);
    a.insert(3, 4);
    a.insert(4, -1);
    a.insert(5, 2);
    a.insert(6, 1);
    a.insert(7, -5);
    a.insert(8, 4);
    cout << maximumSum(a);
    //a.sort();
    //a.remove(3);
    //findElements(a, 8).display();
    return 0;
}

