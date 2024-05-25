#include <iostream>

using namespace std;

class MyString 
{
    char* str;

public:
    MyString() : MyString(80) {}

    MyString(int size) : str(new char[size]) {}

    MyString(const char* newStr) 
    {
        str = new char[strlen(newStr) + 1];
        strcpy_s(str, strlen(newStr) + 1, newStr);
    }

    ~MyString() 
    {
        delete[] str;
    }

    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy_s(str, strlen(other.str) + 1, other.str);
    }

    MyString& operator=(const MyString& other) {
        if (this == &other) return *this;

        delete[] str;
        str = new char[strlen(other.str) + 1];
        strcpy_s(str, strlen(other.str) + 1, other.str);
        return *this;
    }

    MyString(MyString&& other)
    {
        str = other.str;
        other.str = nullptr;
    }

    MyString& operator=(MyString&& other)
    {
        if (this == &other)
            return *this; 

        delete[] str;
        str = other.str;
        other.str = nullptr;
        return *this;
    }

    char& operator[](int index)
    {
        return str[index];
    }

    const char& operator[](int index) const
    {
        return str[index];
    }

    int operator()(int symbol)
    {
        int size = strlen(str);
        for (int i = 0; i < size; i++)
            if (str[i] == symbol)
                return i;
        return -1;
    }

    operator int() const
    {
        return strlen(str);
    }
    
    const char* Get() const { return str; }
    void Set(const char* newStr) 
    {
        delete[] str;
        str = new char[strlen(newStr) + 1];
        strcpy_s(str, strlen(newStr) + 1, newStr);
    }

    
};

void main() 
{
    MyString str;
    str.Set("priva");
    cout << str.Get() << endl;

    MyString str2 = str; 
    cout << str2.Get() << endl;

    MyString str3;
    str3 = move(str2);
    cout << str3.Get() << endl;

    system("pause");
}
