#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>
#include "Episode.h"
#include "Array.h"

using namespace std;

class Podcast {
	friend ostream& operator<<(ostream&, const Podcast&);
	public:
		//constructors
		Podcast(const string&, const string&);
		Podcast(const Podcast&);

		//destructor
		~Podcast();

		bool equals(const string&) const;
		Episode* get(int) const;
		int getSize() const;
		void print(ostream&) const;
		void printWithEpisodes(ostream&) const;
		Podcast& add(Episode*);
	
	private:
		Array<Episode*> episodeList;
		string title, host;
};
#endif