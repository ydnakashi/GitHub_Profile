#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include "Episode.h"

using namespace std;

class Search {
	friend ostream& operator<<(ostream&, const Search&);
	public:
		//constructors
		// Search();
		// Search(const Search&);

		//destructor
		virtual ~Search() = default;

		virtual void print(ostream& ost) const = 0;
		virtual bool matches(const Episode*) const = 0;	
	private:
};

class H_Search: virtual public Search {
	public:
		//constructors
		H_Search(const string& h);
		H_Search(const H_Search&);

		//destructor
		virtual ~H_Search();

		virtual void print(ostream& ost) const;
		virtual bool matches(const Episode*) const;	
	private:
		string host;
};

class C_Search: virtual public Search {
	public:
		//constructors
		C_Search(const string& c);
		C_Search(const C_Search&);

		//destructor
		virtual ~C_Search();

		virtual void print(ostream& ost) const;
		virtual bool matches(const Episode*) const;	
	private:
		string category;
};

class HorC_Search: public H_Search, public C_Search {
	public:
		//constructors
		HorC_Search(const string&, const string&);
		HorC_Search(const HorC_Search&);

		// destructor
		virtual ~HorC_Search();

		virtual void print(ostream& ost) const;
		virtual bool matches(const Episode*) const;	
	private:
};
#endif