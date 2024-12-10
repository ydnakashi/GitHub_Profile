#include "GetHub.h"

GetHub::GetHub() {
    repoList = new RepoList();
}

GetHub::~GetHub(){
    delete repoList;
    repoList = nullptr;
}

// Repo functions
void GetHub::addRepo(const string& repo, const string& owner) {
    Repo* r = new Repo(repo, owner);
    bool out = repoList->add(r);
    if (out)
        cout <<"Complete: Repo addition successful." <<endl;
    else {
        delete r;
        cout <<"Error: Repo addition failed." <<endl;
    }
    r = nullptr;
}

void GetHub::deleteRepo(int repo) {
    Repo* outRepo = repoList->remove(repo);
    if (outRepo == nullptr)
        cout <<"Complete: Repo deletion successful." <<endl;
    else
        cout <<"Error: Repo deletion failed." <<endl;
    delete outRepo;
}

int GetHub::getNumRepos() {
    return repoList->size();
}

bool GetHub::download(int index, Repo** repo) {
    if (index < 0 || index >= getNumRepos()) {
        *repo = NULL;
        return false;
    }
    *repo = repoList->get(index);
    return true;
}

// File functions
void GetHub::addFile(const string& repo, const string& title, const string& content, Date& date) {
    Repo* rep = repoList->get(repo);
    if (addFile(rep, title, content, date))
        cout <<"Complete: File addition successful." <<endl;
    else
        cout <<"Error: File addition failed." <<endl;
}

void GetHub::addFile(int repo, const string& title, const string& content, Date& date) {
    Repo* rep = repoList->get(repo);
    if (addFile(rep, title, content, date))
        cout <<"Complete: File addition successful." <<endl;
    else
        cout <<"Error: File addition failed." <<endl;
}

bool GetHub::addFile(Repo* repo,  const string& title, const string& content, Date& date) {
    if (repo == nullptr) return false;
    return repo->addFile(title, content, date);
}

void GetHub::deleteFile(int repo, int file) {
    if (repoList->get(repo)->removeFile(file))
        cout <<"Complete: File deletion successful." <<endl;
    else
        cout <<"Error: File deletion failed." <<endl;
}

// Other functions
void GetHub::printRepos() {
    cout <<"GetHub\n========" <<endl;
    for (int i = 0; i < repoList->size(); ++i) {
        cout<<i <<") ";
        repoList->get(i)->print();
        cout <<endl;
    }
}

void GetHub::printRepo(int index) {
    Repo* repo = repoList->get(index);
    if (repo == nullptr) {
        cout <<"Error: Repo not found." <<endl;
        return;
    }
    repo->printFiles();
}

void GetHub::printFileContents(int repoIndex, int fileIndex) {
    Repo* repo = repoList->get(repoIndex);
    if (repo == nullptr) {
        cout <<"Error: Repo not found." <<endl;
        return;
    }
    repo->printContents(fileIndex);
}