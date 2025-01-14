
#include "Driver.h"
#include <iomanip>

const int Driver::driverLayer = 1;
int Driver::nextId = 0;
const char Driver::code = 'D';

Driver::Driver(string n, int r, const Size size, const Location& l): Drawable(driverLayer), User(code, ++nextId, n, r, l), size(size) {}

void Driver::print() const {
    cout<<"Driver: "<<left<<setw(10)<<name;
    User::print();
    string sizeStr;
    if (size == small)
        sizeStr = "small";
    else if (size == medium)
        sizeStr = "medium";
    else
        sizeStr = "large";
    cout<<"  Size: " <<sizeStr <<endl;
}

void Driver::draw(View& v) const {
    //v.drawOnMap(*this);
    v.drawDriver(loc.x, loc.y, name[0]);
}

bool Driver::match(const Size inSize, const int inRat) const {
    bool sizeCheck = true;
    if (inSize == medium && size == small) sizeCheck = false;
    else if (inSize == large && (size == small || size == medium)) sizeCheck = false;
    return sizeCheck && (rating - inRat <= 2);
}

