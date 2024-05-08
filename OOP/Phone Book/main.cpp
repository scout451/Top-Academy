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
	PhoneBook Book;

	Book.SetName("Nikita");

	system("pause");
}