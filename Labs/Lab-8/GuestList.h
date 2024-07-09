#ifndef GUEST_LIST_H
#define GUEST_LIST_H
#include"String.h"
class Guest
{
	String name;
	String contactNumber;
public:
	Guest(String n, String c);
	void print();
};
class GuestList
{
	static const int maxSize = 100;
	Guest* guests[maxSize];
	int priorities[maxSize];
	int rear;
public:
	GuestList();
	~GuestList();
	void enqueue(Guest*, int);
	Guest* dequeue();
	Guest* top();
	bool isEmpty() const;
	bool isFull() const;
};
#endif
