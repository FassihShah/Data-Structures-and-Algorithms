#include<iostream>
#include"PriorityQueue.h"
#include"MinHeap.h"
using namespace std;
int kthSmallestElement(int* arr, int k, int size)
{
	if (k > size)
		return -1;
	MinHeap p(size);
	for (int i = 0; i < size; i++)
	{
		p.enqueue(arr[i]);
	}
	for (int i = 0; i < k - 1; i++)
	{
		p.dequeue();
	}
	return p.dequeue();
}
void taskSchedular()
{
	PriorityQueue p(100);
	int choice;
	String d;
	do
	{
		cout << "\nEnter 1 to add a Task\nEnter 2 to get Highest Priority Task\nEnter 3 to delete Highest Priority Task \nEnter 0 to exit\nEnter : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			d.~String();
			int id, pr;
			cout << "Enter task id : ";
			cin >> id;
			cout << "Enter task priority : ";
			cin >> pr;
			cout << "Enter task description : ";
			cin.ignore();
			d.input();
			p.enqueue(Task(id, pr, d));
			break;
		case 2:
			cout << p.peek().description << endl;
			break;
		case 3:
			p.dequeue();
			break;
		case 0:
			break;
		}
	} while (choice != 0);
}
int main()
{
	//taskSchedular();
	/*PriorityQueue p(10);
	p.enqueue(Task(1, 10, "Task 1 - Low Priority"));
	p.enqueue(Task(2, 50, "Task 2 - High Priority"));
	p.enqueue(Task(3, 30, "Task 3 - Medium Priority"));
	p.enqueue(Task(4, 40, "Task 4 - Medium-High Priority"));
	cout << p.getSize() << endl;
	cout << p.peek().description << endl;
	cout << p.dequeue().description << endl;
	cout << p.peek().description << endl;
	cout << p.dequeue().description << endl;
	cout << p.peek().description << endl;
	cout << p.getSize() << endl;*/
	int arr[10] = { 2,3,9,4,0,8 };
	cout << kthSmallestElement(arr, 5, 6);
	return 0;
}