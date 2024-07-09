#include"GuestList.h"
Guest::Guest(String n, String c):name(n),contactNumber(c)
{
}
void Guest::print()
{
	cout << "\nName: " << name;
	cout << "\nNumber: " << contactNumber;
}
GuestList::GuestList()
{
	for (int i = 0; i < maxSize; i++)
		guests[i] = nullptr;
	rear = -1;
}
GuestList::~GuestList()
{
	for (int i = 0; i <= rear; i++)
		guests[i] = nullptr;
	rear = -1;
}
bool GuestList::isEmpty() const
{
	return (rear == -1);
}
bool GuestList::isFull() const
{
	return (rear == maxSize - 1);
}
void GuestList::enqueue(Guest* g, int p)
{
	if (isFull())
	{
		cout << "\nList is Full!";
		return;
	}
	rear++;
	guests[rear] = g;
	if (p < 0 || p > 5)
		p = 0;
	priorities[rear] = p;
}
Guest* GuestList::dequeue()
{
	if (isEmpty())
	{
		cout << "\nList is Empty!";
		exit(0);
	}
	int max = 0, index = -1;
	for (int i = rear; i >= 0; i--)
	{
		if (max <= priorities[i])
		{
			max = priorities[i];
			index = i;
		}
	}
	Guest* elem = guests[index];
	for (int i = index; i < rear; i++)
	{
		guests[i] = guests[i + 1];
		priorities[i] = priorities[i + 1];
	}
	guests[rear] = nullptr;
	rear--;
	return elem;
}
Guest* GuestList::top()
{
	if (isEmpty())
	{
		cout << "\nList is Empty!";
		exit(0);
	}
	int max = 0, index = -1;
	for (int i = rear; i >= 0; i--)
	{
		if (max <= priorities[i])
		{
			max = priorities[i];
			index = i;
		}
	}
	return guests[index];
}