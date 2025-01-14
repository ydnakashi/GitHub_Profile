#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <iostream>
#include "defs.h"
#include "User.h"
#include "Drawable.h"
#include "View.h"

using namespace std;

class Driver: public User, public Drawable {
    public:
        Driver(string, int, const Size, const Location&);
        void print() const;

        void draw(View&) const;
        bool match(const Size inSize, const int inRat) const;

        int getDistance(const Location& dest) {return loc.getDistance(dest);}

        static int compRatings(Driver* c1, Driver* c2){
            return c1->getRating() - c2->getRating();
        }

        static int compNames(Driver* c1, Driver* c2){
            return c1->getName() < c2->getName();
        }

        static void resetNextId(){
            nextId = 0;
        }
        
    private:
        Size size;
        static const char code;
        static const int driverLayer;
        static int nextId;
};

#endif
