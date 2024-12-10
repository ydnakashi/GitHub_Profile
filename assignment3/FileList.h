
#ifndef FILELIST_H
#define FILELIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "File.h"
#include "defs.h"

using namespace std;

// TODO make this a linked list

class FileList {
	class Node {
		public:
			File* file;
			Node* next;
			Node* prev;
	};
		
	public:
		//constructor
		FileList();
		//copy constructor
		FileList(FileList&);
		
		//destructor
		~FileList();
		
		//other
		bool add(File*);
		File* get(const string& name) const;
		File* get(const int) const;
		File* remove(const string& name);
		File* remove(int);
		int size() const;
		bool isFull() const;
	
	private:
		int numFiles;
		Node* head;
		Node* tail;
};
#endif
