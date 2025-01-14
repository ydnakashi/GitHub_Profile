#ifndef RIDESHARE_H
#define RIDESHARE_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Driver.h"
#include "Customer.h"
#include "List.h"
#include "Drawable.h"

using namespace std;

class RideShare {
    public:
        RideShare();
        ~RideShare();
        
        // List manipulation
        void addDriver(const string& name, Size size, int rating, Location loc);
        void addCustomer(const string& name, int rating, Location loc);

        // getters
        Customer* getCustomer(const string& id) const;

        // other
        Driver* findRide(int rating, Size size, Location loc) const;
        void printCustomers() const;
        void printDrivers() const;
        void draw(View&) const;

    private:
        List<Driver*>* drivers;
        List<Customer*>* customers;
        List<Drawable*>* drawables;
};

#endif