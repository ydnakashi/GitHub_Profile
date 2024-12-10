#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include "defs.h"
#include "Location.h"
#include "View.h"

using namespace std;

class User {
    public:
        // constructors & destructors
        User(char, int, const string&, int, const Location&);

        // gettters
        const string& getId() const {return id;}
        const string& getName() const {return name;}
        int getRating() const {return rating;}
        const Location& getLocation() const {return loc;}

        // setters
        void setRating(int inRat) {rating = inRat;}
        void setLocation(const Location& inLocation) {loc = inLocation;}
        void setLocation(int x, int y) {loc.setLocation(x,y);}

        // other
        void print() const;

    protected:
        string id;
        string name;
        int rating;
        Location loc;
};

#endif