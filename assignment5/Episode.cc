
#include "Episode.h"

Episode::Episode(const string& podT, const string& h, const string& epiT, const string& cat, const string& aud, const string& vidF):
podcastTitle(podT), host(h), episodeTitle(epiT), category(cat), audio(aud), videoFile(vidF) {}

Episode::Episode(const Episode& e){
    podcastTitle = e.podcastTitle;
    host = e.host;
    episodeTitle = e.episodeTitle;
    category = e.category;
    audio = e.audio;
    videoFile = e.videoFile;
}

// Episode::~Episode() {}

void Episode::print(ostream& ost) const {
    ost<<"Episode: " << episodeTitle <<endl
        <<"-- Podcast: " <<podcastTitle <<endl
        <<"-- Host: " <<host <<endl
        <<"-- Category: " <<category <<endl;
}

ostream& operator<<(ostream& ost, const Episode& e){
    e.print(ost);
    return ost;
}
