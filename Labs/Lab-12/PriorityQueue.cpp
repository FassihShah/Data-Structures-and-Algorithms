#include"PriorityQueue.h"
PriorityQueue::PriorityQueue(int cap)
{
	capacity = cap;
	size = 0;
	heap = new Task[cap];
}
PriorityQueue::~PriorityQueue()
{
    delete[] heap;
    heap = nullptr;
    size = 0;
}
void PriorityQueue::swap(Task& a, Task& b)
{
    Task temp = a;
    a = b;
    b = temp;
}
int PriorityQueue::parent(int i)
{
    return (i - 1) / 2;
}
int PriorityQueue::left(int i)
{
    return 2 * i + 1;
}
int PriorityQueue::right(int i)
{
    return 2 * i + 2;
}
void PriorityQueue::heapifyUp(int index)
{
    if (index == 0)
        return;
    int parentIndex = parent(index);
    if (heap[index].priority > heap[parentIndex].priority)
    {
        swap(heap[index], heap[parentIndex]);
        heapifyUp(parentIndex);
    }
}
void PriorityQueue::heapifyDown(int index)
{
    int leftChild = left(index);
    int rightChild = right(index);
    int largest = index;
    if (leftChild < size && heap[leftChild].priority > heap[largest].priority)
    {
        largest = leftChild;
    }
    if (rightChild < size && heap[rightChild].priority > heap[largest].priority)
    {
        largest = rightChild;
    }
    if (largest != index)
    {
        swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}
bool PriorityQueue::isEmpty() const
{
    return size == 0;
}
int PriorityQueue::getSize() const
{
    return size;
}
Task PriorityQueue::peek() const
{
    if (size == 0)
    {
        cout << "\nTree is empty!";
        exit(0);
    }
    return heap[0];
}
void PriorityQueue::enqueue(Task t)
{
    if (size == capacity)
    {
        cout << "Queue is Full!";
        return;
    }
    heap[size] = t;
    heapifyUp(size);
    size++;
}
Task PriorityQueue::dequeue()
{
    if (size == 0)
    {
        cout << "\nTree is empty!";
        exit(0);
    }
    Task maxValue = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return maxValue;
}