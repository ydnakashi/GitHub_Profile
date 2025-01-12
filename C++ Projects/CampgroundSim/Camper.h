#ifndef CAMPER_H
#define CAMPER_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Camper {
    private:
        string name;
        string plate_number;
        int num_people;
        Date check_in, check_out;
    public:
        // constructors
        Camper(const string&, const string&, const int&, Date&, Date&);
        Camper();

        // setters
        void setCamper(const string&, const string&, const int&, Date&, Date&);

        // getters
        string getName();
        Date getCheckIn();
        Date getCheckOut();

        // other functions
        void print();
};

#endif