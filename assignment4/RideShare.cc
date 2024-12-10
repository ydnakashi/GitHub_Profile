#include "RideShare.h"

RideShare::RideShare() {
    drivers = new List<Driver*>(Driver::compRatings);
    customers = new List<Customer*>(Customer::compNames);
    drawables = new List<Drawable*>(Drawable::compare);
}

RideShare::~RideShare() {
    drawables->clear();
    delete drawables;
    delete drivers;
    delete customers;
}

// List manipulation
void RideShare::addDriver(const string& name, Size size, int rating, Location loc) {
    Driver* newDriver = new Driver(name, rating, size, loc);
    drivers->add(newDriver);
    drawables->add(newDriver);
}

void RideShare::addCustomer(const string& name, int rating, Location loc) {
    Customer* newCus = new Customer(name, rating, loc);
    customers->add(newCus);
    drawables->add(newCus);
}

// getters
Customer* RideShare::getCustomer(const string& id) const {
    for (int i = 0; i < customers->getSize(); ++i) {
        if (customers->get(i)->getId() == id)
            return customers->get(i);
    }
    return nullptr;
}

// other
Driver* RideShare::findRide(int rating, Size size, Location loc) const {
    Driver* closestDriver = nullptr;
    Driver* currDriver;
    for (int i = 0; i < drivers->getSize(); ++i) {
        currDriver = drivers->get(i);
        if (currDriver->match(size, rating)) {
            if (closestDriver == nullptr || currDriver->getDistance(loc) < closestDriver->getDistance(loc))
                closestDriver = currDriver;
        }
    }
    return closestDriver;
}

void RideShare::printCustomers() const {
    for (int i=0; i < customers->getSize(); ++i) {
        customers->get(i)->print();
    }
}

void RideShare::printDrivers() const {
    for (int i=0; i < drivers->getSize(); ++i) {
        drivers->get(i)->print();
    }
}

void RideShare::draw(View& view) const {
    for (int i=0; i < drawables->getSize(); ++i)
        drawables->get(i)->draw(view);
}