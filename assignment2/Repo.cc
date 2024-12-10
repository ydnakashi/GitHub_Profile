#include "Repo.h"

Repo::Repo(const string& inTitle, const string& inOwner) {
    title = inTitle;
    owner = inOwner;
    fileList = new FileList();
}

Repo::~Repo() {
    delete fileList;
    fileList = nullptr;
}

bool Repo::lessThan(Repo& repo) {
    return (title.compare(repo.getTitle()) <= 0);
}

bool Repo::addFile(const string& name, const string& content, Date& date) {
    File* f = new File(name, content, date);
    bool out = fileList->add(f);
    if (!out)
        delete f;
    return out;
}

bool Repo::removeFile(int index) {
    File* outFile = fileList->remove(index);
    bool out = (outFile != nullptr);
    if (out)
        delete outFile;
    return out;
}

int Repo::getNumFiles() {
    return fileList->size();
}

void Repo::print() {
    cout<<"\nRepo Title: " <<title <<"\nRepo Owner: " <<owner <<" Number of Files: " <<getNumFiles() <<endl;
}

void Repo::printFiles() {
    print();
    for (int i = 0; i < fileList->size(); ++i) {
        cout<<i <<") File: " <<fileList->get(i)->getName() <<"\nDate Added: ";
        fileList->get(i)->getDate().print();
        cout <<endl;
    }
}

string Repo::getTitle() {
    return title;
}

void Repo::printContents(int index) {
    if (index < 0 || index >= fileList->size()) 
        cout <<"Index Out of Bounds or not valid." <<endl;
    fileList->get(index)->printContents();
}