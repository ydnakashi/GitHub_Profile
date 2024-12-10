#ifndef CAMPSITE_H
#define CAMPSITE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Category.h"
#include "Camper.h"
#include "defs.h"

using namespace std;

class Campsite {
    private:
        int site_number;
        cat::Category category;
        string description;
        int max_people;
        double price_per_day;
        Camper campers[MAX_ARRAY];
        int members; // number of Campers in campers array

        // Bounds check
        void boundsCheck();

        // Helper function
        // Returns matching index in campers array from given camper name
        int findCamper(const string& name);
    public:
        // constructors
        Campsite(const int&, const cat::Category&, const string&, const int&, const double&);
        Campsite();

        // getters
        int getSiteNumber(); 
        cat::Category getCategory();
        
        // setters
        void setCampsite(const int&, const cat::Category&, const string&, const int&, const double&);

        // other functions
        bool addCamper(const string&, const string&, const int&, Date&, Date&);
        bool removeCamper(string);
        void print();
        void printCampers();
        void printCamper(Date&);
};
#endif