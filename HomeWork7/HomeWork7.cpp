#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

void FirstTask() {
	time_t local_time = time(0);
	std::unique_ptr<Date> date = nullptr;
	std::unique_ptr<Date> today = std::make_unique<Date>(localtime(&local_time)->tm_mday, localtime(&local_time)->tm_mon + 1, localtime(&local_time)->tm_year + 1900);
	std::cout << "Today manual cout: " << today->getDay() << "." << today->getMonth() << "." << today->getYear() << std::endl;
	std::cout << "Today internal cout: " << *today << std::endl;
	date = std::move(today);

	if(today == nullptr)
		std::cout << "Today is nullptr now" << std::endl;
	else
		std::cout << "Today internal cout: " << *today << std::endl;
	
	if (date == nullptr)
		std::cout << "Date is nullptr now" << std::endl;
	else
		std::cout << "Date internal cout: " << *date << std::endl;
};

void SecondTask() {
	std::unique_ptr<Date> date1 = std::make_unique<Date>(15,9,2014);;
	std::unique_ptr<Date> date2 = std::make_unique<Date>(8,1,2012);
	std::cout << "Date1: " << *date1 << std::endl;
	std::cout << "Date2: " << *date2 << std::endl;
	std::cout << "Bigger date: " << *findBiggerDate(date1, date2) << std::endl;
	exchangeDatePointers(date1, date2);
	std::cout << "Date1: " << *date1 << std::endl;
	std::cout << "Date2: " << *date2 << std::endl;
};


int main()
{
	FirstTask();
	SecondTask();
	return 0;
}
