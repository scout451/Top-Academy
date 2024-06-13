#include <iostream>
#include <string>
#include <vector>
#include "DoubleLinkedList.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include "List.h"
#include "VectorList.h"

using namespace std;
//
//template <template <typename> class TList, typename T>
//class StackQueue
//{
//protected:
//    TList<T>* list;
//
//    StackQueue()
//    {
//        list = new TList<T>();
//    }
//
//    StackQueue(const StackQueue<TList, T>& other)
//    {
//        list = new TList<T>(*other.list);
//    }
//
//    StackQueue(StackQueue<TList, T>&& other)
//    {
//        list = other.list;
//        other.list = nullptr;
//    }
//
//    virtual ~StackQueue()
//    {
//        if (list != nullptr)
//            delete list;
//    }
//
//public:
//    bool IsEmpty()
//    {
//        return list->IsEmpty();
//    }
//
//    virtual void Push(const T& value) = 0;
//
//    virtual T Pop() = 0;
//
//    virtual T Peek() = 0;
//
//    void Clear()
//    {
//        // todo
//    }
//
//    StackQueue& operator=(const StackQueue<TList, T>& other)
//    {
//        // todo
//    }
//
//    StackQueue& operator=(StackQueue<TList, T>&& other)
//    {
//        // todo
//    }
//};
//
//template <template <typename> class TList, typename T>
//class Queue : StackQueue<TList, T>
//{
//public:
//    Queue() : StackQueue<TList, T>()
//    {
//    }
//
//    Queue(const Queue& other) : StackQueue<TList, T>(other)
//    {
//    }
//
//    Queue(Queue&& other) : StackQueue<TList, T>(other)
//    {
//    }
//
//    ~Queue() override
//    {
//    }
//
//    void Push(const T& value) override
//    {
//        this->list->AddToBack(value);
//    }
//
//    T Pop() override
//    {
//        // todo
//    }
//
//    T Peek() override
//    {
//        // todo
//    }
//
//    Queue& operator=(const Queue<TList, T>& other)
//    {
//        // todo
//    }
//
//    Queue& operator=(Queue<TList, T>&& other)
//    {
//        // todo
//    }
//};
//
//template <template <typename> class TList, typename T>
//class Stack : StackQueue<TList, T>
//{
//    // todo
//};


template <template <typename> class TList, typename T>
void ListTests()
{
	TList<T> list;

	list.AddToFront(2);
	list.AddToFront(1);
	list.AddToBack(4);
	list.Add(2, 3);

	cout << endl;
	cout << "Items expecting: ";
	for (int i = 1; i <= 4; i++)
		cout << (T)i << " ";
	cout << endl;

	cout << "Items received:  ";
	for (int i = 0; i < list.GetSize(); i++)
		cout << list[i] << " ";
	cout << endl;

	list.RemoveFromFront();
	list.RemoveFromFront();
	list.RemoveFromBack();

	cout << "Items expecting: " << (T)3 << endl;

	cout << "Items received:  ";
	for (int i = 0; i < list.GetSize(); i++)
		cout << list[i] << " ";
	cout << endl;
}

void main()
{
	ListTests<VectorList, int>();
	ListTests<ArrayList, int>();
	ListTests<LinkedList, int>();
	ListTests<DoublyLinkedList, int>();
	system("pause");
}