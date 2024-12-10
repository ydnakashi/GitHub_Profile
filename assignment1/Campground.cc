#include "Campground.h"

// helper function
// Find matching index in campground array with given campsite number
int Campground::findCampsite(const int& site_number) {
    for (int i = 0; i < num_campsites; ++i) {
        if (campsites[i].getSiteNumber() == site_number)
            return i;
    }
    return -1;
}

// constructor
Campground::Campground() {
    campsites;
    num_campsites = 0;
}

void Campground::addCampsite(const int& site_number, const cat::Category& category, const string& description, const int& max_people, const double& price_per_day) {
    if (num_campsites == MAX_ARRAY)  {
        cout <<"Campground is full, campsite addition failed." << endl;
        return;
    }
    else if (findCampsite(site_number) != -1) {
        cout <<"Campsite number duplicate found, campsite addition failed." <<endl;
        return;
    }
    campsites[num_campsites++].setCampsite(site_number, category, description, max_people, price_per_day);
    cout <<"Campsite addition successful" <<endl; 
}

void Campground::removeCampsite(const int& site_number) {
    int matchingSite = findCampsite(site_number);
    if (matchingSite != -1) {
        for (int j = matchingSite; j < num_campsites; ++j) {
                campsites[j] = campsites[j+1];
        }
        num_campsites--;
        cout <<"Campsite removal successful." <<endl;
        return;
    }
    cout <<"Campsite not found, removal failed." <<endl;
}

void Campground::addCamper(const int& site_number, const string &name, const string &plate_number, const int& num_people, Date &check_in, Date &check_out) {
    int matchingSite = findCampsite(site_number);
    if (matchingSite < 0)
        cout<<"Campsite " <<site_number <<" not found. Camper addition failed." <<endl;
    else if (campsites[matchingSite].addCamper(name, plate_number, num_people, check_in, check_out))
        cout<<"Camper addition to Campsite " <<site_number <<" successful." <<endl;
    else
        cout<<"Camper addition to Campsite " <<site_number <<" failed." <<endl;
}

void Campground::removeCamper(const int& site_number, const string& name) {
    int matchingSite = findCampsite(site_number);
    if (matchingSite == -1)
        cout <<"Campsite " <<site_number <<" not found. Camper removal failed." <<endl;
    if (campsites[matchingSite].removeCamper(name))
        cout <<"Camper " <<name <<" removal from Campsite " <<site_number <<" successful." <<endl;
    else
        cout <<"Camper " <<name <<" not found at Campsite " <<site_number <<". Camper removal failed." <<endl;
}

void Campground::printCampsites() {
    for (int i = 0; i < num_campsites; ++i) {
        campsites[i].print();
    }
}

void Campground::printCampers(const int& site_number) {
    int matchingSite = findCampsite(site_number);
    campsites[matchingSite].printCampers();
}

void Campground::printCampers(Date& date) {
    for (int i = 0; i < num_campsites; ++i) {
        campsites[i].printCamper(date);
    }
}

void Campground::printCampsitesByCategory(const cat::Category& category) {
    string cat_str = cat::categoryToString(category);
    for (int i = 0; i < num_campsites; ++i) {
        if (cat_str.compare(cat::categoryToString(campsites[i].getCategory())) == 0)
            campsites[i].print();
    }
}



