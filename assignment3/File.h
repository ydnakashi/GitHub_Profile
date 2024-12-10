
#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;


class File {
		
	public:
		//constructor
		File(const string& name, const string& content, const Date& date);
		
		//copy constructor
		File(const File&);

		// comparisons
		bool lessThan(File&) const;
		bool equals(File&) const;

		// getters
		const string& getName() const {return name;}
		
		//other
		void print() const;
		void printContents() const;
	
	private:
		Date lastModified;
		string name;
		string content;
};
#endif
