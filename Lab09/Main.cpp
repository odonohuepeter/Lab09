/*
Author: Peter O'Donohue
Creation Date: 08/16/17
Modification Date: 08/16/17
Description: Lab 09, circular queue
*/

#include <iostream>

using namespace std;

#ifndef QUETYPE
#define QUETYPE
const int MAX = 15;
template <class ItemType>
class QueType
{
public:
	QueType();                    // easiest one 
	void MakeEmpty();             // just as easy 
	bool IsEmpty() const;         // simple 
	bool IsFull() const;          // also simple 
	void Enqueue(ItemType item); // push 
	ItemType Dequeue();            // pops it off AND 
								   // returns the front 
private:
	ItemType que[MAX];
	int rear;
	int front;
	int count;
};
#endif

// implementations
template <class ItemType>
QueType<ItemType>::QueType()
{
	front = 0;
	rear = 14;
	que[MAX];
}

template <class ItemType>
void QueType<ItemType>::MakeEmpty()
{
	delete[] que;
}


template <class ItemType>
bool QueType<ItemType>::IsEmpty() const
{
	if (count == 0)
		return true;
	else
		return false;
}

template <class ItemType>
bool QueType<ItemType>::IsFull() const
{
	if (count == 14)
		return true;
	else
		return false;
}

template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType item)
{
	if (!IsFull())
	{
		rear = (rear + 1) % MAX;
		que[rear] = item;
		++count;
	}
}

template <class ItemType>
ItemType QueType<ItemType>::Dequeue()
{
	if (!IsEmpty())
	{
		ItemType tempFront = que[front];
		front = (front + 1) % MAX;
		--count;
		return tempFront;
	}
}

#ifndef COUNTED_CLASS
#define COUNTED_CLASS
template <class ItemType>
class Counted : public QueType<ItemType>
{
public:
	Counted();
	int GetLength();
	void Enqueue(ItemType item);
	int Dequeue();
private:
	int length;
};
#endif

// implementations
template <class ItemType>
Counted<ItemType>::Counted()
{
	length = 0;
}

template <class ItemType>
int Counted<ItemType>::GetLength()
{
	return length;
}

template <class ItemType>
void Counted<ItemType>::Enqueue(ItemType item)
{
	++length;
}

template <class ItemType>
int Counted<ItemType>::Dequeue()
{
	return length;
}


int main()
{
	QueType<int> foo;
	Counted<int> foo2;
	for (int i = 0; i < 2; ++i)
	{
		foo.Enqueue(13);
		foo.Enqueue(40);
		foo.Enqueue(31);
		foo.Enqueue(15);
		foo.Enqueue(11);
		foo.Enqueue(10);
		foo.Enqueue(20);
		foo.Enqueue(96);
		foo.Enqueue(55);
		foo.Enqueue(34);
		cout << foo.Dequeue() << endl;
		cout << foo.Dequeue() << endl;
		cout << foo.Dequeue() << endl;
		cout << foo.Dequeue() << endl;
		cout << foo.Dequeue() << endl;
		cout << foo.Dequeue() << endl;
		cout << foo.Dequeue() << endl;
		cout << foo.Dequeue() << endl;
		cout << foo.Dequeue() << endl;
		cout << foo.Dequeue() << endl;
	}

	foo2.Enqueue(13);
	foo2.Enqueue(40);
	foo2.Enqueue(31);
	foo2.Enqueue(15);
	foo2.Enqueue(11);
	foo2.Enqueue(10);
	foo2.Enqueue(20);
	foo2.Enqueue(96);
	foo2.Enqueue(55);
	foo2.Enqueue(34);
	cout << foo2.Dequeue() << endl;
	cout << foo2.Dequeue() << endl;
	cout << foo2.Dequeue() << endl;
	cout << foo2.Dequeue() << endl;
	cout << foo2.Dequeue() << endl;
	cout << foo2.Dequeue() << endl;
	cout << foo2.Dequeue() << endl;
	cout << foo2.Dequeue() << endl;
	cout << foo2.Dequeue() << endl;
	cout << foo2.Dequeue() << endl;
	system("pause");
	return 0;
}