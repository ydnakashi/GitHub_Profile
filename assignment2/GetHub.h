#ifndef GETHUB_H
#define GETHUB_H

#include <iostream>
#include <iomanip>
#include <string>
#include "RepoList.h"
#include "Repo.h"
#include "File.h"

using namespace std;

class GetHub {
    private:
        RepoList* repoList;

        // Helper functions
        bool addFile(Repo*, const string&, const string&, Date&);

    public:
        // constructor
        GetHub();

        // deconstructor
        ~GetHub();

        // Repo functions
        void addRepo(const string&, const string&);
        void deleteRepo(int);
        int getNumRepos();
        bool download(int, Repo**);

        // File functions
        void addFile(const string&, const string&, const string&, Date&);
        void addFile(int, const string&, const string&, Date&);
        void deleteFile(int, int);

        // other functions
        void printRepos();
        void printRepo(int);
        void printFileContents(int, int);
};

#endif