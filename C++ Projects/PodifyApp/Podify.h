#ifndef PODIFY_H
#define PODIFY_H

#include <iostream>
#include <string>
#include "Podcast.h"
#include "Search.h"
#include "Array.h"

using namespace std;

class Podify {
		
	public:
		// constructors
		Podify();
		// Podify(const Podify&);

		//destructor
		~Podify();

		void addPodcast(Podcast*);
		void addEpisode(Episode*, const string& podcastTitle);
		const Array<Podcast*>& getPodcasts() const;
		Podcast* getPodcast(int index) const;
		Podcast* getPodcast(const string& title) const;
		void getEpisodes(const Search& search, Array<Episode*>& episodes) const;
		void printPodcasts() const;
	
	private:
		Array<Podcast*> podcastList;
};
#endif