#include "RepoList.h"

RepoList::RepoList() {
    numRepos = 0;
    list = new Repo*[MAX_REPOS];
}

RepoList::~RepoList() {
	for(int i = 0; i < numRepos; ++i){
        delete list[i];
		list[i] = nullptr;
    }
	delete [] list;
}

bool RepoList::add(Repo* r){
	if (numRepos >= MAX_REPOS) return false;
    list[numRepos] = r;
    ++numRepos;
	return true;
}

Repo* RepoList::remove(int index){
	if (index < 0 || index >= numRepos) return nullptr;
	Repo* goner = list[index];
	for (int i = index; i < numRepos-1; ++i){
		list[i] = list[i+1];
	}
	--numRepos;
	return goner;
}

Repo* RepoList::remove(const string& title){
	int index = getIndex(title);
	return remove(index);
}

Repo* RepoList::get(int index) {
	if (index < 0 || index >= numRepos) return nullptr;
	return list[index];
}

Repo* RepoList::get(const string& title) {
    for (int i = 0; i < numRepos; ++i) {
        if (list[i]->getTitle().compare(title) == 0)
            return list[i];
    }
	return nullptr;
}

int RepoList::size(){
	return numRepos;
}

int RepoList::getIndex(const string& title) {
    for (int i = 0; i < numRepos; ++i) {
        if (list[i]->getTitle().compare(title) == 0)
            return i;
    }
	return -1;
}