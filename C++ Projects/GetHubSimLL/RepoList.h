
#ifndef REPOLIST_H
#define REPOLIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Repo.h"
#include "defs.h"

using namespace std;

// TODO make this a linked list

class RepoList {
	class Node {
		public:
			Repo* repo;
			Node* next;
			Node* prev;
	};
		
	public:
		//constructor
		RepoList();
		//copy constructor
		RepoList(const RepoList&);
		
		//destructor
		~RepoList();
		
		//other
		bool add(Repo*);
		Repo* get(const string& title) const;
		Repo* get(int) const;
		Repo* remove(const string& title);
		Repo* remove(int);
		int size() const;
		bool isFull() const;
			
	private:
		int numRepos;
		Node* head;
		Node* tail;
};
#endif
