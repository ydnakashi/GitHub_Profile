#include "Client.h"

// constructor
Client::Client():currRepo(nullptr) {}

// destructor
Client::~Client() {
    delete currRepo;
}

void Client::cloneRepo(const GetHub& getHub, int index) {
    if (currRepo != nullptr) {
        delete currRepo;
        currRepo = nullptr;
    }
    if (!getHub.download(index, &currRepo)) {
        cout << "Download unsuccessful" <<endl;
        return;
    }
    cout << "Download successful" <<endl;
}

void Client::printRepo() const {
    if (currRepo == NULL) {
        cout << "Current repo is null" <<endl;
        return;        
    }
    currRepo->printFiles();
}

void Client::printFileContents(int index) const {
    if (currRepo == NULL) {
        cout << "Current repo is null" <<endl;
        return;        
    }
    currRepo->printContents(index);
}