#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Episode {
	friend ostream& operator<<(ostream&, const Episode&);
	public:
		//constructors
		Episode(const string&, const string&, const string&, const string&, const string&, const string&);
		Episode(const Episode&);

		//destructor
		// ~Episode();

		// getters
		const string& getPodcastTitle() const {return podcastTitle;}
		const string& getHost() const {return host;}
		const string& getEpisodeTitle() const {return episodeTitle;}
		const string& getCategory() const {return category;}
		const string& getAudio() const {return audio;}
		const string& getVideoFile() const {return videoFile;}
		
		void print(ostream&) const;
	
	private:
		string podcastTitle, host, episodeTitle, category, audio, videoFile;
};
#endif