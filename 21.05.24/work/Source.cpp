#include <iostream>
#include <algorithm>
#include <string>
#include <span>

using namespace std;

class TimeSpan
{
	long long totalMilliseconds;
	
public:
	int GetDays() const { return totalMilliseconds / 1000 / 60 / 60/ 24; };

	int GetHours() const { return totalMilliseconds / 1000 / 60 / 60 % 60; };
	int GetTotalHours() const { return totalMilliseconds / 1000 / 60 / 60; };

	int GetMinutes() const { return totalMilliseconds / 1000 / 60 % 60; };
	int GetTotalMinutes() const { return totalMilliseconds / 1000 / 60; };
	
	int GetSeconds() const { return totalMilliseconds / 1000 % 60; };
	int GetTotalSeconds() const { return totalMilliseconds / 1000; };

	int GetTotalMilliseconds() const { return totalMilliseconds; } ;

	TimeSpan operator-(const TimeSpan& right) const
	{
		TimeSpan temp(*this);
		temp.totalMilliseconds - right.totalMilliseconds;

		return temp;
	}

	TimeSpan operator+(const TimeSpan& right) const
	{
		TimeSpan temp(*this);
		totalMilliseconds + right.totalMilliseconds;

		return temp;
	}

	TimeSpan AddDays(int days)
	{
		totalMilliseconds += days * 24 * 60 * 60 * 1000;

		return *this;
	}
	TimeSpan AddHours(int hours)
	{
		totalMilliseconds += hours * 60 * 60 * 1000;

		return *this;
	}
	TimeSpan AddMinutes(int minutes)
	{
		totalMilliseconds += minutes * 60 * 1000;

		return *this;
	}
	TimeSpan AddSeconds(int seconds)
	{
		totalMilliseconds += seconds * 1000;

		return *this;
	}
	TimeSpan AddMilliseconds(int milliseconds)
	{
		totalMilliseconds += milliseconds;

		return *this;
	}


	string& ToString()
	{
		string str;
		str = to_string(totalMilliseconds);
	}
	string& ToString(
		string daysSeparator,
		string timeSeparator,
		string millisecondsSeparator)
	{
		string str;
		str = to_string(totalMilliseconds / 1000 / 60 / 60 / 24) + daysSeparator + to_string(totalMilliseconds / 1000 / 60 / 60) +
			to_string(totalMilliseconds / 1000 / 60) + timeSeparator + to_string(totalMilliseconds / 1000) +
			millisecondsSeparator + to_string(totalMilliseconds / 1000);
	}
	string& ToString(
		string daysHoursSeparator,
		string hoursMinutesSeparator,
		string minutesSecondsSeparator,
		string secondsMillisecondsSeparator)
	{
		string str;
		str = to_string(totalMilliseconds / 1000 / 60 / 60 / 24) + daysHoursSeparator + to_string(totalMilliseconds / 1000 / 60 / 60) +
			hoursMinutesSeparator + to_string(totalMilliseconds / 1000 / 60) + minutesSecondsSeparator + to_string(totalMilliseconds / 1000) +
			secondsMillisecondsSeparator + to_string(totalMilliseconds / 1000);
	}

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
	DateTime() : DateTime(0, 0, 0, 0, 0, 0, 0) {}

	DateTime(int year, int month, int day) : DateTime(year, month, day, 0, 0, 0, 0) {}

	DateTime(int year, int month, int day, int hours, int minutes, int seconds) : DateTime(year, month, day, hours, minutes, seconds, 0) {}

	DateTime(int year, int month, int day, int hours, int minutes, int seconds, int milliseconds) 
	{
		this->year = year;
		this->month = month;
		this->day = day;
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
		this->milliseconds = milliseconds;
	}

	int GetYear() const { return year; };
	int SetYear(int year) {	this->year = year; };

	int GetMonth() const { return month; };
	int SetMonth(int month) { this->month = month; };

	int GetDay() const { return day; };
	int SetDay(int day) { this->day = day; };

	int GetHours() const { return hours; };
	int SetHours(int hours) { this->hours = hours; };

	int GetMinutes() const { return minutes; };
	int SetMinutes(int minutes) { this->minutes = minutes; };

	int GetSeconds() const { return seconds; };
	int SetSeconds(int seconds) { this->seconds = seconds; };

	int GetMilliseconds() const { return milliseconds; };
	int SetMilliseconds(int milliseconds) { this->milliseconds = milliseconds; };


	DateTime operator+(const TimeSpan& right) const
	{
		DateTime temp(*this);
		temp.day += right.GetDays();
		if (temp.day >= 30)
		{
			temp.month += temp.day / 30;
			temp.day = temp.day % 30;
		}

		temp.hours += right.GetHours();
		if (temp.hours >= 24)
		{
			temp.day += temp.hours / 24;
			temp.hours = temp.hours % 24;
		}

		temp.minutes += right.GetMinutes();
		if (temp.minutes >= 60)
		{
			temp.hours += temp.minutes / 60;
			temp.minutes = temp.minutes % 60;
		}

		temp.seconds += right.GetSeconds();
		if (temp.seconds >= 60)
		{
			temp.minutes += temp.seconds / 60;
			temp.seconds = temp.seconds % 60;
		}

		temp.milliseconds += right.GetTotalMilliseconds();
		if (temp.seconds >= 1000)
		{
			temp.seconds += temp.milliseconds / 1000;
			temp.milliseconds = temp.milliseconds % 1000;
		}

		if (temp.day > 30)
		{
			temp.month += temp.day / 30;
			temp.day = temp.day % 30;
		}

		if (temp.month > 12)
		{
			temp.year += temp.month / 12;
			temp.month = temp.month % 12;
		}
		
		return temp;
	}
	friend DateTime operator+(const TimeSpan& left, const DateTime& right)
	{
		DateTime temp(right);
		temp.day += left.GetDays();
		if (temp.day > 30)
		{
			temp.month += temp.day - 30;
			temp.day = temp.day % 30;
		}

		return temp;
	}

	TimeSpan operator-(const DateTime& right) const
	{
		DateTime temp(*this);
		temp.day -= right.GetDays();
		if (temp.day > 30)
		{
			temp.month -= temp.day - 30;
			temp.day = temp.day % 30;
		}

		return temp;
	}
	DateTime operator-(const TimeSpan& right) const;
	friend DateTime operator-(const TimeSpan& left, const DateTime& right);

	string ToString() const;
} ;

void main()
{

	system("pause");
}