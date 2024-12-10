#ifndef REPO_H
#define REPO_H

#include <iostream>
#include <string>
#include <iomanip>
#include "FileList.h"
#include "defs.h"

using namespace std;

class Repo {
    private:
        string title, owner;
        FileList* fileList;
    public:
        // constructor
        Repo(const string&, const string&);

        // destructor
        ~Repo();

        // other
        bool lessThan(Repo&);
        bool addFile(const string&, const string&, Date&);
        bool removeFile(int);
        int getNumFiles();
        void print();
        void printFiles();
        string getTitle();
        void printContents(int);
};

#endif