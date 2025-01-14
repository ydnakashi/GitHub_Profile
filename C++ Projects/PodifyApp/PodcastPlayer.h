#ifndef PODCASTPLAYER_H
#define PODCASTPLAYER_H

#include <iostream>
#include <string>
#include "Episode.h"
#include <fstream>

using namespace std;

class PodcastPlayer {	
	public:
		//constructors
		PodcastPlayer();
		// PodcastPlayer(const PodcastPlayer&);

		//destructor
		~PodcastPlayer();

		virtual void play(const Episode& m, ostream& ost) const = 0;
};

class AudioPlayer: public PodcastPlayer {
	public:
		//constructors
		AudioPlayer();
		// AudioPlayer(const AudioPlayer&);

		//destructor
		~AudioPlayer();

		virtual void play(const Episode& m, ostream& ost) const;
};

class VideoPlayer: public PodcastPlayer {
	public:
		//constructors
		VideoPlayer();
		// VideoPlayer(const VideoPlayer&);

		//destructor
		~VideoPlayer();

		virtual void play(const Episode& m, ostream& ost) const;
};
#endif