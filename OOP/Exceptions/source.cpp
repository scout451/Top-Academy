#include <iostream>
#include <exception>
#include <string>

using namespace std;

// Базовый класс исключения
class MyException : public exception
{
protected:
	string message;

public:
	MyException(const string& msg) : message(msg)	{	}

	const char* Error() const	{ return message.c_str(); }
};

// Математические ошибки
class MathError : public MyException
{
public:
	MathError(const string& msg) : MyException("Math Error: " + msg)	{	}
};

class DivisionByZero : public MathError
{
public:
	DivisionByZero() : MathError("Division by zero")	{	}
};

class NegativeSqrt : public MathError
{
public:
	NegativeSqrt() : MathError("Square root of negative number")	{	}
};

// Проблемы с памятью
class MemoryError : public MyException
{
public:
	MemoryError(const string& msg) : MyException("Memory Error: " + msg)	{	}
};

class OutOfMemory : public MemoryError
{
public:
	OutOfMemory() : MemoryError("Out of memory")	{	}
};

class FileError : public MyException
{
public:
	FileError(const string& msg) : MyException("File Error: " + msg) {	}
};

class FileNotFound : public FileError
{
public:
	FileNotFound() : FileError("File not found")	{	}
};

class FileReadError : public FileError
{
public:
	FileReadError() : FileError("Error reading file")	{	}
};

class FileWriteError : public FileError
{
public:
	FileWriteError() : FileError("Error writing to file")	{	}
};

void main()
{
	try
	{
		throw DivisionByZero();
	}
	catch (const MyException& e)
	{
		cout << e.Error() << endl;
	}

	try
	{
		throw NegativeSqrt();
	}
	catch (const MyException& e)
	{
		cout << e.Error() << endl;
	}

	try
	{
		throw OutOfMemory();
	}
	catch (const MyException& e)
	{
		cout << e.Error() << endl;
	}

	try
	{
		throw FileNotFound();
	}
	catch (const MyException& e)
	{
		cout << e.Error() << endl;
	}

	try
	{
		throw FileReadError();
	}
	catch (const MyException& e)
	{
		cout << e.Error() << endl;
	}

	try
	{
		throw FileWriteError();
	}
	catch (const MyException& e)
	{
		cout << e.Error() << endl;
	}

	system("pause");
}