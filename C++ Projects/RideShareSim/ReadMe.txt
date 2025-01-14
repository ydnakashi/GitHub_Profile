Name & Student ID:
    Yuki Nakashima
    101189690

Purpose of Program:
    Simulate a rideshare application. Main logic class responsible for utilities of ridesharing being on RideShare object. 
    Users can request for Drivers with specific car sizes to be transported within a simulated map.

Files Included:
    Controller.cc
        Controls interaction of RideShare with the View
    Controller.h
        Header file for Controller.cc
    Customer.cc
        A User who can hail a ride, also a Drawable object (Derived from User and Drawable)
        Additionally storing class variables of
        - Customer code
        - Next id for the next generated Customer
        - Layer index of Customer
    Customer.h
        Header file for Customer.cc
    defs.h
        Header file with array limits, city dimensions, and Size enum
    Drawable.cc
        Abstract class allowing containing draw(View&) function that must be overridden
        View objects visit derived classes of this class
        Contains layer data, designating the order in which to draw Drawables
    Drawable.h
        Header file for Drawable.h
    Driver.cc
        A User who can give a ride, also a Drawable object (Dervied from User and Drawable)
        Additionally stores data member of Size from defs.h
        Also contains,
        - Driver code
        - Driver layer index
        - Next id for the next generated Driver
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
        Manages Drivers and Customers of RideShare
        Coordinates rideshares from Drivers for Customers
        Maintains a collection of Drawable objects that can be drawn on a View object
    RideShare.h
        Header file for RideShare
    User.cc
        Contains RideShare user information including
        - user ID
        - user name
        - user rating (1 - 5)
        - current location of user
    User.h
        Header file for User
    View.cc
        Provides menu, takes input, gives output, and draws maps based on RideShare Users
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
    std::cout is used as the main View output object for error reporting.
    
