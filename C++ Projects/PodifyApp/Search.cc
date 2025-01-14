
#include "Search.h"

// Search::Search() {}
// Search::Search(const Search&){}
// Search::~Search() {}

C_Search::~C_Search() {}
H_Search::~H_Search() {}
HorC_Search::~HorC_Search() {}

ostream& operator<<(ostream& ost, const Search& s){
    s.print(ost);
    return ost;
}

H_Search::H_Search(const string& h):host(h) {}

H_Search::H_Search(const H_Search& s){
    host = s.host;
}

bool H_Search::matches(const Episode* e) const {
    return (host == e->getHost());    
}

void H_Search::print(ostream& os) const {
    os<<"- Search matches episodes with Host: " <<host <<" - " <<endl;
}

C_Search::C_Search(const string& c):category(c) {}

C_Search::C_Search(const C_Search& s){
    category = s.category;
}

bool C_Search::matches(const Episode* e) const {
    return (category == e->getCategory());    
}

void C_Search::print(ostream& os) const {
    os<<"- Search matches episodes with Category: " <<category <<" - " <<endl;
}

HorC_Search::HorC_Search(const string& h, const string& c):H_Search(h), C_Search(c) {};

// HorC_Search::HorC_Search(const HorC_Search& s) {
//     host = s.host;
//     category = s.category;
// }

bool HorC_Search::matches(const Episode* e) const {
    return C_Search::matches(e) || H_Search::matches(e);
}
void HorC_Search::print(ostream& os) const {
    // ost<<"- Search matches episodes with Category: " <<category <<" or Host: " <<host <<"- " <<endl;    
    H_Search::print(os);
    os <<" OR ";
    C_Search::print(os);
}
