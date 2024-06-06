#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pet
{
	string name;

public:
	Pet(string n)
	{
		name = n;
	}
	string GetName() { return name; }

	virtual void Sound()
	{
		cout << "Abstract sound" << endl;
	}

	virtual void Show()
	{
		cout << "Name: " << name << endl;
	}

	virtual void Type()
	{
		cout << "Abstract type" << endl;
	}
};

class Dog: public Pet
{
public:
	Dog(string n) : Pet(n) {}

	void Sound() override	{ cout << "Sound - Gav" << endl; }

	void Show() override	{ cout << "Name: " << GetName()  << endl; }

	void Type() override	{ cout << "Type - Dog" << endl;	}
};

class Cat : public Pet
{
public:
	Cat(string n) : Pet(n) {}

	void Sound() override	{ cout << "Sound - Mur" << endl; }

	void Show() override	{ cout << "Name: " << GetName() << endl; }

	void Type() override	{ cout << "Type - Cat" << endl; }
};

class Parrot : public Pet
{
public:
	Parrot(string n) : Pet(n) {}

	void Sound() override	{ cout << "Sound - *sound parrot*" << endl; }

	void Show() override	{ cout << "Name: " << GetName() << endl; }

	void Type() override	{ cout << "Type - Parrot" << endl; }
};

class Hamster : public Pet
{
public:
	Hamster(string n) : Pet(n) {}

	void Sound() override	{ cout << "Sound - *sound hamster*" << endl; }

	void Show() override	{ cout << "Name: " << GetName() << endl; }

	void Type() override	{ cout << "Type - Hamster" << endl; }
};

//void main()
//{
//	Hamster h("hamster");
//	h.Show();
//	h.Sound();
//	h.Type();
//	cout << endl;
//
//	Dog d("dog");
//	d.Show();
//	d.Sound();
//	d.Type();
//	cout << endl;
//
//	Cat c("cat");
//	c.Show();
//	c.Sound();
//	c.Type();
//	cout << endl;
//
//	Parrot p("parrot");
//	p.Show();
//	p.Sound();
//	p.Type();
//	cout << endl;
//
//	Pet pet("pet");
//	pet.Show();
//	pet.Sound();
//	pet.Type();
//	cout << endl;
//
//	vector<Pet*> pets;
//	pets.push_back(&h);
//	pets.push_back(&d);
//	pets.push_back(&c);
//	pets.push_back(&p);
//	pets.push_back(&pet);
//
//	for(Pet* animal : pets)
//	{
//		cout << animal->GetName() << " " << endl;
//		animal->Sound();
//		cout << " ";
//		animal->Type();
//		cout << " " << endl;
//	}
//
//	system("pause");
//}



class List
{
	struct Node
	{
		int Value;
		Node* Next;
		Node* Prev;
	};
	Node* head;
	Node* tail;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	virtual void Clear()
	{
		while (head != nullptr)
		{
			Node* forDelete = head;
			head = head->Next;
			delete forDelete;
		}
	}

	virtual void Push(int value)
	{
		if (head == nullptr)
		{
			head = new Node();
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

	virtual int Pop()
	{
		int result = head->Value;
		StackNode* forDelete = head;
		head = head->Next;

		delete forDelete;
		return result;
	}

	virtual void ForEach(const function<void(int)> action) const
	{
		StackNode* current = head;
		while (current != nullptr)
		{
			action(current->Value);
			current = current->Next;
		}
	}

};

class Stack : public List
{
	struct StackNode
	{
		int Value;
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

	virtual void Clear()
	{
		while (head != nullptr)
		{
			StackNode* forDelete = head;
			head = head->Next;
			delete forDelete;
		}
	}

	virtual void Push(int value)
	{
		if (head == nullptr)
		{
			head = new StackNode();
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

	virtual int Pop()
	{
		int result = head->Value;
		StackNode* forDelete = head;
		head = head->Next;

		delete forDelete;
		return result;
	}

	virtual void ForEach(const function<void(int)> action) const
	{
		StackNode* current = head;
		while (current != nullptr)
		{
			action(current->Value);
			current = current->Next;
		}
	}
};

class Queue : public List
{
	struct QueueNode
	{
		int Value;
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

	virtual void Clear()
	{
		while (head != nullptr)
		{
			QueueNode* forDelete = head;
			head = head->Next;
			delete forDelete;
		}
		tail = nullptr;
	}

	virtual void Push(int value)
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

	virtual int Pop()
	{
		if (head == nullptr)
			return 0;
		int result = head->Value;
		QueueNode* forDelete = head;
		head = head->Next;

		if (head == nullptr)
			tail = nullptr;
		delete forDelete;
		return result;
	}

	virtual void ForEach(const function<void(int)> action) const
	{
		QueueNode* current = head;
		while (current != nullptr)
		{
			action(current->Value);
			current = current->Next;
		}
	}
};