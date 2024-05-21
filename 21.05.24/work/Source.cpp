#include <iostream>
#include <algorithm>
#include <string>
#include <span>

using namespace std;

class TimeSpan
{
	long long totalMilliseconds;
	
public:
	int GetDays();
	int GetHours();
	int GetMinutes();
	int GetSeconds();
	int GetMilliseconds();

	TimeSpan operator-(const TimeSpan& right) const;
	TimeSpan operator+(const TimeSpan& right) const;

	TimeSpan AddDays(int days)
	{
		return *this;
	}
	TimeSpan AddHours(int hours);
	TimeSpan AddMinutes(int minutes);
	TimeSpan AddSeconds(int seconds);
	TimeSpan AddMilliseconds(int milliseconds);

	string ToString();
	string ToString(string daysSeparator, 
					string timeSeparator, 
					string millisecondsSeparator);
	string ToString(string daysHoursSeparator, 
					string hoursMinutesSeparator, 
					string minutesSecondsSeparator,
					string secondsMillisecondsSeparator );

};

class DateTime
{
	unsigned short year;
	unsigned char month;
	unsigned char day;
	unsigned char hours;
	unsigned char minutes;
	unsigned char seconds;
	unsigned short milliseconds;

public:
	DateTime() {}

	DateTime(int year, int month, int day) 
	{

	}

	DateTime(int year, int month, int day, int hours, int minutes, int seconds) 
	{

	}

	DateTime(int year, int month, int day, int hours, int minutes, int seconds, int milliseconds) 
	{

	}

	int GetYear();
	int SetYear(int year);

	int GetMonth();
	int SetMonth(int month);

	int GetDay();
	int SetDay(int day);

	int GetHours();
	int SetHours(int hours);

	int GetMinutes();
	int SetMinutes(int minutes);

	int GetSeconds();
	int SetSeconds(int seconds);

	int GetMilliseconds();
	int SetMilliseconds(int milliseconds);


	DateTime operator+(const TimeSpan& right) const;
	friend DateTime operator+(const TimeSpan& left, const DateTime& right);

	TimeSpan operator-(const DateTime& right) const;
	DateTime operator-(const TimeSpan& right) const;
	friend DateTime operator-(const TimeSpan& left, const DateTime& right);

	string ToString();
};

void main()
{
	system("pause");
}