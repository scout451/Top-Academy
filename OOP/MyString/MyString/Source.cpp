#include <iostream>
#include <string>

using namespace std;

//Встреча 18
//Задание 1

/*class Pet
{
	string name;
	string color;
public:
	Pet() : Pet("\0", "\0") {}

	Pet(string n, string c) : name(n), color(c) {}

	string GetName() { return name; }
	string SetName(string n) { name = n; }

	string GetColor() { return color; }
	string SetColor(string c) { color = c; }
};

class Cat : public Pet
{
	string catDistinctiveFeature;
public:
	Cat(string n, string c, string f) : Pet(n, c)
	{
		catDistinctiveFeature = f;
	}

	string PrintFeature()
	{
		return catDistinctiveFeature;
	}
};

class Dog : public Pet
{
	string dogDistinctiveFeature;
public:
	Dog(string n, string c, string f) : Pet(n, c)
	{
		dogDistinctiveFeature = f;
	}

	string PrintFeature()
	{
		return dogDistinctiveFeature;
	}
};

class Parrot : public Pet
{
	string parrotDistinctiveFeature;
public:
	Parrot(string n, string c, string f) : Pet(n, c)
	{
		parrotDistinctiveFeature = f;
	}

	string PrintFeature()
	{
		return parrotDistinctiveFeature;
	}
};

template <typename T>
void Print(T& pet)
{
	cout << pet.GetName() << ", " << pet.GetColor() << ", "
		<< pet.PrintFeature() << endl;
}
void main()
{
	Cat cat("CName", "CColor", "CFeature");
	Dog dog("DName", "DColor", "DFeature");
	Parrot parrot("PName", "PColor", "PFeature");

	Print(cat);
	Print(dog);
	Print(parrot);

	system("pause");
}*/

//Задание 2

#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
protected:
	char* str;

public:
	MyString() : MyString("") {}

	MyString(const char* newStr)
	{
		str = new char[strlen(newStr) + 1];
		strcpy_s(str, strlen(newStr) + 1, newStr);
	}

	~MyString()
	{
		delete[] str;
	}

	MyString(const MyString& other)
	{
		str = new char[strlen(other.str) + 1];
		strcpy_s(str, strlen(other.str) + 1, other.str);
	}

	MyString& operator=(const MyString& other)
	{
		if (this == &other) return *this;

		delete[] str;
		str = new char[strlen(other.str) + 1];
		strcpy_s(str, strlen(other.str) + 1, other.str);
		return *this;
	}

	MyString(MyString&& other) noexcept
	{
		str = other.str;
		other.str = nullptr;
	}

	MyString& operator=(MyString&& other) noexcept
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

	int operator()(int symbol) const
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

	int Size() const
	{
		return strlen(str);
	}

	void Clear()
	{
		delete[] str;
		str = new char[1];
		str[0] = '\0';
	}

	MyString operator+(const MyString& other) const
	{
		int newSize = strlen(str) + strlen(other.str) + 1;
		char* newStr = new char[newSize];
		strcpy_s(newStr, newSize, str);
		strcat_s(newStr, newSize, other.str);

		MyString newMyString(newStr);
		delete[] newStr;
		return newMyString;
	}

	MyString operator+=(const MyString& other) const
	{
		int newSize = strlen(str) + strlen(other.str) + 1;
		char* newStr = new char[newSize];
		strcpy_s(newStr, newSize, str);
		strcat_s(newStr, newSize, other.str);

		MyString newMyString(newStr);
		delete[] newStr;
		return newMyString;
	}

	bool operator==(const MyString& other) const
	{
		return strcmp(str, other.str) == 0;
	}

	bool operator!=(const MyString& other)
	{
		return strcmp(str, other.str) != 0;
	}
};

class BitString : public MyString
{
private:
	bool isValidBitString(const char* s)
	{
		for (int i = 0; s[i] != '\0'; ++i)
		{
			if (s[i] != '0' && s[i] != '1')
			{
				return false;
			}
		}
		return true;
	}

	int toInt() const
	{
		int value = 0;
		for (int i = 0; i < Size(); i++)
		{
			value = (value << 1) | (str[i] - '0');
		}

		return value;
	}

	char* intToBitString(int value) const
	{
		if (value == 0)
		{
			char* zeroStr = new char[2];
			zeroStr[0] = '0';
			zeroStr[1] = '\0';
			return zeroStr;
		}

		bool isNegative = (value < 0);
		if (isNegative)
			value = -value;

		int bitCount = sizeof(int) * 8;
		char* buffer = new char[bitCount + 1];
		buffer[bitCount] = '\0';

		for (int i = bitCount - 1; i >= 0; i--)
		{
			buffer[i] = (value & 1) ? '1' : '0';
			value >>= 1;
		}

		int startIndex = 0;
		while (startIndex < bitCount - 1 && buffer[startIndex] == '0')
		{
			startIndex++;
		}

		char* result = new char[bitCount - startIndex + 1];
		strcpy_s(result, bitCount - startIndex + 1, buffer + startIndex);
		delete[] buffer;

		if (isNegative)
		{
			for (int i = 0; result[i] != '\0'; i++)
				result[i] = (result[i] == '0') ? '1' : '0';

			bool shift = true;
			for (int i = strlen(result) - 1; i >= 0; i--)
			{
				if (shift)
				{
					if (result[i] == '1')
						result[i] = '0';
					else
					{
						result[i] = '1';
						shift = false;
					}
				}
				else
					break;
			}
		}
		return result;
	}
public:
	BitString() : MyString() {}

	BitString(const char* newStr) : MyString()
	{
		if (isValidBitString(newStr))
		{
			delete[] str;
			str = new char[strlen(newStr) + 1];
			strcpy_s(str, strlen(newStr) + 1, newStr);
		}
		else
			Clear();
	}

	BitString(const BitString& other) : MyString(other) { }

	BitString& operator=(const BitString& other)
	{
		if (this == &other) return *this;
		MyString::operator=(other);
		return *this;
	}

	BitString(BitString&& other) : MyString(move(other)) { }

	BitString& operator=(BitString&& other)
	{
		if (this == &other) return *this;
		MyString::operator=(move(other));
		return *this;
	}

	void negate()
	{
		for (int i = 0; i < Size(); ++i)
		{
			str[i] = (str[i] == '0') ? '1' : '0';
		}

		bool shift = true;
		for (int i = Size() - 1; i >= 0; --i)
		{
			if (shift)
			{
				if (str[i] == '1')
				{
					str[i] = '0';
				}
				else
				{
					str[i] = '1';
					shift = false;
				}
			}
			else
				break;
		}
	}

	BitString operator+(const BitString& other)
	{
		int thisVal = toInt();
		int otherVal = other.toInt();
		int resultVal = thisVal + otherVal;

		return BitString(intToBitString(resultVal));
	}

	bool operator==(const BitString& other) const
	{
		return strcmp(str, other.str) == 0;
	}

	bool operator!=(const BitString& other) const
	{
		return !(*this == other);
	}
};


void TestMyString()
{
	MyString str;
	str.Set("priva");
	cout << str.Get() << endl;

	MyString str2 = str;
	cout << str2.Get() << endl;

	MyString str3;
	str3 = move(str2);
	cout << str3.Get() << endl;

	MyString str4("qwe");
	MyString str5("rty");
	MyString str6;

	if (str == str4)
		cout << "Nice" << endl;
	if (str != str4)
		cout << "Not Nice" << endl;

	str6 = str4 + str5;
	cout << str6.Get() << endl;
}

void TestBitString()
{
	BitString bitStr1("1001");
	BitString bitStr2("0110");

	cout << "BitStr1: " << bitStr1.Get() << endl;
	cout << "BitStr2: " << bitStr2.Get() << endl;

	BitString bitStr3 = bitStr1 + bitStr2;
	cout << "BitStr1 + BitStr2: " << bitStr3.Get() << endl;

	bitStr1.negate();
	cout << "Negated BitStr1: " << bitStr1.Get() << endl;

	cout << "BitStr1 == BitStr2: " << (bitStr1 == bitStr2) << endl;
	cout << "BitStr1 != BitStr2: " << (bitStr1 != bitStr2) << endl;
}

void main()
{
	//TestMyString();

	//TestBitString();



	system("pause");
}
