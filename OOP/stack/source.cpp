#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Stack
{
	
	template <typename T>
	class Node
	{
	public:
		T value;
		Node* next;

		Node(T value = T(), Node* next = nullptr)
		{
			this->value = value;
			this->next = next;
		}
	};

	int size;
	Node<T>* head;

public:
	Stack()
	{
		size = 0;
		head = nullptr;
	}

	~Stack()
	{
		clear();
	}

	Stack(Stack& other) : size(0), head(nullptr)
	{
		Node<T>* current = other.head;
		while (current != nullptr)
		{
			this->push_back(current->value);
			current = current->next;
		}
	}

	Stack& operator=(Stack& other) 
	{
		if (this == &other)
			return *this;

		clear();

		Node<T>* last = nullptr;
		for (Node<T>* n = other.head; n != nullptr; n = n->next)
		{
			Node<T>* item = new Node<T>(n->value);
			if (!head)
			{
				head = item;
			}
			else
			{
				last->next = item;
			}
			last = item;
			size++;
		}
		return *this;
	}

	Stack(Stack&& other) : size(other.size), head(other.head)
	{
		other.size = 0;
		other.head = nullptr;
	}

	Stack& operator=(Stack&& other) 
	{
		if (this != &other)
		{
			clear();
			size = other.size;
			head = other.head;
			other.size = 0;
			other.head = nullptr;
		}
		return *this;
	}

	Stack operator+(const Stack& other)
	{
		Stack result;

		Node<T>* current = this->head;
		while(current != nullptr)
		{
			result.push_back(current->value);
			current = current->next;
		}
		current = other.head;
		while (current != nullptr)
		{
			result.push_back(current->value);
			current = current->next;
		}
		return result;
	}

	Stack operator*(const Stack& other) const
	{
		Stack result;

		Node<T>* current = head;
		while (current != nullptr)
		{
			if (other.IsContains(current->value))
			{
				result.push_back(current->value);
			}
			current = current->next;
		}

		return result;
	}

	bool IsContains(const T& value) const
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			if (current->value == value)
			{
				return true;
			}
			current = current->next;
		}
		return false;
	}



	T& operator[](const int index)
	{
		Node<T>* current = this->head;
		int counter = 0;
		while (current != nullptr)
		{
			if(counter == index)
			{
				return current->value;
			}
			current = current->next;
			counter++;
		}
	}

	int GetSize() { return size; }

	void push_back(T value)
	{
		if(head == nullptr)
		{
			head = new Node<T>(value);
		}
		else
		{
			Node<T>* current = this->head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = new Node<T>(value);
		}
		size++; 
	}

	void pop_front()
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		size--;
	}

	void push_front(T value)
	{
		head = new Node<T>(value, head);
		size++;
	}

	void insert(T value, int index)
	{
		if(index == 0)
		{
			push_front(value);
		}
		else
		{
			Node<T>* previous = this->head;

			for (int i = 0; i < index - 1; i++)
				previous = previous->next;

			previous->next = new Node<T>(value, previous->next);
			size++;
		}
	}

	void removeAt(int index)
	{
		if(index == 0)
		{
			pop_front();
		}
		else
		{
			Node<T>* previous = this->head;

			for (int i = 0; i < index - 1; i++)
				previous = previous->next;

			Node<T>* forDelete = previous->next;
			previous->next = forDelete->next;

			delete forDelete;
			size--;
		}
	}

	void pop_back()
	{
		removeAt(size - 1);
	}

	void clear()
	{
		while (size)
		{
			pop_front();
		}
	}
};

void TestStack()
{
	setlocale(LC_ALL, "");

	Stack<int> stc;
	stc.push_front(11);
	stc.push_back(5);
	stc.push_back(10);
	stc.push_back(15);
	stc.insert(99, 2);

	cout <<"stc[2] = " << stc[2] << endl;
	cout << "stc.GetSize() = " << stc.GetSize() << endl;

	for (int i = 0; i < stc.GetSize(); i++)
		cout << "stc[" << i << "] = " << stc[i] << endl;

	stc.pop_front();
	cout << "stc.pop_front()" << endl;
	stc.removeAt(3);
	cout << "stc.removeAt(3)" << endl;

	for (int i = 0; i < stc.GetSize(); i++)
		cout << "stc[" << i << "] = " << stc[i] << endl;

	stc.pop_back();
	cout << "stc.pop_back()" << endl;
	for (int i = 0; i < stc.GetSize(); i++)
		cout << "stc[" << i << "] = " << stc[i] << endl;

	stc.clear();
	cout << "Ёлементов в списке " << stc.GetSize() << endl;
}

void main() 
{
	//TestStack();
	Stack<int> a;
	a.push_back(1);
	a.push_back(12);
	a.push_back(123);
	for (int i = 0; i < a.GetSize(); i++)
		cout << "a[" << i << "] = " << a[i] << endl;

	Stack<int> b(a);
	for (int i = 0; i < b.GetSize(); i++)
		cout << "b[" << i << "] = " << b[i] << endl;

	Stack<int> c = a + b;
	for (int i = 0; i < c.GetSize(); i++)
		cout << "c[" << i << "] = " << c[i] << endl;

	Stack<int> d;
	d.push_back(54);
	d.push_back(11);
	d.push_back(1);
	d = d * c;
	for (int i = 0; i < d.GetSize(); i++)
		cout << "d[" << i << "] = " << d[i] << endl;
	
	system("pause");
}
