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



template <typename TValue>
class LinkedList
{
protected:
	struct LinkedListNode
	{
		TValue Value;
		LinkedListNode* Next;

		LinkedListNode(const TValue& value, LinkedListNode* next)
		{
			Value = value;
			Next = next;
		}
	};

	LinkedListNode* head;
	LinkedListNode* tail;

public:
	LinkedList()
	{
		head = tail = nullptr;
	}

	~LinkedList()
	{
		Clear();
	}

	bool IsEmpty() const
	{
		return head == nullptr;
	}

	void Clear()
	{
		while (head != nullptr)
		{
			const LinkedListNode* forDelete = head;
			head = head->Next;
			delete forDelete;
		}

		tail = nullptr;
	}

	virtual void Push(const TValue& value)
	{
	}

	virtual TValue Pop()
	{
		return 0;
	}

	void ForEach(const function<void(TValue)> action) const
	{
		LinkedListNode* current = head;
		while (current != nullptr)
		{
			action(current->Value);
			current = current->Next;
		}
	}
};

template <typename TValue>
class Stack : public LinkedList<TValue>
{
public:
	void Push(const TValue& value) override
	{
		if (LinkedList<TValue>::IsEmpty())
			LinkedList<TValue>::head =
			LinkedList<TValue>::tail =
			new LinkedList<TValue>::LinkedListNode(
				value,
				nullptr);
		else
			LinkedList<TValue>::head =
			new LinkedList<TValue>::LinkedListNode(
				value,
				LinkedList<TValue>::head);
	}

	TValue Pop() override
	{
		if (LinkedList<TValue>::IsEmpty())
			return 0;

		const TValue result = LinkedList<TValue>::head->Value;
		const LinkedList<TValue>::LinkedListNode* forDelete =
			LinkedList<TValue>::head;

		LinkedList<TValue>::head = LinkedList<TValue>::head->Next;
		if (LinkedList<TValue>::head == nullptr)
			LinkedList<TValue>::tail = nullptr;

		delete forDelete;
		return result;
	}
};

template <typename TValue>
class Queue : public LinkedList<TValue>
{
public:
	void Push(const TValue& value) override
	{
		if (LinkedList<TValue>::IsEmpty())
			LinkedList<TValue>::head =
			LinkedList<TValue>::tail =
			new LinkedList<TValue>::LinkedListNode(value, nullptr);
		else
			LinkedList<TValue>::tail =
			LinkedList<TValue>::tail->Next =
			new LinkedList<TValue>::LinkedListNode(value, nullptr);
	}

	TValue Pop() override
	{
		if (LinkedList<TValue>::IsEmpty())
			return 0;

		const TValue result = LinkedList<TValue>::head->Value;
		const LinkedList<TValue>::LinkedListNode* forDelete =
			LinkedList<TValue>::head;

		LinkedList<TValue>::head = LinkedList<TValue>::head->Next;
		if (LinkedList<TValue>::head == nullptr)
			LinkedList<TValue>::tail = nullptr;

		delete forDelete;
		return result;
	}
};