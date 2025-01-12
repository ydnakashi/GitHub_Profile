#include "FileList.h"

FileList::FileList() {
    numFiles = 0;
    list = new File*[MAX_FILES];
}

FileList::~FileList() {
	for(int i = 0; i < numFiles; ++i){
        delete list[i];
		list[i] = nullptr;
    }
	delete [] list;
}

bool FileList::add(File* f){
	if (numFiles >= MAX_FILES) return false;
	Date right;
	for (int i = numFiles; i > 0; --i){
		right = list[i-1]->getDate();
		if (f->lessThan(right)) {
			list[i] = list[i-1];
		} else {
			list[i] = f;
			++numFiles;
			return true;
		}
	}
	list[0] = f;
	++numFiles;
	return true;
}

File* FileList::remove(int index){
	if (index < 0 || index >= numFiles) return nullptr;
	File* goner = list[index];
	for (int i = index; i < numFiles-1; ++i){
		list[i] = list[i+1];
	}
	--numFiles;
	return goner;
}

File* FileList::remove(const string& name){
	int index = getIndex(name);
	return remove(index);
}

File* FileList::get(int index) {
	if (index < 0 || index >= numFiles) return nullptr;
	return list[index];
}

File* FileList::get(const string& name) {
    for (int i = 0; i < numFiles; ++i) {
        if (list[i]->getName().compare(name) == 0)
            return list[i];
    }
	return nullptr;
}

int FileList::size(){
	return numFiles;
}

int FileList::getIndex(const string& name) {
    for (int i = 0; i < numFiles; ++i) {
        if (list[i]->getName().compare(name) == 0)
            return i;
    }
	return -1;
}
