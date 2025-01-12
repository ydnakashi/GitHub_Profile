#ifndef REPOLIST_H
#define REPOLIST_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Repo.h"
#include "defs.h"

using namespace std;

class RepoList {
    private:
        int numRepos;
        Repo** list;

        // helper function
        int getIndex(const string&);
    public:
        // constructor
        RepoList();

        // deconstructor
        ~RepoList();

        // other functions
        bool add(Repo*);
        Repo* get(const string&);
        Repo* get(int);
        Repo* remove(const string&);
        Repo* remove(int);
        int size();
};

#endif