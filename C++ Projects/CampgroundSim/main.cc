#include <iostream>
#include <string>
#include "Category.h"
#include "Date.h"
#include "Tester.h"
#include "Camper.h"
#include "Campground.h"
#include "Campsite.h"

using namespace std;
using namespace cat;

// Constants
#define MAX_DESCRIPTION_LEN 250

// Campground Actions
void addCampsite();
void removeCampsite();
void printByCategory();

// Campsite and Camper Actions
void addCamperInCampsite();
void removeCamperInCampsite();
void printCampersInCampsite();
void printCampersOnDate();

// helper function
Category getCategory(const string& cat);

// Global Initialization of Campground
// Not good practice in most contexts, but makes the most sense in this application
Campground campground;

int main(){
    int choice = -1;
    while(choice != 0 && cin.good()){
        cout<<endl;
        cout<<" 0. Exit"<<endl;
        cout<<" Campground Actions:"<<endl;
        cout<<" 1. Add Campsite"<<endl;
        cout<<" 2. Remove Campsite"<<endl;
        cout<<" 3. Print Campsites"<<endl;
        cout<<" 4. Print Campsites by Category"<<endl;
        cout<<endl<<" Campsite and Camper Actions:"<<endl;
        cout<<" 5. Add Camper in a Campsite"<<endl;
        cout<<" 6. Remove Camper in a Campsite"<<endl; 
        cout<<" 7. Print Campers in Campsite"<<endl;
        cout<<" 8. Print Campers on Date"<<endl;

        cin >> choice;
        cout<<endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (choice)
        {
            case 1: addCampsite(); break;  
            case 2: removeCampsite(); break;  
            case 3: campground.printCampsites(); break;
            case 4: printByCategory(); break;
            case 5: addCamperInCampsite(); break;
            case 6: removeCamperInCampsite(); break;
            case 7: printCampersInCampsite(); break;
            case 8: printCampersOnDate(); break;
        }
    }
    cout<<"Bye!"<<endl;
    return 0;  
}

// Campground Actions
void addCampsite() {
    int siteNum, capacity;
    string strCat;
    char description[MAX_DESCRIPTION_LEN];
    Category category;
    double rate;

    cout<<"Enter campsite number: ";
    cin >> siteNum;
    
    cout <<"Enter campsite category: ";
    cin >> strCat;
    category = stringToCategory(strCat);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout <<"Enter the description for this campsite: " <<endl;
    cin.getline(description, MAX_DESCRIPTION_LEN);

    cout <<"Enter the max capacity of people for the campsite: ";
    cin >> capacity;

    cout <<"Enter the price per day rate of the campsite: ";
    cin >> rate;

    campground.addCampsite(siteNum, category, description, capacity, rate);
}

void removeCampsite() {
    int siteNum;
    cout << "Enter the site number of the campsite you would like to remove: ";
    cin >> siteNum;

    campground.removeCampsite(siteNum);
}

void printByCategory() {
    string inCat;
    cout <<"Enter the category of campsites you would like to print: ";
    cin >> inCat;

    Category category = stringToCategory(inCat);
    campground.printCampsitesByCategory(category);
}

// Campsite and Camper Actions
void addCamperInCampsite() {
    int siteNum, numPeople, checkInDay, checkInMonth, checkInYear, checkOutDay, checkOutMonth, checkOutYear;
    string name, plateNum;
    Date checkIn, checkOut;

    cout<<"Enter campsite Number: ";
    cin >> siteNum;
    
    cout <<"Enter camper name: ";
    cin >> name;

    cout <<"Enter the camper vehicle's plate number: ";
    cin >> plateNum;

    cout <<"Enter the group size of camper: ";
    cin >> numPeople;

    cout <<"Enter the check in date in the format of MM DD YYYY (ie. Sept 10, 2024 = 9 10 2024): ";
    cin >> checkInMonth >> checkInDay >> checkInYear;
    checkIn.setDate(checkInYear, checkInMonth, checkInDay);

    cout <<"Enter the check out date in the format of MM DD YYYY (ie. Sept 10, 2024 = 9 10 2024): ";
    cin >> checkOutMonth >> checkOutDay >> checkOutYear;
    checkOut.setDate(checkOutYear, checkOutMonth, checkOutDay);

    campground.addCamper(siteNum, name, plateNum, numPeople, checkIn, checkOut);
}

void removeCamperInCampsite() {
    int siteNum;
    string name;

    cout <<"Enter site number: ";
    cin >> siteNum;

    cout <<"Enter the camper name to removed: ";
    cin >> name;

    campground.removeCamper(siteNum, name);
}

void printCampersInCampsite() {
    int siteNum;
    cout <<"Enter site number: ";
    cin >> siteNum;

    campground.printCampers(siteNum);
}

void printCampersOnDate() {
    int day, month, year;
    cout <<"Enter date to print in the format of DD MM YYYY (ie. Sept 10, 2024 = 10 9 2024): " <<endl;
    cin >> day >> month >> year;

    Date date(year, month, day);
    campground.printCampers(date);
}