#pragma once
#include <iostream>

class Date {
private:
	int _day;
	int _month;
	int _year;
public:
	Date(int, int, int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	friend bool operator<(const Date& left, const Date& right) {
		if (left.getYear() < right.getYear())
			return true;
		else if (left.getYear() == right.getYear())
		{
			if (left.getMonth() < right.getMonth())
				return true;
			else if (left.getMonth() == right.getMonth())
			{
				if (left.getDay() < right.getDay())
					return true;
			}
		}
		return false;
	};
	friend bool operator==(const Date& left, const Date& right) {
		if (left.getYear() < right.getYear())
			return true;
		else if (left.getYear() == right.getYear())
		{
			if (left.getMonth() < right.getMonth())
				return true;
			else if (left.getMonth() == right.getMonth())
			{
				if (left.getDay() < right.getDay())
					return true;
			}
		}
		return false;
	};
	friend bool operator<=(const Date& left, const Date& right) {
		if (left == right)
			return true;
		if (left < right)
			return true;
		return false;
	};
};

std::ostream& operator<< (std::ostream&, const Date&);
const std::unique_ptr<Date>& findBiggerDate(const std::unique_ptr<Date>&, const std::unique_ptr<Date>&);
void exchangeDatePointers(std::unique_ptr<Date>&, std::unique_ptr<Date>&);