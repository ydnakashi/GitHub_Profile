#ifndef CAMPGROUND_H
#define CAMPGROUND_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Campsite.h"
#include "Category.h"

using namespace std;

class Campground {
    private:
        Campsite campsites[MAX_ARRAY];
        int num_campsites;

        // helper functions
        // Find matching index in campground array with given campsite number
        int findCampsite(const int&);
    public:
        // Constructor
        Campground();
        
        void addCampsite(const int&, const cat::Category&, const string&, const int&, const double&);
        void removeCampsite(const int&);
        void addCamper(const int&, const string&, const string&, const int&, Date&, Date&);
        void removeCamper(const int&, const string&);
        void printCampsites();
        void printCampers(const int&);
        void printCampers(Date&);
        void printCampsitesByCategory(const cat::Category&);
};

#endif