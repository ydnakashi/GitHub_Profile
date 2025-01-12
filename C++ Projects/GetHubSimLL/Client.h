#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include "GetHub.h"
#include "defs.h"

using namespace std;

class Client {
    public:
        Client();
        ~Client();
        
        void cloneRepo(const GetHub&, int);
        void printRepo() const;
        void printFileContents(int index) const;

    private:
        Repo* currRepo;
};

#endif