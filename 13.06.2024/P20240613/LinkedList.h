#pragma once

#include "List.h"

template <class T>
class LinkedList : public List<T>
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
	Node<T>* tail;

public:
	LinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	~LinkedList()
	{
		Clear();
	}

	bool IsEmpty() const override
	{
		return head == nullptr;
	}

	virtual T GetFront() const
	{
		return head->value;
	}

	virtual T GetBack() const
	{
		return tail->value;
	}

	LinkedList(const LinkedList& other)
	{
		Node<T>* current = other.head;
		while (current != nullptr)
		{
			this->AddToBack(current->value);
			current = current->next;
		}
	}

	LinkedList& operator=(LinkedList& other)
	{
		if (this == &other)
			return *this;

		Clear();

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

	LinkedList(LinkedList&& other) : size(other.size), head(other.head), tail(other.tail)
	{
		other.size = 0;
		other.head = nullptr;
		other.tail = nullptr;
	}

	LinkedList& operator=(LinkedList&& other)
	{
		if (this != &other)
		{
			Clear();
			size = other.size;
			head = other.head;
			tail = other.tail;
			other.size = 0;
			other.tail = nullptr;
			other.head = nullptr;
		}
		return *this;
	}

	virtual T& operator[](const int index)
	{
		Node<T>* current = this->head;
		int counter = 0;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->value;
			}
			current = current->next;
			counter++;
		}
	}

	virtual T operator[](const int index) const
	{
		Node<T>* current = this->head;
		int counter = 0;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->value;
			}
			current = current->next;
			counter++;
		}
	}

	virtual int GetSize() const { return size; }

	virtual void AddToBack(const T& value)
	{
		if (head == nullptr)
		{
			head = tail = new Node<T>(value);
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

	virtual void AddToFront(const T& value)
	{
		head = new Node<T>(value, head);
		size++;
	}

	virtual void Add(const int index, const T& value)
	{
		if (index == 0)
		{
			AddToFront(value);
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

	virtual void RemoveFromFront()
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		size--;
	}

	virtual void Remove(const int index)
	{
		if (index == 0)
		{
			RemoveFromFront();
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

	virtual void RemoveFromBack()
	{
		Remove(size - 1);
	}

	virtual void Clear()
	{
		while (size)
		{
			RemoveFromFront();
		}
	}
};