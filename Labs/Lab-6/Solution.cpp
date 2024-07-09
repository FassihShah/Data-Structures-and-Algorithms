#include<iostream>
using namespace std;
int binarySearch(int array[], int left, int right, int key)
{
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (array[mid] == key)
        return mid;
    if (array[mid] < key)
        left = mid + 1;
    else
        right = mid - 1;
    binarySearch(array, left, right, key);
}

/////////////////////////////////////////

int evenDigits(int num)
{
    if (num == 0)
        return num;
    int x = num % 10;
    num = num / 10;
    int y = evenDigits(num);
    if (x % 2 == 0)
        return y * 10 + x;
    return y;
}

///////////////////////////////////////////

long long int decimalToBinary(int num)
{
    if (num == 0)
        return 0;
    int x = num % 2;
    num = num / 2;
    return decimalToBinary(num) * 10 + x;
}
int countOnesInBinary(int binary)
{
    if (binary == 0)
        return 0;
    int x = binary % 10;
    binary = binary / 10;
    if (x == 1)
        return 1 + countOnesInBinary(binary);
    if (x == 0)
        return countOnesInBinary(binary);
}
int main()
{
    cout << evenDigits(811643);
    return 0;
}