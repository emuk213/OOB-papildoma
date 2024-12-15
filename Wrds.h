#ifndef WRDS_H_INCLUDED
#define WRDS_H_INCLUDED

#include "MyLib.h"

class Wrds {
public:
	int kiekis;
	set<int> eilutes;
	Wrds() : kiekis(0), eilutes() {}
	Wrds( int k, set<int> e) : kiekis(k), eilutes(e) {}

	friend ostream& operator<<(ostream& out, const Wrds& zod);
	
};
void read(const string& fileName, map<string, Wrds>& mp);
void output(const string& fileName, const map<string, Wrds>& mp);
string removePunctuation(const string& word);
void findURL(const string& fileName);


#endif // MYCLASS_H_INCLUDED
