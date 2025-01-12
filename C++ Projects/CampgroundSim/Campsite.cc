#include "Campsite.h"

// Bounds Check
void Campsite::boundsCheck() {
    if (price_per_day <= 0)
        price_per_day = 1;
    if (max_people < 1)
        max_people = 1;
}

// Helper Function
// Returns matching index in campers array from given camper name
int Campsite::findCamper(const string& name) {
    for (int i = 0; i < members; ++i) {
        if (campers[i].getName().compare(name) == 0)
            return i;
    }
    return -1;
}

// Constructor
Campsite::Campsite(const int& site_number, const cat::Category& category, const string& description, const int& max_people, const double& price_per_day) {
    this->site_number = site_number;
    this->category = category;
    this->description = description;
    this->max_people = max_people;
    this->price_per_day = price_per_day;
    campers;
    members = 0;
    boundsCheck();
}

Campsite::Campsite() {
    site_number = 0;
    category = cat::cabin;
    description = "";
    max_people = 1;
    price_per_day = 1.00;
    campers;
    members = 0;
    boundsCheck();
}

// getters
int Campsite::getSiteNumber() {
    return site_number;
}

cat::Category Campsite::getCategory() {
    return category;
}

// setters
void Campsite::setCampsite(const int& site_number, const cat::Category& category, const string& description, const int& max_people, const double& price_per_day) {
    this->site_number = site_number;
    this->category = category;
    this->description = description;
    this->max_people = max_people;
    this->price_per_day = price_per_day;
    campers;
    members = 0;
    boundsCheck();
}

// other functions
bool Campsite::addCamper(const string& name, const string& plate_number, const int& num_people, Date& check_in, Date& check_out) {
    if (members == max_people || check_out.lessThan(check_in))
        return false;
    else if (members == 0) {
        campers[0].setCamper(name, plate_number, num_people, check_in, check_out);
    }
    else {
        for (int i = 0; i < members; ++i) {
            if (campers[i].getName().compare("-1") != 0 && (campers[i].getCheckIn().lessThan(check_out) && !campers[i].getCheckIn().lessThan(check_in))) {
                return false;
            }
        }
        for (int i = 0; i < members; ++i) {
            if (campers[i].getName().compare("-1") == 0 || (campers[i].getCheckIn().moreThan(check_in) && !campers[i].getCheckIn().lessThan(check_out))) {
                for (int j = members; j > i; --j) {
                    campers[j] = campers[j-1];
                }     
                campers[i].setCamper(name, plate_number, num_people, check_in, check_out);
                break;
            }
        }
    }
    ++members;
    return true;
}

bool Campsite::removeCamper(string name) {
    int matchingCamper = findCamper(name);
    if (matchingCamper == -1)
        return false;
    for (int i = matchingCamper; i < members; ++i)
        campers[i] = campers[i+1];
    --members;
    return true;
}

void Campsite::print() {
    cout <<"Site Number: " <<site_number <<endl
         <<"Cateogry: " <<categoryToString(category) <<endl
         <<"Description: " <<description <<endl
         <<"Max People: " <<max_people <<endl;
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout <<"Price per Day: $" <<price_per_day <<endl;
}

void Campsite::printCampers() {
    for (int i = 0; i < members; ++i) {
        campers[i].print();
    }
}

void Campsite::printCamper(Date& date) {
    for (int i = 0; i < members; ++i) {
        if (!campers[i].getCheckIn().moreThan(date) && campers[i].getCheckOut().moreThan(date)) {
            campers[i].print();
        }
    }
}

