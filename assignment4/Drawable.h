#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <string>
#include <iostream>
#include "defs.h"
#include "View.h"

using namespace std;

class Drawable {
    public:
        Drawable(int);
        virtual ~Drawable();
        virtual void draw(View&) const = 0;
        static int compare(Drawable* d1, Drawable* d2);
        //void print() const;

    private:
        int layer;
};

#endif