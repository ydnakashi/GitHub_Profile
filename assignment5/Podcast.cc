
#include "Podcast.h"

Podcast::Podcast(const string& t, const string& h): title(t), host(h), episodeList(){}

Podcast::Podcast(const Podcast& p){
    title = p.title;
    host = p.host;
}

Podcast::~Podcast() {
    episodeList.clear();
}

bool Podcast::equals(const string& inTitle) const {
    return title == inTitle;
}

Episode* Podcast::get(int index) const {
    return episodeList[index];
}

int Podcast::getSize() const {
    return episodeList.getSize();
}

void Podcast::print(ostream& ost) const {
    ost<<"Podcast: " << title <<endl
        <<"- Host: " <<host <<endl;    
}

void Podcast::printWithEpisodes(ostream& ost) const {
    print(ost);
    for (int i = 0; i < getSize(); ++i) {
        episodeList[i]->print(ost);
    }
}

ostream& operator<<(ostream& ost, const Podcast& p){
    p.print(ost);
    return ost;
}

Podcast& Podcast::add(Episode* e) {
    episodeList += e;
    return *this;
}