#include "FileList.h"

FileList::FileList() {
    numFiles = 0;
    head = NULL;
	tail = NULL;
}

FileList::FileList(FileList& fl) {
	numFiles = fl.numFiles;
	Node* newNode;
	Node* prevNode = NULL;
	for (int i = 0; i < numFiles; ++i) {
		newNode = new Node();
		newNode->file = fl.get(i);
		if (i == 0) head = newNode;
		newNode->prev = prevNode;
		newNode->next = NULL;
		if (prevNode != NULL)
			prevNode->next = newNode;
	}
	tail = newNode;
}

FileList::~FileList() {
    Node* currNode = head;
    Node* nextNode = NULL;

    while (currNode != NULL) {
        nextNode = currNode->next;
        delete currNode->file;
        delete currNode;
        currNode = nextNode;
    }
}

bool FileList::add(File* f){
	if (f == NULL || isFull()) return false;
    Node* newNode = new Node();
    newNode->file = f;
    newNode->next = NULL;
	newNode->prev = NULL;

    Node* currNode = head;
    Node* prevNode = NULL;

    while (currNode != NULL){
        if (newNode->file->lessThan(*currNode->file)){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (prevNode == NULL && currNode == NULL){ //empty list insertion
        head = newNode;
        tail = newNode;
    } else if (prevNode == NULL && currNode != NULL) { //non-empty list head insertion
        currNode->prev = newNode;
        head = newNode;
    } else { //non-mepty list tail insertion
        prevNode->next = newNode;
		newNode->prev = prevNode;
        if (currNode != NULL)   //non-empty list middle insertion
            currNode->prev = newNode;
    }	
    newNode->next = currNode;

    if (newNode->next == NULL)
        tail = newNode;
	++numFiles;
	return true;
}

File* FileList::remove(int index){
	if (index < 0 || index >= numFiles) return nullptr;
    Node* currNode = head;
    Node* prevNode = NULL;
	File* goner;

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
    goner = currNode->file;
    delete currNode;
	--numFiles;
	return goner;
}

File* FileList::remove(const string& name){
    Node* currNode = head;
    Node* prevNode = NULL;
	int i;

	for (i = 0; currNode != NULL; ++i) {
		if (currNode->file->getName() == name) break;
		prevNode = currNode;
		currNode = currNode->next;
	}
	return remove(i);
}

File* FileList::get(const int index) const {
	if (index < 0 || index >= numFiles) return nullptr;
    Node* currNode = head;

	for (int i = 0; currNode != NULL; ++i) {
		if (i == index) break;
		currNode = currNode->next;
	}

    if (currNode == NULL) return nullptr;
    return currNode->file;
}

File* FileList::get(const string& name) const {
    Node* currNode = head;

	while (currNode != NULL) {
		if (currNode->file->getName() == name) break;
		currNode = currNode->next;
	}

    if (currNode == NULL) return nullptr;
    return currNode->file;
}

int FileList::size() const {
	return numFiles;
}

bool FileList::isFull() const {
	return false;
}
