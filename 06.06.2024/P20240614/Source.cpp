#include <iostream>
#include <string>

using namespace std;

int Convert(string str)
{
	if (str == "\0")
		throw("String is NULL");

	long long result = 0;

	for(int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
			throw("String is contains letter");

		result = result * 10 + (str[i] - '0');
		if (result > numeric_limits<int>::max())
			throw("Went beyond the borders of INT");
	}
	
	return result;
}

void TryCatch(string str)
{
	try
	{
		cout << "Received int: " << Convert(str) << endl;
	}
	catch (const char* error)
	{
		cout << "Error: " << error << endl;
	}
}

void main()
{
	string str = "3147483647";
	string str1 = "123";
	string str2 = "Af421";

	TryCatch(str);
	TryCatch(str1);
	TryCatch(str2);

	system("pause");
}
