#include "Camper.h"

// constructors
Camper::Camper(const string &name, const string &plate_number, const int &num_people, Date &check_in, Date &check_out) {
    this->name = name;
    this->plate_number = plate_number;
    this->num_people = num_people;
    this->check_in = check_in;
    this->check_out = check_out;
}

Camper::Camper() {
    name = "-1";
    plate_number = "DUMMY000";
    num_people = 1;
    check_in;
    check_out;
}

// setters
void Camper::setCamper(const string &name, const string &plate_number, const int &num_people, Date &check_in, Date &check_out) {
    this->name = name;
    this->plate_number = plate_number;
    this->num_people = num_people;
    this->check_in = check_in;
    this->check_out = check_out;
}

// getters
string Camper::getName() {
    return name;
}

Date Camper::getCheckIn() {
    return check_in;
}

Date Camper::getCheckOut() {
    return check_out;
}

//other functions
void Camper::print() {
    cout <<"Camper " <<name <<"\n    Plate Number: " <<plate_number <<"\n    # of people: " <<num_people <<endl;
    cout <<"    Check in Date: "; check_in.print();
    cout <<"    Check out Date: "; check_out.print();
}







