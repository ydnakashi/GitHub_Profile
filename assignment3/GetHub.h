#ifndef GETHUB_H
#define GETHUB_H

#include <iostream>
#include <string>
#include <iomanip>
#include "RepoList.h"
#include "defs.h"

using namespace std;

class GetHub {
		
	public:
		//constructor
		GetHub();
		
		//destructor
		~GetHub();
			

		//adders and removers
		void addRepo(const string& repo, const string& owner);
		void deleteRepo(int repo);
		int getNumRepos() const;

		void addFile(const string& repo, const string& title, const string& content, const Date& date);
		void addFile(int repo, const string& title, const string& content, const Date& date);
		void deleteFile(int repo, int file);

		//Client services (no Client class yet)
		bool download(int repo, Repo**) const;

		//other
		void printRepos() const;
		void printRepo(int repo) const;
		void printFileContents(int repo, int file) const;
	
	private:
		RepoList* repoList;
};
#endif
