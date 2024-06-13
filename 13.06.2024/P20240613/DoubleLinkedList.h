#pragma once

#include "List.h"

template <class T>
class DoublyLinkedList : public List<T>
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
    DoublyLinkedList() :size(0), head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() override {}

    DoublyLinkedList(const DoublyLinkedList& other)
    {
        Node<T>* current = other.head;
        while (current != nullptr)
        {
            this->push_back(current->value);
            current = current->next;
        }
    }

    DoublyLinkedList(DoublyLinkedList&& other) : size(other.size), head(other.head), tail(other.tail)
    {
        other.size = 0;
        other.head = nullptr;
        other.tail = nullptr;
    }

    DoublyLinkedList& operator=(const DoublyLinkedList& other)
    {
        if (this == &other)
            return *this;

        Clear();

        Node<T>* current = other.head;
        while (current != nullptr)
        {
            this->AddToBack(current->value);
            current = current->next;
        }
        return *this;
    }

    DoublyLinkedList& operator=(DoublyLinkedList&& other)
    {
        if (this == &other)
            return *this;

        Clear();
        size = other.size;
        head = other.head;
        tail = other.tail;
        other.size = 0;
        other.head = nullptr;
        other.tail = nullptr;

        return *this;
    }

    int GetSize() const override { return size; }

    bool IsEmpty() const override
    {
        return head->next == nullptr;
    }

    T GetFront() const override { return head->value; }

    T GetBack() const override { return tail->value; }

    T& operator[](const int index) override
    {
        Node<T>* current = head;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        return current->value;
    }

    T operator[](const int index) const override
    {
        Node<T>* current = head;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        return current->value;
    }

    void AddToBack(const T& value) override
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

    void AddToFront(const T& value) override
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

    void Add(const int index, const T& value) override
    {
        if (index == 0)
        {
            AddToFront(value);
        }
        else if (index == size)
        {
            AddToFront(value);
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

    void RemoveFromFront() override
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
    }

    void Remove(const int index) override
    {
        if (index == 0)
        {
            RemoveFromBack();
        }
        else if (index == size - 1)
        {
            RemoveFromBack();
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

    void RemoveFromBack() override
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
    }

    void Clear() override
    {
        while (size)
        {
            RemoveFromBack();
        }
    }
};

