#ifndef FILELIST_H
#define FILELIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "File.h"
#include "defs.h"

using namespace std;

class FileList {
    private:
        int numFiles;
        File** list;

        // helper functions
        int getIndex(const string&);
    public:
        // constructor
        FileList();

        // destructor
        ~FileList();

        // other
        bool add(File*);
        File* get(const string&);
        File* get(int);
        File* remove(const string&);
        File* remove(int);
        int size();
};


#endif