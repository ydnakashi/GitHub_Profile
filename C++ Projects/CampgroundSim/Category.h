#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>

using namespace std;

namespace cat{
    
    enum Category {rv_site, cabin, lodge, tent, trailer, misc};

    string categoryToString(Category c);
    Category stringToCategory(const string& s);

}
#endif