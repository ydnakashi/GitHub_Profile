
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


class Date {
		
	public:
		//constructor
		Date();
		Date(int year, int month, int day);
		Date(Date&);
		
		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		
		void setDate(int, int, int);
		void setDate(Date&);
		
		//getters
		int getDay();
		int getMonth();
		int getYear();
		string getMonthName();
		string getShortMonthName();
		
		//other
		bool isLeapYear(int year);
		
		void print();
		int convertToDays();

		// comparisons
		bool equals(Date&); // Returns true if dates are equal, otherwise false
		bool lessThan(Date&); // Returns true if date in question is before argument date, otherwise false (equal is false)
		bool moreThan(Date&); // Returns true if date in question is after argument date, otherwise false, (equals is false)
	
	private:
		//functions
		int getDaysInMonth();	
	
		//variables
		int day;
		int month;
		int year;	
};
#endif
