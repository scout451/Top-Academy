// ReSharper disable All
#include <functional>
#include <iostream>
#include <string>
using namespace std;

template<typename TValue>
class Stack
{
	struct StackNode
	{
		TValue Value;
		StackNode* Next;
	};
	StackNode* head;

public:
	Stack()
	{
		head = nullptr;
	}

	~Stack()
	{
		Clear();
	}

	void Clear()
	{
		while (head != nullptr)
		{
			StackNode* forDelete = head;
			head = head->Next;
			delete forDelete;
		}
	}

	void Push(TValue value)
	{
		if(head == nullptr)
		{
			head  = new StackNode();
			head->Value = value;
			head->Next = nullptr;
		}
		else
		{
			StackNode* newNode = new StackNode();
			newNode->Value = value;
			newNode->Next = head;
			head = newNode;
		}
	}

	TValue Pop()
	{


		TValue result = head->Value;
		StackNode* forDelete = head;
		head = head->Next;

		delete forDelete;
		return result;
	}
};

template <typename TValue>
class Queue
{
	struct QueueNode
	{
		TValue Value;
		QueueNode* Next;
	};

	QueueNode* head;
	QueueNode* tail;

public:
	Queue()
	{
		head = nullptr;
		tail = nullptr;
	}

	~Queue()
	{
		Clear();
	}

	void Clear()
	{
		while (head != nullptr)
		{
			QueueNode* forDelete = head;
			head = head->Next;
			delete forDelete;
		}
		tail = nullptr;
	}

	void Push(TValue value)
	{
		if (head == nullptr)
		{
			head = tail = new QueueNode();
			tail->Value = value;
			tail->Next = nullptr;
		}
		else
		{
			QueueNode* newNode = new QueueNode();
			newNode->Value = value;
			newNode->Next = nullptr;
			tail->Next = newNode;
			tail = newNode;
		}
	}

	TValue Pop()
	{
		if (head == nullptr)
			return 0;
		TValue result = head->Value;
		QueueNode* forDelete = head;
		head = head->Next;

		if (head == nullptr)
			tail = nullptr;
		delete forDelete;
		return result;
	}

	void ForEach(const function<void(TValue)> action) const
	{
		QueueNode* current = head;
		while (current != nullptr)
		{
			action(current->Value);
			current = current->Next;
		}
	}
};

class Point
{
	int x, y;

public:
	Point() : Point(0, 0)
	{
	}

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Point(const int value) : Point(value,value)
	{
	}

	int GetX() const { return x; }
	void SetX(int x) { this->x = x; }

	int GetY() const { return y; }
	void SetY(int y) { this->y = y; }


};
	ostream& operator<<(ostream& out, const Point& point)
	{
		out << "(" << point.GetX() << ", " << point.GetY() << ")";
		return out;
	}

	string to_string(const Point& point)
	{
		return "(" + to_string(point.GetX()) + "," + to_string(point.GetY()) + ")";
	}

template<typename  TValue>
class ArrayStack
{
	TValue* values;
	int size;
	int index = 0;

public:
	ArrayStack(int s) : size(s), values(new TValue[s]) {};

		~ArrayStack()
		{
			delete[] values;
		}
	bool IsFull()
	{
		return index == size;
	}

	bool IsEmpty()
	{
		return index == 0;
	}

	void Push(TValue value)
	{
		if (IsFull())
		{
			return;
		}
		else
		{
			values[index] = value;
			index++;
		}
	}

	TValue Pop()
	{
		if (IsEmpty())
			return 0;

		return values[--index];
	}
};

void WorkWithArrayStack()
{
	ArrayStack<int> stack(3);

	cout << "After create stack" << endl;
	cout << "Stack is empty / is full: " << stack.IsEmpty() << " / " << stack.IsFull() << endl;

	stack.Push(1);
	cout << "After push 1" << endl;
	cout << "Stack is empty / is full: " << stack.IsEmpty() << " / " << stack.IsFull() << endl;
	stack.Push(2);
	stack.Push(3);

	cout << "After push 2 and 3" << endl;
	cout << "Stack is empty / is full: " << stack.IsEmpty() << " / " << stack.IsFull() << endl;

	cout << stack.Pop() << endl; // 3
	cout << "Stack is empty / is full: " << stack.IsEmpty() << " / " << stack.IsFull() << endl;
	cout << stack.Pop() << endl; // 2
	cout << stack.Pop() << endl; // 1

	cout << "Stack is empty / is full: " << stack.IsEmpty() << " / " << stack.IsFull() << endl;

	cout << endl;
}



void main()
{
	//Stack<char> stack;
	//stack.Push('d');
	//stack.Push('s');
	//stack.Push('a');
	//cout << stack.Pop() << endl; // 3
	//cout << stack.Pop() << endl; // 2
	//cout << stack.Pop() << endl; // 1

	//stack.Clear();
	//cout << endl;

	//Stack<Point> stack2;
	//stack2.Push(Point('a', 'b'));
	//stack2.Push(Point('s', 'd'));
	//stack2.Push(Point('x', 'z'));
	//
	//cout << stack2.Pop() << endl;
	//cout << stack2.Pop() << endl;
	//cout << stack2.Pop() << endl;

	//stack2.Clear();
	//cout << endl;

	//Queue<double> queue;
	//queue.Push(1.3);
	//queue.Push(2.2);
	//queue.Push(3.1);
	//queue.ForEach([](double value) {cout << value << " "; });
	//cout << endl;
	//cout << queue.Pop() << endl; // 1
	//cout << queue.Pop() << endl; // 2
	//cout << queue.Pop() << endl; // 3

	//queue.Clear();
	WorkWithArrayStack();

	system("pause");
}