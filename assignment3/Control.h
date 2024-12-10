
#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include <vector>

#include "GetHub.h"
#include "Client.h"
#include "View.h"

using namespace std;


class Control
{
  public:
    Control();
    
    void launch();
    

  private:
	// GetHub functions
    void printRepos();
    void printRepo();
    void printFileContents();
	  void removeRepo();
	  void removeFile();
    
	// Client functions
    void downloadRepo();
    void printClientRepo();
    void printClientFileContent();

    //helper function
    void initGetHub();

    GetHub getHub;
    View view;


    static vector<string> menu;

    // Repo information
    static const string repoTitles[5];
    static const string owners[5];

    // File information
    static const string fileTitles[5][5];
    static const string content[5][5];
    static const Date dates[5][5];


	
};
#endif