Name & Student ID:
    Yuki Nakashima
    101189690

Purpose of Program:
    

Files Included:
    Controller.cc
        Controls interaction of RideShare with the View
    Controller.h
        Header file for Controller.cc
    Customer.cc
        A User who can hail a ride, also a Drawable object
    Customer.h
        Header file for Customer.cc
    defs.h
        Header file with array limits, city dimensions, and Size enum
    Drawable.cc
        Abstract class allowing View objects to visit derived classes of this class
    Drawable.h
        Header file for Drawable.h
    Driver.cc
        A User who can give a ride, also a Drawable object
    Driver.h
        Header file for Driver.cc
    List.h
        Template class for storing pointers
    Location.cc
        Contains map coordinates as well as street names
    Location.h
        Header file for Location.cc
    main.cc
        Launches Controller object
    Makefile
        Facilitates compiling
    ReadMe.txt
        Program documentation
    RideShare.cc
        Manages Drivers and Customers, coordinates rideshares, and manages collection of Drawables for View
    RideShare.h
        Header file for RideShare
    User.cc
        Contains RideShare user information
    User.h
        Header file for User
    View.cc
        Provides menu, takes input, gives output, and draws maps based on RideShare
    View.h
        Header file for View

Libraries Used:
    iostream
    string
    iomanip
    vector

Compilation Instructions:
    To get final executable a2 and a2test, enter in terminal
        make

    To execute executable, enter in terminal
        ./a4
    
    To make and execute debugger, enter in terminal
        make a4db
        gdb a4db
    
    To delete all object files of classes, enter in terminal
        make clean
    
Notes:
    Added function getId() in View class, to facilitate findRide() function in RideShare.
    
