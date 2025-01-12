#ifndef FILE_H  
#define FILE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

class File {
    private:
        string name, content;
        Date date;
    
    public:
        File(string, string, Date&);
        bool lessThan(Date&);
        void print();
        void printContents();
        Date getDate();
        string getName();
};

#endif