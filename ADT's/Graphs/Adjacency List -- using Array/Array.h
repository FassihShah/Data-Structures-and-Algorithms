#ifndef ARRAY_H
#define ARRAY_H
template<typename T>
class Array
{
	T* data;
	int size;
	int capacity;
	void copyArray(T* const dest, const T* const src, int cap);
public:
	Array();
	Array(int);
	~Array();
	int getSize() const;
	void reSize(int newCapacity);
	T& operator[](int index) const;
	void insert(int index, const T& value);
	void remove(int index);
	void pushBack(const T& value);
};
template class Array<int>;
template class Array<bool>;
template class Array<Array<int>>;
#endif