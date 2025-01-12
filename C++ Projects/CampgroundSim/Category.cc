#include "Category.h"


std::string cat::categoryToString(cat::Category c){
    switch(c){
        case rv_site: return "rv_site";
        case cabin: return "cabin";
        case lodge: return "lodge";
        case tent: return "tent";
        case trailer: return "trailer";
        case misc: return "misc";
    }
    return "unknown category";
}

cat::Category cat::stringToCategory(const string& s) {
    if (s == "rv_site") return cat::rv_site;
    if (s == "cabin") return cat::cabin;
    if (s == "lodge") return cat::lodge;
    if (s == "tent") return cat::tent;
    if (s == "trailer") return cat::trailer;
    if (s == "misc") return cat::misc;
    return cat::misc;
}