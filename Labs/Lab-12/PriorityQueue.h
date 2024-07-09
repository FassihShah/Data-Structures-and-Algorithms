#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include"String.h"
class Task
{
public:
	int id;
	int priority;
	String description;
	Task() :id(0), priority(0), description("") {};
	Task(int i, int p, String d) :id(i), priority(p), description(d) {};
};
class PriorityQueue
{
	Task* heap;
	int capacity;
	int size;

	int left(int i);
	int right(int i);
	int parent(int i);
	void heapifyUp(int i);
	void heapifyDown(int i);
	void swap(Task& a, Task& b);
public:
	PriorityQueue(int cap);
	~PriorityQueue();
	void enqueue(Task t);
	Task dequeue();
	Task peek() const;
	bool isEmpty() const;
	int getSize() const;
};
#endif