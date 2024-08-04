#include<iostream>
#include"Array.h"
using namespace std;
template<typename T>
void Array<T>::copyArray(T* const dest, const T* const src, int cap)
{
	if (src == nullptr)
	{
		return;
	}
	for (int i = 0; i < cap; i++)
	{
		dest[i] = src[i];
	}
}
template<typename T>
Array<T>::Array()
{
	data = nullptr;
	size = 0;
	capacity = 0;
}
template<typename T>
Array<T>::Array(int s)
{
	capacity = s;
	data = new T[s];
	size = 0;
}
template<typename T>
Array<T>::~Array()
{
	if (capacity == 0)
	{
		return;
	}
	delete[]data;
	data = nullptr;
	size = 0;
	capacity = 0;
}
template<typename T>
void Array<T>::reSize(int newCapacity)
{
	int s = size;
	if (newCapacity <= 0)
	{
		this->~Array();
		return;
	}
	T* temp = new T[newCapacity];
	if (newCapacity >= capacity)
	{
		copyArray(temp, data, size);
	}
	else
	{
		copyArray(temp, data, newCapacity);
		s = newCapacity;
	}
	this->~Array();
	data = temp;
	size = s;
	capacity = newCapacity;
}
template<typename T>
int Array<T>::getSize() const
{
	return size;
}
template<typename T>
T& Array<T>::operator[](int index) const
{
	if (index >=0 && index < capacity)
	{
		return data[index];
	}
	exit(0);
}
template<typename T>
void Array<T>::insert(int index, const T& value)
{
	if (size == capacity)
		reSize(capacity * 2 + 1);
	for (int i = size - 1; i > index; i--)
	{
		data[i] = data[i + 1];
	}
	data[index] = value;
	size++;
}
template<typename T>
void Array<T>::remove(int index)
{
	if (index >= size)
		return;
	for (int i = index; i < size - 1; i++)
	{
		data[i] = data[i + 1];
	}
	size--;
}
template<typename T>
void Array<T>::pushBack(const T& value)
{
	if (size == capacity)
	{
		reSize(capacity * 2 + 1);
	}
	data[size] = value;
	size++;
}