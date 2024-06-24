#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Deque
{
	template <typename T>
	class Node
	{
	public:
		T value;
		Node* next;
		Node* previous;

		Node(T value = T(), Node* next = nullptr, Node* previous = nullptr)
		{
			this->value = value;
			this->next = next;
			this->previous = previous;
		}
	};

	int size;
	Node<T>* head;
	Node<T>* tail;

public:
	Deque(): size(0), head(nullptr), tail(nullptr)
	{
	}

	~Deque()
	{
	}

	Deque(Deque& other) : size(0), head(nullptr), tail(nullptr)
	{
		Node<T>* current = other.head;
		while (current != nullptr)
		{
			this->push_back(current->value);
			current = current->next;
		}
	}

	T& operator=(Deque& other)
	{
		if (this == other)
			return *this;

		clear();

		Node<T>* current = other.head;
		while (current != nullptr)
		{
			this->push_back(current->value);
			current = current->next;
		}
		return *this;
	}

	Deque(Deque&& other) : size(other.size), head(other.head), tail(other.tail)
	{
		other.size = 0;
		other.head = nullptr;
		other.tail = nullptr;
	}

	T& operator=(Deque&& other)
	{
		if (this != other)
		{
			clear();
			size = other.size;
			head = other.head;
			tail = other.tail;
			other.size = 0;
			other.head = nullptr;
			other.tail = nullptr;
		}

		return *this;
	}

	Deque operator+(Deque& other)
	{
		Deque result;

		Node<T>* current = head;
		while (current != nullptr)
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

	Deque operator*(const Deque& other) const
	{
		Deque result;

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

	int GetSize() const { return size; }

	T& operator[](const int index)
	{
		try
		{
			if (index < 0)
				throw string("Index out of range");
			if (index > size)
				throw string("Index out of range");

			Node<T>* current = head;
			for (int i = 0; i < index; ++i)
			{
				current = current->next;
			}
			return current->value;
		}
		catch(const string& error)
		{
			cout << "Error: " << error << endl;
		}
	}

	void push_back(T value)
	{
		Node<T>* newNode = new Node<T>(value, nullptr, tail);
		if (tail != nullptr)
		{
			tail->next = newNode;
		}
		else
		{
			head = newNode;
		}
		tail = newNode;
		size++;
	}

	void pop_front()
	{
		try
		{
			if (head != nullptr)
			{
				Node<T>* temp = head;
				head = head->next;
				if (head != nullptr)
				{
					head->previous = nullptr;
				}
				else
				{
					tail = nullptr;
				}
				delete temp;
				size--;
			}
			else
			{
				throw string("Head == nullptr");
			}
		}
		catch (const string& error)
		{
			cout << "Error: " << error << endl;
		}
	}

	void push_front(T value)
	{
		Node<T>* newNode = new Node<T>(value, head);
		if (head != nullptr)
		{
			head->previous = newNode;
		}
		else
		{
			tail = newNode;
		}
		head = newNode;
		size++;
	}

	void insert(T value, int index)
	{
		if (index == 0)
		{
			push_front(value);
		}
		else if (index == size)
		{
			push_back(value);
		}
		else
		{
			Node<T>* current = head;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			Node<T>* newNode = new Node<T>(value, current, current->previous);
			current->previous->next = newNode;
			current->previous = newNode;
			size++;
		}
	}

	void removeAt(int index)
	{
		if (index == 0)
		{
			pop_front();
		}
		else if (index == size - 1)
		{
			pop_back();
		}
		else
		{
			Node<T>* current = head;
			for (int i = 0; i < index; ++i)
			{
				current = current->next;
			}
			current->previous->next = current->next;
			current->next->previous = current->previous;
			delete current;
			size--;
		}
	}

	void pop_back()
	{
		try
		{
			if (tail != nullptr)
			{
				Node<T>* temp = tail;
				tail = tail->previous;
				if (tail != nullptr)
				{
					tail->next = nullptr;
				}
				else
				{
					head = nullptr;
				}
				delete temp;
				size--;
			}
			else
				throw string("Tail == nullptr");
		}
		catch (const string& error)
		{
			cout << "Error: " << error << endl;
		}
	}

	void clear()
	{
		try
		{
			if (size == 0)
				throw string("Deque is clear");

			while (size)
			{
				pop_front();
			}
		}
		catch (const string& error)
		{
			cout << "Error: " << error << endl;
		}
	}
};

void TestDeque()
{
	setlocale(LC_ALL, "");

	Deque<int> deq;
	deq.push_front(11);
	deq.push_back(5);
	deq.push_back(10);
	deq.push_back(15);
	deq.insert(99, 2);
	cout << "Вывод всей очереди: " << endl;
	for (int i = 0; i < deq.GetSize(); i++)
		cout << "deq[" << i << "] = " << deq[i] << endl;

	cout << "deq[2] = " << deq[2] << endl;
	cout << "deq.GetSize() = " << deq.GetSize() << endl;

	cout << "Вывод всей очереди: " << endl;
	for (int i = 0; i < deq.GetSize(); i++)
		cout << "deq[" << i << "] = " << deq[i] << endl;

	deq.pop_front();
	cout << "deq.pop_front()" << endl;
	deq.removeAt(3);
	cout << "deq.removeAt(3)" << endl;

	for (int i = 0; i < deq.GetSize(); i++)
		cout << "deq[" << i << "] = " << deq[i] << endl;

	deq.pop_back();
	cout << "deq.pop_back()" << endl;
	for (int i = 0; i < deq.GetSize(); i++)
		cout << "deq[" << i << "] = " << deq[i] << endl;

	Deque<int> deq2;
	cout << "deq2.clear()" << endl;
	deq2.clear();
	cout << "deq2.pop_back()" << endl;
	deq2.pop_back();
	cout << "deq2.pop_front()" << endl;
	deq2.pop_front();
	

	deq.clear();
	cout << "Элементов в списке " << deq.GetSize() << endl;
}

void TestAdditionAndMultiplication()
{
	Deque<int> a;
	a.push_back(1);
	a.push_back(12);
	a.push_back(123);
	for (int i = 0; i < a.GetSize(); i++)
		cout << "a[" << i << "] = " << a[i] << endl;

	Deque<int> b(a);
	for (int i = 0; i < b.GetSize(); i++)
		cout << "b[" << i << "] = " << b[i] << endl;

	Deque<int> c = a + b;
	cout << "a + b:" << endl;
	for (int i = 0; i < c.GetSize(); i++)
		cout << "c[" << i << "] = " << c[i] << endl;

	Deque<int> d = a * b;
	cout << "a * b:" << endl;
	for (int i = 0; i < d.GetSize(); i++)
		cout << "d[" << i << "] = " << d[i] << endl;
}

void main()
{
	TestDeque();
	cout << "\nSecond test: " << endl;
	TestAdditionAndMultiplication();


	system("pause");
}
