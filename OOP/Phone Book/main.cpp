#include <iostream>

using namespace std;

class PhoneBook
{
	char* Name;
	char* Surname;
	char* Patronymic;
	int HomeNumber;
	int WorkNumber;
	int MobileNumber;
	char Info;
public:

	PhoneBook() : PhoneBook('\0', '\0', '\0', 0, 0, 0)
	{
		
	}

	PhoneBook(const char n, const char s, const char p, int home, int work, int mobile)
	{

	}

	~PhoneBook()
	{
		cout << "call destr" << endl;
		delete[] Name;
	}

	const char GetName() { return *Name; }
	void SetName(const char *n)
	{
		delete[] Name;

		const int size = strlen(n) + 1;
		Name = new char[size];

		strcpy_s(Name, size, n);
	}

	const char GetSurname() { return *Surname; }
	void SetSurname()
	{}

	const char GetPatronymic() { return *Patronymic; }
	void SetPatronymic()
	{}

	int GetHomeNumber() { return HomeNumber; }
	void SetHomeNumber()
	{}

	int GetWorkNumber()	{ return WorkNumber; }
	void SetWorkNumber()
	{}

	int GetMobileNumber() { return MobileNumber; }
	void SetMobileNumber()
	{}

	const char GetInfo() { return Info; }
	void SetInfo()
	{}

};

void main()
{
	PhoneBook* Book = new PhoneBook;

	Book->SetName("Nikita");

	delete Book;

	system("pause");
}



/*class Student
{
	char* name;

public:
	Student() : Student("")
	{
		cout << "Call Student()" << endl;
	}

	Student(const char* n)
	{
		cout << "Call Student(const char* n)" << endl;

		const int size = strlen(n) + 1;
		name = new char[size];

		strcpy_s(name, size, n);
	}

	~Student()
	{
		cout << "Call ~Student()" << endl;

		delete[] name;
	}

	char* GetName()
	{
		return name;
	}

	void SetName(const char* n)
	{
		delete[] name;

		const int size = strlen(n) + 1;
		name = new char[size];

		strcpy_s(name, size, n);
	}
};

void Method()
{
	Student s1("qwerty");
	cout << "s1 created" << endl;
}

void main()
{
	cout << "Start" << endl;
	Student* s1 = new Student("qwerty");
	cout << "s1 created" << endl;
	s1->SetName("asdf");
	delete s1;
	cout << "s1 deleted" << endl;

	if (true)
	{
		cout << "Start" << endl;
		Student s1("qwerty");
		cout << "s1 created" << endl;
	}

	//cout << "Start" << endl;
	//Method();
	//Method();

	//Student* s1 = new Student("qwerty");
	//delete s1->GetName();
	//s1->SetName("asdf");
	//delete s1;

	//Student* arr1 = new Student[2];

	//Student** arr2 = new Student* [2];
	//for (int i = 0; i < 2; i++)
	//	arr2[i] = new Student("qwerty");

	system("pause");
}*/