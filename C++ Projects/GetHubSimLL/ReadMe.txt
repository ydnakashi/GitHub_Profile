Name & Student ID:
    Yuki Nakashima
    101189690

Purpose of Program:
    Simulates GitHub repositories system with files of strings. Uses a linked list based data structure for repo and file storage. 
    Adds client application tool, simulating cloning repositories by creating deep copies in client objects of repositories.


Files Included:
    class.py
        Python file used to generate templated C++ source files.
    Client.cc Client.h
        Contains current working copy of repo in getHub.
    Control.cc Control.h
        Manages the interaction of the other objects
    Date.cc Date.h
        Contains date information
    defs.h
        Header files containing constants to use in other source files
    File.cc File.h
        Contains information about the File (name, content, last date modified)
    FileList.cc FileList.h
        Linked List based Data structure for File pointers        
    GetHub.cc GetHub.h
        Manages a collection of Repos
        Provides services to add, delete, access, and print Repos and the Files in the Repos
        Prints (error) messages to std::cout
    List.cc List.h
        General data structure sourc files used to design FileList and RepoList
    main.cc
        Creates a3 executable.
    Makefile
        Facilitates compiling and execution of program files
    ReadMe.txt
        Contains information about program
    Repo.cc Repo.h
        Contains information about the Repo
        Manages a collection of Files
    RepoList.cc RepoList.h
        Linked List based Data structure for Repo pointers
    test.cc test.h
        Creates a3test executable.
    TestControl.cc TestControl.h
        Manages the interaction of the other objects in order to run tests
    Tester.cc Tester.h
        Provides testing functionality
    View.cc View.h
        Presents a menu, takes input from the user

Libraries Used:
    iostream
    string
    iomanip
    vector

Compilation Instructions:
    To get final executable a2 and a2test, enter in terminal
        make all

    To execute executable, enter in terminal
        ./a3
    
    To delete all object files of classes, enter in terminal
        make clean

    To compile and use class.py, enter in terminal where <class_name> should start with a lowercase letter, otherwise capitize it
        python3 class.py <class_name>
    
Notes:

