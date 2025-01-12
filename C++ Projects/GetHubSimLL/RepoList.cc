#include "RepoList.h"

RepoList::RepoList():head(nullptr), tail(nullptr) {
    numRepos = 0;
}

RepoList::RepoList(const RepoList& rl) {
	numRepos = rl.numRepos;
	Node* newNode;
	Node* prevNode = NULL;
	for (int i = 0; i < numRepos; ++i) {
		newNode = new Node();
		newNode->repo = rl.get(i);
		if (i == 0) head = newNode;
		newNode->prev = prevNode;
		newNode->next = NULL;
		if (prevNode != NULL)
			prevNode->next = newNode;
	}
	tail = newNode;
}

RepoList::~RepoList() {
	Node* currNode = head;
    Node* nextNode = NULL;

    while (currNode != NULL) {
        nextNode = currNode->next;
        delete currNode->repo;
        delete currNode;
        currNode = nextNode;
    }
}

bool RepoList::add(Repo* r){
	if (r == NULL || isFull()) return false;
    Node* newNode = new Node();
    newNode->repo = r;
    newNode->next = NULL;
	newNode->prev = NULL;

	if (head == NULL) {
		head = newNode;
		tail = newNode;
		++numRepos;
		return true;
	}

	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
	++numRepos;
	return true;
}

Repo* RepoList::remove(int index){
	if (index < 0 || index >= numRepos) return nullptr;
    Node* currNode = head;
    Node* prevNode = NULL;
	Repo* goner;

	for (int i = 0; currNode != NULL; ++i) {
		if (i == index) break;
		prevNode = currNode;
		currNode = currNode->next;
	}

    if (currNode == NULL){
		return NULL;
    }

    if (prevNode == NULL){
        head = currNode->next;
    } else {
        prevNode->next = currNode->next;
		currNode->next->prev = prevNode;
    }
    goner = currNode->repo;
    delete currNode;
	--numRepos;
	return goner;
}

Repo* RepoList::remove(const string& title){
    Node* currNode = head;
    Node* prevNode = NULL;
	int i;

	for (i = 0; currNode != NULL; ++i) {
		if (currNode->repo->getTitle() == title) break;
		prevNode = currNode;
		currNode = currNode->next;
	}
	return remove(i);
}

Repo* RepoList::get(int index) const {
	if (index < 0 || index >= numRepos) return nullptr;
	Node* currNode = head;

	for (int i = 0; currNode != NULL; ++i) {
		if (i == index) break;
		currNode = currNode->next;
	}
    if (currNode == NULL) return nullptr;
    return currNode->repo;
}

Repo* RepoList::get(const string& title) const {
    Node* currNode = head;

	while (currNode != NULL) {
		if (currNode->repo->getTitle() == title) break;
		currNode = currNode->next;
	}

    if (currNode == NULL) return nullptr;
    return currNode->repo;
}

int RepoList::size() const {
	return numRepos;
}

bool RepoList::isFull() const {
	return false;
}