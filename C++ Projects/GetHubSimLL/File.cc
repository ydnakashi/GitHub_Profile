#include "File.h"

File::File(const string& name, const string& content, const Date& date): lastModified(date), name(name), content(content) {}

File::File(const File& e): File(e.name, e.content, e.lastModified){  }

void File::print() const{
	cout <<"File:          "<<name<<endl;
	cout <<"Last modified: ";
	lastModified.print(); cout<<endl;
}

bool File::lessThan(File& e) const {
	int ord = name.compare(e.name);
	if (ord == 0)
		return (lastModified.lessThan(e.lastModified));
	return (ord < 0);
}

bool File::equals(File& e) const {
	return (name.compare(e.name) == 0 && lastModified.equals(e.lastModified));
}

void File::printContents() const {
	print();
	cout <<endl<< content<<endl<<endl;
}

