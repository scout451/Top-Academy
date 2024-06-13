#pragma once

template <class T>
class List
{
public:
    virtual ~List() = default;

    virtual int GetSize() const = 0;
    virtual bool IsEmpty() const = 0;

    virtual T GetFront() const = 0;
    virtual T GetBack() const = 0;
    virtual void Add(const int index, const T& value) = 0;
    virtual void AddToFront(const T& value) = 0;
    virtual void AddToBack(const T& value) = 0;
    virtual void Remove(const int index) = 0;
    virtual void RemoveFromFront() = 0;
    virtual void RemoveFromBack() = 0;

    virtual void Clear() = 0;

    virtual T operator[](const int index) const = 0;
    virtual T& operator[](const int index) = 0;
};