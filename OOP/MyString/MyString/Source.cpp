#include <iostream>

using namespace std;

class MyString
{
    char* str;

public:

    MyString() : str(new char[80]) {} // Конструктор по умолчанию

    MyString(int size) : str(new char[size])
    {}

    MyString(const char* newStr)
    {
        if (str != nullptr)
        {
            delete[] str;
            str = nullptr;
        }

        // Выделяем память для новой строки
        str = new char[strlen(newStr) + 1]; // +1 для нуль-терминатора
        strcpy_s(str, strlen(newStr) + 1, newStr);
    }

    ~MyString() 
    {
        if (str != nullptr) 
            delete[] str; 
    } // Деструктор для освобождения памяти

    const char* Get() { return str; }
    void Set(const char* newStr)
    {
        // Удаляем старую строку, если она есть
        if (str != nullptr)
        {
            delete[] str;
            str = nullptr;
        }

        // Выделяем память для новой строки
        str = new char[strlen(newStr) + 1];
        strcpy_s(str, strlen(newStr) + 1, newStr);
    }
};

int main()
{
    MyString str;
    str.Set("priva");
    cout << str.Get() << endl;

    return 0;
}
