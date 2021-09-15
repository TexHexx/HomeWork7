#include "Date.h"

Date::Date(int day, int month, int year) : _day(day), _month(month), _year(year) {};
int Date::getDay() const { return _day; };
int Date::getMonth() const { return _month; };
int Date::getYear() const { return _year; };
void Date::setDay(int day) { _day = day; };
void Date::setMonth(int month) { _month = month; };
void Date::setYear(int year) { _year = year; };

std::ostream& operator<< (std::ostream& out, const Date& date) {
	out << date.getDay() << "." << date.getMonth() << "." << date.getYear();
	return out;
};

const std::unique_ptr<Date>& findBiggerDate (const std::unique_ptr<Date>& date1, const std::unique_ptr<Date>& date2) {
	if (*date1 <= *date2)
		return date2;
	return date1;
};

void exchangeDatePointers(std::unique_ptr<Date>& date1, std::unique_ptr<Date>& date2) {
	auto tmp = std::move(date1);
	date1 = std::move(date2);
	date2 = std::move(tmp);
};
