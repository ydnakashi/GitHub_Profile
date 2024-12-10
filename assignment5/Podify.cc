
#include "Podify.h"

Podify::Podify(): podcastList(){}

Podify::~Podify() {
    podcastList.clear();
}

void Podify::addPodcast(Podcast* pod) {
    podcastList += pod;
}

void Podify::addEpisode(Episode* e, const string& podcastTitle) {
    getPodcast(podcastTitle)->add(e);
}

const Array<Podcast*>& Podify::getPodcasts() const {
    return podcastList;
}

Podcast* Podify::getPodcast(int index) const {
    return podcastList[index];
}

Podcast* Podify::getPodcast(const string& title) const {
    for (int i = 0; i < podcastList.getSize(); ++i) {
        if (podcastList[i]->equals(title)) {
            return podcastList[i];
        }
    }
    cerr<<"Podcast not found"<<endl;
    exit(1);
}

void Podify::getEpisodes(const Search& search, Array<Episode*>& episodes) const {
    for (int pod = 0; pod < podcastList.getSize(); ++pod) {
        for (int ep = 0; ep < podcastList[pod]->getSize(); ++ep) {
            Episode* episode = podcastList[pod]->get(ep);
            if (search.matches(episode))
                episodes += episode;
            episode = nullptr;
        }
    }
}

void Podify::printPodcasts() const {
    for (int i = 0; i < podcastList.getSize(); ++i) {
        podcastList[i]->print(cout);
    }
}