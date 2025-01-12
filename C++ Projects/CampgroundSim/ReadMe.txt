Name & Student ID:
    Yuki Nakashima
    101189690

Purpose Of Program:
    Simulates a campground management software. Abilities include adding and removing campsites and adding and removing 
    campers. Campers are defined as singular or groups of people under a name, with a corresponding vehicle for the group.
    Categories of campsites include rv site, cabin, lodge, tent, trailer, and miscellanous.

Files Included:
    Camper.h
    Camper.cc
    Campground.h
    Campground.cc
    Campsite.h
    Campsite.cc
    Category.h
    Category.cc
    Date.h
    Date.cc
    defs.h
    main.cc
    Tester.h
    Tester.cc
    Makefile
    ReadMe.txt

Libraries Used:
    iostream
    string
    iomanip

Compilation Instructions:
    To get final executable a1, enter in terminal
        make

    To run executable a1, enter in terminal
        ./a1

    To run executable a1test, enter in terminal
        ./a1test
    
    To delete all object files of classes, enter in terminal
        make clean
    
Notes:
    Introduced Functions:
        bool Date::moreThan(Date&);
            Introduced in Date class to facilitate date comparisons in Campsite class.

        void Campsite::boundsCheck();
            Introduced in Campsite class to ensure campsite members stay within range.
        
        int Campsite::findCamper(const string&);
            Introduced in Campsite class to facilitate finding the index of a camper in array for a given camper.

        int Campground::findCampsite(const int&);
            Introduced in Campground class to facilitate finding the index of a campsite in array for a given campsite number.

        void setCampsite(const int&, const cat::Category&, const string&, const int&, const double&);
            Introduced in Campsite class as a setter to facilitate campsite info setting.

        All getters in various classes
            Introduced to facilitate string comparisons and/or cout formatting.
