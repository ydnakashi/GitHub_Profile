
#include "PodcastPlayer.h"

PodcastPlayer::PodcastPlayer() {}
AudioPlayer::AudioPlayer() {}
VideoPlayer::VideoPlayer() {}

PodcastPlayer::~PodcastPlayer() {}
AudioPlayer::~AudioPlayer() {}
VideoPlayer::~VideoPlayer() {}

void AudioPlayer::play(const Episode& e, ostream& ost) const {
    ost<<e.getAudio();
}

void VideoPlayer::play(const Episode& e, ostream& ost) const {
    ost<<e.getAudio();
    ifstream podFile;
    podFile.open(e.getVideoFile());
    string temp;

    while( true ){
        if(!getline(podFile, temp)) break;
        ost<<temp;
    }
    podFile.close();
}